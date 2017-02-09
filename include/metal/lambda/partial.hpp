// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_PARTIAL_HPP
#define METAL_LAMBDA_PARTIAL_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename lbd, typename... vals>
        struct _partial;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// ...
    template<typename lbd, typename... vals>
    using partial = typename detail::_partial<lbd, vals...>::type;
}

#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename lbd, typename... vals>
        struct _partial
        {};

        template<template<typename...> class expr, typename... leading>
        struct _partial<lambda<expr>, leading...>
        {
            template<typename... trailing>
            using impl = invoke<lambda<expr>, leading..., trailing...>;

            using type = lambda<impl>;
        };

        template<template<typename...> class expr>
        struct _partial<lambda<expr>>
        {
            using type = lambda<expr>;
        };
    }
    /// \endcond
}

#endif
