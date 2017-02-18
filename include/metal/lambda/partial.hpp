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
    /// Partially invokes a \lambda with some \values.
    ///
    /// ### Usage
    /// For any \lambda `lbd` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::partial<lbd, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \lambda
    /// \semantics:
    ///     If `lbd` holds \expression `f`, then
    ///     \code
    ///         using result = metal::lambda<g>;
    ///     \endcode
    ///     where `g` is an \expression such that
    ///     \code
    ///         template<typename... args>
    ///         using g = f<val_0, ..., val_n-1, args...>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp partial
    ///
    /// ### See Also
    /// \see lambda, invoke, bind, quote
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
