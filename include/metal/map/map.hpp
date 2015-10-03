// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_MAP_HPP
#define METAL_MAP_MAP_HPP

namespace metal
{
    /// \ingroup map
    /// \brief ...
    template<typename... pairs>
    struct map;

    /// \ingroup map
    /// \brief ...
    template<typename map>
    struct is_map;

    /// \ingroup map
    /// \brief Eager adaptor for \ref is_map.
    template<typename map>
    using is_map_t = typename metal::is_map<map>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/distinct.hpp>
#include <metal/list/size.hpp>
#include <metal/list/empty.hpp>
#include <metal/number/number.hpp>
#include <metal/number/logical/and.hpp>
#include <metal/number/comparison/equal_to.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>

namespace metal
{
    template<typename... pairs>
    struct map :
        conditional<is_map_t<map<pairs...>>, just<map<pairs...>>>
    {};

    template<typename>
    struct is_map :
        boolean<false>
    {};

    template<template<typename...> class map>
    struct is_map<map<>> :
        empty<map<>>
    {};

    template<
        template<typename...> class map,
        template<typename...> class... pairs,
        typename... keys,
        typename... vals
    >
    struct is_map<map<pairs<keys, vals>...>> :
        and_<
            equal_to_t<size_t<pairs<keys, vals>>, integer<2>>...,
            distinct_t<list<keys...>>
        >
    {};
}

#endif
