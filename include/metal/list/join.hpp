// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename... lists>
    struct join;

    /// \ingroup list
    /// \brief Eager adaptor for \ref join.
    template<typename... lists>
    using join_t = typename join<lists...>::type;
}

#include <metal/list/reduce.hpp>
#include <metal/lambda/defer.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/eval.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct join_impl;

        template<
            template<typename...> class xl, typename... xs,
            template<typename...> class yl, typename... ys,
            template<typename...> class zl, typename... zs,
            typename... lists
        >
        struct join_impl<xl<xs...>, yl<ys...>, zl<zs...>, lists...> :
            reduce<
                join_impl<xl<xs..., ys..., zs...>, lists...>,
                lambda<join_impl>
            >
        {};

        template<
            template<typename...> class xl, typename... xs,
            template<typename...> class yl, typename... ys
        >
        struct join_impl<xl<xs...>, yl<ys...>>
        {
            using type = defer<xs..., ys...>;
        };

        template<template<typename...> class xl, typename... xs>
        struct join_impl<xl<xs...>>
        {
            using type = defer<xs...>;
        };
    }

    template<template<typename...> class head, typename... hs, typename... tail>
    struct join<head<hs...>, tail...> :
        eval<
            detail::join_impl<defer<lambda<head>, hs...>, tail...>,
            nothing
        >
    {};
}

#endif
