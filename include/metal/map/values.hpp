// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_VALUES_HPP
#define METAL_MAP_VALUES_HPP

namespace metal
{
    /// \ingroup map
    /// ...
    template<typename map>
    struct values
    {};

    /// \ingroup map
    /// Eager adaptor for \ref values.
    template<typename map>
    using values_t = typename metal::values<map>::type;
}

#include <metal/map/map.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    template<
        template<typename...> class map,
        template<typename...> class... pairs,
        typename... ks,
        typename... vs
    >
    struct values<map<pairs<ks, vs>...>> :
        conditional<is_map_t<map<pairs<ks, vs>...>>, just<map<vs...>>>
    {};

    template<template<typename...> class map>
    struct values<map<>> :
        conditional<is_map_t<map<>>, just<map<>>>
    {};
}

#endif
