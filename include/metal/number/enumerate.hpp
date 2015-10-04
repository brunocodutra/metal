// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ENUMERATE_HPP
#define METAL_NUMBER_ENUMERATE_HPP

namespace metal
{
    /// \ingroup number
    /// \brief ...
    template<typename...>
    struct enumerate;

    /// \ingroup number
    /// \brief Eager adaptor for \ref enumerate.
    template<typename... args>
    using enumerate_t = typename metal::enumerate<args...>::type;
}

#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/list/join.hpp>
#include <metal/optional/eval.hpp>

namespace metal
{
    namespace detail
    {
        template<typename t, t... vs>
        struct numbers :
            list<number<t, vs>...>
        {};

        template<typename, typename>
        struct offset;

        template<template<typename...> class list, typename t, t... vs, t o>
        struct offset<list<number<t, vs>...>, number<t, o>> :
            numbers<t, (o + vs)...>
        {};
    }

    template<typename f, f fv, typename l, l lv>
    struct enumerate<number<f, fv>, number<l, lv>> :
        enumerate<
            number<decltype(true ? fv : lv), fv>,
            number<decltype(true ? fv : lv), lv>
        >
    {};

    template<typename t, t f, t l>
    struct enumerate<number<t, f>, number<t, l>> :
        join<
            enumerate_t<number<t, f>, number<t, (l + f)/2>>,
            eval<
                detail::offset<
                    enumerate_t<number<t, f>, number<t, l + f - (l + f)/2>>,
                    number<t, (l + f)/2 - f>
                >
            >
        >
    {};

    template<typename t, t f>
    struct enumerate<number<t, f>, number<t, f + 1>> :
        list<number<t, f>>
    {};

    template<typename t, t f>
    struct enumerate<number<t, f>, number<t, f - 1>> :
        list<number<t, f>>
    {};

    template<typename t, t f>
    struct enumerate<number<t, f>, number<t, f>> :
        list<>
    {};

    template<typename t, t v>
    struct enumerate<number<t, v>> :
        enumerate<number<t, 0>, number<t, v>>
    {};
}

#endif
