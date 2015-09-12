// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP

#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/eval_or.hpp>
#include <metal/optional/nothing.hpp>

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

    namespace detail
    {
        template<typename>
        struct join_recurse
        {};

        template<
            template<typename...> class list,
            template<typename...> class xl, typename... xs,
            template<typename...> class yl, typename... ys,
            typename... lists
        >
        struct join_recurse<list<xl<xs...>, yl<ys...>, lists...>> :
                eval_or<join<bind<lambda<xl>, xs..., ys...>, lists...>, nothing>
        {};

        template<typename _>
        struct join_impl :
                join_recurse<_>
        {};

        template<
            template<typename...> class list,
            template<typename...> class head, typename... hs,
            template<typename...> class... tail, typename... ts
        >
        struct join_impl<list<head<hs...>, tail<ts>...>> :
                bind<lambda<head>, hs..., ts...>
        {};
    }

    template<typename... lists>
    struct join :
            detail::join_impl<join<lists...>>
    {};

    template<template<typename...> class head, typename... hs>
    struct join<head<hs...>>
    {
        using type = head<hs...>;
    };

    template<
        template<typename...> class head, typename... hs,
        template<typename...> class... tail
    >
    struct join<head<hs...>, tail<>...> :
            join<head<hs...>>
    {};
}

#endif
