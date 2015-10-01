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
#include <metal/lambda/lambda.hpp>
#include <metal/optional/eval.hpp>
#include <metal/optional/just.hpp>

namespace metal
{
    namespace detail
    {
        template<template<typename...> class expr>
        struct lift
        {
            template<typename... args>
            using type = eval<bind_t<lambda<expr>, eval<args>...>>;
        };
    }

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
        bind<lambda<detail::lift<expr>::template type>, just<args>...>
    {};

    template<
        template<typename...> class expr,
        typename... params,
        typename... args
    >
    struct invoke<expr<params...>, args...> :
        bind<
            lambda<detail::lift<expr>::template type>,
            invoke<params, args...>...
        >
    {};
}

#endif
