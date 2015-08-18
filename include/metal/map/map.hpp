// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_MAP_HPP
#define METAL_MAP_MAP_HPP

#include <metal/list/count.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>
#include <metal/number/comparison/equal_to.hpp>
#include <metal/number/logical/and.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/extract.hpp>

namespace metal
{
    /// \ingroup map
    /// \brief ...
    template<typename... seqs>
    struct map;

    /// \ingroup sequece
    /// \brief ...
    template<typename seq>
    struct is_map;

    /// \ingroup map
    /// \brief Eager adaptor for \ref is_map.
    template<typename seq>
    using is_map_t = extract<metal::is_map<seq>>;

    template<typename... seqs>
    struct map :
            conditional<is_map_t<map<seqs...>>, just<map<seqs...>>>
    {};

    template<typename>
    struct is_map :
            boolean<false>
    {};

    template<template<typename...> class map>
    struct is_map<map<>> :
            boolean<true>
    {};

    template<
        template<typename...> class map,
        template<typename...> class... pairs,
        typename... keys,
        typename... vals
    >
    struct is_map<map<pairs<keys, vals>...>> :
            and_<equal_to_t<count_t<list<keys...>, keys>, integer<1>>...>
    {};
}

#endif
