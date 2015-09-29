// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ZIP_HPP
#define METAL_LIST_ZIP_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename... lists>
    struct zip
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref zip.
    template<typename... lists>
    using zip_t = typename zip<lists...>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/same.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/optional/eval.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/conditional.hpp>


namespace metal
{
    namespace detail
    {
        template<typename, typename...>
        struct tier;

        template<typename t, t v, typename... lists>
        struct tier<number<t, v>, lists...> :
            list<at_t<lists, number<t, v>>...>
        {};

        template<typename, typename...>
        struct grid;

        template<
            template<typename...> class nl, typename... ns,
            typename... lists
        >
        struct grid<nl<ns...>, lists...> :
            list<eval<tier<ns, lists...>>...>
        {};

        template<typename x, typename y, typename... tail>
        struct zip_impl :
            grid<enumerate_t<size_t<x>>, x, y, tail...>
        {};

        template<
            template<typename...> class xl, typename... xs,
            template<typename...> class yl, typename... ys
        >
        struct zip_impl<xl<xs...>, yl<ys...>> :
            list<list<xs, ys>...>
        {};
    }

    template<
        template<typename...> class xl, typename... xs,
        template<typename...> class yl, typename... ys,
        typename... tail
    >
    struct zip<xl<xs...>, yl<ys...>, tail...> :
        conditional<
            same_t<
                list<
                    size_t<xl<xs...>>,
                    size_t<yl<ys...>>,
                    conditional_t<is_list_t<tail>, size<tail>, just<void>>...
                >
            >,
            detail::zip_impl<xl<xs...>, yl<ys...>, tail...>
        >
    {};

    template<template<typename...> class xl, typename... xs>
    struct zip<xl<xs...>> :
        list<list<xs>...>
    {};
}

#endif
