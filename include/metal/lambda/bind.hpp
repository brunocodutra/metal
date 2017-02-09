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
    /// ...
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
