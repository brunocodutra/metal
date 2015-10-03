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

#include <metal/list/list.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/eval.hpp>
#include <metal/optional/nothing.hpp>

namespace metal
{
    namespace detail
    {
        template<typename>
        struct join_impl;

        template<
            template<typename...> class xl, typename... xs,
            template<typename...> class yl, typename... ys,
            template<typename...> class zl, typename... zs,
            typename... lists
        >
        struct join_impl<list<xl<xs...>, yl<ys...>, zl<zs...>, lists...>> :
            join_impl<list<xl<xs..., ys..., zs...>, lists...>>
        {};

        template<
            template<typename...> class xl, typename... xs,
            template<typename...> class yl, typename... ys
        >
        struct join_impl<list<xl<xs...>, yl<ys...>>>
        {
            using type = xl<xs..., ys...>;
        };

        template<template<typename...> class xl, typename... xs>
        struct join_impl<list<xl<xs...>>>
        {
            using type = xl<xs...>;
        };
    }

    template<template<typename...> class head, typename... hs, typename... tail>
    struct join<head<hs...>, tail...> :
        eval_or<
            detail::join_impl<list<bind<lambda<head>, hs...>, tail...>>,
            nothing
        >
    {};

    template<typename... hs, typename... tail>
    struct join<list<hs...>, tail...> :
        detail::join_impl<list<list<hs...>, tail...>>
    {};
}

#endif
