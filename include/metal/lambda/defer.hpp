// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_DEFER_HPP
#define METAL_LAMBDA_DEFER_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct defer
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref defer.
    template<typename... args>
    using defer_t = typename defer<args...>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>

namespace metal
{
    namespace detail
    {
        template<
            template<typename...> class expr,
            typename... args,
            typename ret = expr<args...>
        >
        just<ret> instantiate(defer<lambda<expr>, args...>*);
        nothing instantiate(...);
    }

    template<template<typename...> class expr, typename... args>
    struct defer<lambda<expr>, args...> :
        decltype(
            detail::instantiate(
                static_cast<defer<lambda<expr>, args...>*>(0)
            )
        )
    {};

    template<typename lbd, typename... args>
    struct defer<lbd, args...> :
        just<invoke<lbd, args...>>
    {};
}

#endif

