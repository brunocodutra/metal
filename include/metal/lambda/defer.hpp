// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_DEFER_HPP
#define METAL_LAMBDA_DEFER_HPP

namespace metal
{
    namespace detail
    {
        template<template<typename...> class expr>
        struct deferred;

        template<typename lbd>
        struct defer;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd>
    using defer = detail::defer<lbd>;

    /// \ingroup lambda
    /// Eager adaptor for metal::defer.
    template<typename lbd>
    using defer_t = typename metal::defer<lbd>::type;
}

#include <metal/lambda/bind.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

namespace metal
{
    namespace detail
    {
        template<template<typename...> class expr>
        struct deferred
        {
            using type = deferred;
        };

        template<typename lbd>
        struct defer :
            quote<lbd>
        {};

        template<typename lbd>
        struct defer<lifted<lbd>> :
            lifted<defer_t<lbd>>
        {};

        template<template<typename...> class expr>
        struct defer<lambda<expr>> :
            deferred<expr>
        {};

        template<template<typename...> class expr>
        struct defer<deferred<expr>>
        {
            template<typename... args>
            using _ = invoke<deferred<expr>, args...>;

            using type = deferred<_>;
        };

        template<template<typename...> class expr, typename... params>
        struct defer<expr<params...>> :
            bind<deferred<expr>, params...>
        {};
    }
}

#endif

