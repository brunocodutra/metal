// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_BIND_HPP
#define METAL_LAMBDA_BIND_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... vals>
        struct _bind;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd, typename... vals>
    using bind = typename detail::_bind<lbd, vals...>::type;
}

#include <metal/list/list.hpp>
#include <metal/number/number.hpp>
#include <metal/value/value.hpp>

namespace metal
{
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
            template<template<typename...> class> class head,
            template<typename...> class expr,
            template<template<typename...> class> class... tail,
            template<typename...> class... params
        >
        struct _bind<head<expr>, tail<params>...>
        {
            template<typename... vals>
            using impl = typename _bind_impl<
                bound<expr, params...>,
                list<vals...>
            >::type;

            using type = head<impl>;
        };

        template<
            template<template<typename...> class> class head,
            template<typename...> class expr
        >
        struct _bind<head<expr>>
        {
            template<typename... vals>
            using impl = typename _bind_impl<
                bound<expr>,
                list<vals...>
            >::type;

            using type = head<impl>;
        };
    }
}

#endif
