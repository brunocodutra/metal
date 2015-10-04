// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct invoke
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref invoke.
    template<typename... args>
    using invoke_t = typename invoke<args...>::type;
}

#include <metal/lambda/bind.hpp>
#include <metal/lambda/compose.hpp>
#include <metal/lambda/identity.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/lift.hpp>

namespace metal
{
    template<typename val, typename... args>
    struct invoke<val, args...> :
        bind<val, args...>
    {};

    template<
        template<template<typename...> class> class lambda,
        template<typename...> class expr,
        typename... args
    >
    struct invoke<lambda<expr>, args...> :
        bind<compose_t<lambda<expr>, lambda<identity>>, args...>
    {};

    template<
        template<typename...> class expr,
        typename... params,
        typename... args
    >
    struct invoke<expr<params...>, args...> :
        invoke<
            lift_t<lambda<identity>, lambda<expr>>,
            invoke<params, args...>...
        >
    {};
}

#endif
