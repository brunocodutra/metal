// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_TRANSFORM_HPP
#define METAL_LIST_TRANSFORM_HPP

#include <metal/config.hpp>

#include <metal/list/size.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/if.hpp>
#include <metal/value/same.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename head, typename... tail>
        struct _transform;

        template<typename lbd, typename head, typename... tail>
        using transform = typename _transform<lbd, head, tail...>::type;
    }

    /// \ingroup list
    /// ...
    template<typename lbd, typename head, typename... tail>
    using transform = typename if_<
        same<size<head>, size<tail>...>,
        detail::_transform<if_<is_lambda<lbd>, lbd>, head, tail...>
    >::type;
}

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/number.hpp>
#include <metal/value/value.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename = true_>
        struct _transform_impl
        {};

        template<template<typename...> class expr, typename... vals>
        struct _transform_impl<lambda<expr>, list<vals...>,
            is_value<list<expr<vals>...>>
        > :
            value<list<expr<vals>...>>
        {};

        template<typename lbd, typename head, typename... tail>
        struct _transform :
            _transform<
                bind<
                    lbd,
                    partial<lambda<at>, head>,
                    partial<lambda<at>, tail>...
                >,
                indices<head>
            >
        {};

        template<
            typename lbd,
            typename x, typename y, typename z,
            typename h, typename... t
        >
        struct _transform<lbd, list<x>, list<y>, list<z>, list<h>, list<t>...> :
            _invoke<bind<lambda<list>, lbd>, x, y, z, h, t...>
        {};

        template<typename lbd, typename... x, typename... y, typename... z>
        struct _transform<lbd, list<x...>, list<y...>, list<z...>> :
            _transform_impl<partial<lambda<apply>, lbd>, list<list<x, y, z>...>>
        {};

        template<typename lbd, typename... x, typename... y>
        struct _transform<lbd, list<x...>, list<y...>> :
            _transform_impl<partial<lambda<apply>, lbd>, list<list<x, y>...>>
        {};

        template<typename lbd, typename... x>
        struct _transform<lbd, list<x...>> :
            _transform_impl<lbd, list<x...>>
        {};

        template<typename lbd>
        struct _transform<lbd, list<>>
        {
            using type = list<>;
        };
    }
}

#endif
