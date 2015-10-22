// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_DEFER_HPP
#define METAL_LAMBDA_DEFER_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename lbd>
    struct defer;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref defer.
    template<typename lbd>
    using defer_t = typename defer<lbd>::type;
}

#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/core/instantiate.hpp>

namespace metal
{
    template<typename lbd>
    struct defer :
        quote<lbd>
    {};

    template<template<typename...> class expr>
    struct defer<lambda<expr>>
    {
        template<typename... args>
        using _ = instantiate<expr, args...>;

        using type = lambda<_>;
    };

    template<template<typename...> class expr, typename... params>
    struct defer<expr<params...>> :
        bind<defer_t<lambda<expr>>, params...>
    {};
}

#endif

