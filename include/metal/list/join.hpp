// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP

namespace metal
{
    namespace detail
    {
        template<typename... lists>
        struct join;
    }

    /// \ingroup list
    /// ...
    template<typename... lists>
    using join = detail::join<lists...>;

    /// \ingroup list
    /// Eager adaptor for metal::join.
    template<typename... lists>
    using join_t = typename metal::join<lists...>::type;
}

#include <metal/list/reduce.hpp>
#include <metal/list/copy.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... lists>
        struct join
        {};

        template<
            template<typename...> class expr,
            typename... ws, typename... xs, typename... ys, typename... zs,
            typename... _
        >
        struct join<expr<ws...>, expr<xs...>, expr<ys...>, expr<zs...>, _...> :
            reduce<
                list<expr<ws...>, expr<xs...>, expr<ys...>, expr<zs...>, _...>,
                lambda<join>
            >
        {};

        template<
            template<typename...> class expr,
            typename... ws, typename... xs, typename... ys, typename... zs
        >
        struct join<expr<ws...>, expr<xs...>, expr<ys...>, expr<zs...>> :
            copy<expr<ws...>, list<ws..., xs..., ys..., zs...>>
        {};

        template<
            template<typename...> class expr,
            typename... ws, typename... xs, typename... ys
        >
        struct join<expr<ws...>, expr<xs...>, expr<ys...>> :
            copy<expr<ws...>, list<ws..., xs..., ys...>>
        {};

        template<
            template<typename...> class expr,
            typename... ws, typename... xs
        >
        struct join<expr<ws...>, expr<xs...>> :
            copy<expr<ws...>, list<ws..., xs...>>
        {};

        template<template<typename...> class expr, typename... ws>
        struct join<expr<ws...>>
        {
            using type = expr<ws...>;
        };

        template<
            typename... xs, typename... ys, typename... zs,
            typename a, typename b, typename... _
        >
        struct join<
            list<xs...>, list<ys...>, list<zs...>,
            list<a>, list<b>, list<_>...
        > :
            list<xs..., ys..., zs..., a, b, _...>
        {};
    }
}

#endif
