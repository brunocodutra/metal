// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_LIFT_HPP
#define METAL_LAMBDA_LIFT_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd>
        struct lifted
        {
            using type = lifted;
        };

        template<typename lbd>
        struct lift;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd>
    using lift = detail::lift<lbd>;

    /// \ingroup lambda
    /// Eager adaptor for metal::lift.
    template<typename lbd>
    using lift_t = typename metal::lift<lbd>::type;
}

#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct lift
        {
            using type = val;
        };

        template<typename lbd>
        struct lift<lifted<lbd>> :
            lifted<lifted<lbd>>
        {};

        template<template<typename...> class expr>
        struct lift<lambda<expr>> :
            lifted<lambda<expr>>
        {};

        template<template<typename...> class expr, typename... params>
        struct lift<expr<params...>>
        {
            using type = expr<lift_t<params>...>;
        };

        template<std::size_t n>
        struct lift<arg<n>>
        {
            using type = optional<arg<n>>;
        };
    }
}

#endif
