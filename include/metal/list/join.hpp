// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename...>
    struct join
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref join.
    template<typename... ls>
    using join_t = typename join<ls...>::type;

    template<template<typename...> class list, typename... xs>
    struct join<list<xs...>>
    {
        using type = list<xs...>;
    };

    template<
        template<typename...> class list,
        typename... xs, typename... ys,
        typename... tail
    >
    struct join<list<xs...>, list<ys...>, tail...> :
            join<list<xs..., ys...>, tail...>
    {};
}

#endif
