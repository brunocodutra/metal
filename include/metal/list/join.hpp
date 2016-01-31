// Copyright Bruno Dutra 2015
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
    /// Eager adaptor for \ref join.
    template<typename... lists>
    using join_t = typename metal::join<lists...>::type;
}

#include <metal/list/reduce.hpp>
#include <metal/list/copy.hpp>
#include <metal/lambda/lambda.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... lists>
        struct join
        {};

        template<
            template<typename...> class list,
            typename... xs, typename... ys, typename... zs,
            typename... lists
        >
        struct join<list<xs...>, list<ys...>, list<zs...>, lists...> :
            reduce<
                join<list<xs...>, list<ys...>, list<zs...>, lists...>,
                lambda<join>
            >
        {};

        template<
            template<typename...> class list,
            typename... xs, typename... ys, typename... zs
        >
        struct join<list<xs...>, list<ys...>, list<zs...>> :
            copy<list<xs...>, metal::list<xs..., ys..., zs...>>
        {};

        template<template<typename...> class list, typename... xs, typename... ys>
        struct join<list<xs...>, list<ys...>> :
            copy<list<xs...>, metal::list<xs..., ys...>>
        {};

        template<template<typename...> class list, typename... xs>
        struct join<list<xs...>>
        {
            using type = list<xs...>;
        };

        template<typename x, typename y, typename z, typename... tail>
        struct join<list<x>, list<y>, list<z>, list<tail>...> :
            list<x, y, z, tail...>
        {};

        template<typename x, typename y, typename z>
        struct join<list<x>, list<y>, list<z>> :
            list<x, y, z>
        {};

        template<typename x, typename y>
        struct join<list<x>, list<y>> :
            list<x, y>
        {};

        template<typename x>
        struct join<list<x>> :
            list<x>
        {};
    }
}

#endif
