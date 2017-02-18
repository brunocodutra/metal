// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_BIND_HPP
#define METAL_LAMBDA_BIND_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename lbd, typename... vals>
        struct _bind;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// Provides higher-order composition of \lambdas.
    ///
    /// \tip{Use metal::arg<n> as a placeholder for the n-th argument.}
    ///
    /// ### Usage
    /// For any \lambdas `lbd` and `lbd_0, ..., lbd_n-1`
    /// \code
    ///     using result = metal::bind<lbd, lbd_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \lambda
    /// \semantics:
    ///     If `lbd` holds \expression `f` and, likewise, `lbd_0, ..., lbd_n-1`
    ///     hold \expressions `f_0, ..., f_n-1`, then
    ///     \code
    ///         using result = metal::lambda<g>;
    ///     \endcode
    ///     where `g` is an \expression such that
    ///     \code
    ///         template<typename... args>
    ///         using g = f<f_0<args...>, ...<args...>, f_n-1<args...>>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp bind
    ///
    /// ### See Also
    /// \see lambda, invoke, arg, quote
    template<typename lbd, typename... vals>
    using bind = typename detail::_bind<lbd, vals...>::type;
}

#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>
#include <metal/value/value.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<template<typename...> class, template<typename...> class...>
        struct bound;

        template<typename, typename, typename = true_>
        struct _bind_impl
        {};

        template<
            template<typename...> class expr,
            template<typename...> class... params,
            typename... vals
        >
        struct _bind_impl<bound<expr, params...>, list<vals...>,
            is_value<expr<params<vals...>...>>
        > :
            value<expr<params<vals...>...>>
        {};

        template<typename lbd, typename... vals>
        struct _bind
        {};

        template<
            template<typename...> class expr,
            template<typename...> class... params
        >
        struct _bind<lambda<expr>, lambda<params>...>
        {
            template<typename... vals>
            using impl = typename _bind_impl<
                bound<expr, params...>,
                list<vals...>
            >::type;

            using type = lambda<impl>;
        };

        template<template<typename...> class expr>
        struct _bind<lambda<expr>>
        {
            template<typename... vals>
            using impl = typename _bind_impl<
                bound<expr>,
                list<vals...>
            >::type;

            using type = lambda<impl>;
        };
    }
    /// \endcond
}

#endif
