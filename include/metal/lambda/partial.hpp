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
    /// Partially [invokes](\ref invoke) a \lambda with some \values.
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
    /// \see lambda, invoke, bind, always
    template<typename lbd, typename... vals>
    using partial = typename detail::_partial<lbd, vals...>::type;
}

#include <metal/lambda/lambda.hpp>
#include <metal/value/same.hpp>

#include <metal/detail/sfinae.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename... vals>
        struct _partial_impl
        {
            template<template<typename...> class expr>
            using type =
#if defined(METAL_COMPAT_MODE)
                call<expr, vals...>;
#else
                expr<vals...>;
#endif
        };

        template<typename lbd, typename... leading>
        struct _partial
        {};

        template<template<typename...> class expr, typename... leading>
        struct _partial<lambda<expr>, leading...>
        {
            template<typename... trailing>
            using impl = forward<
                _partial_impl<leading..., trailing...>::template type,
                expr
            >;

            using type = lambda<impl>;
        };

        template<typename x>
        struct _partial<lambda<same>, x>
        {
            template<typename y>
            using impl = same<x, y>;

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
