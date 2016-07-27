// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_MAP_HPP
#define METAL_MAP_MAP_HPP

#include <metal/list/list.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _is_map;
    }

    /// \ingroup map
    /// ...
    template<typename val>
    using is_map = typename detail::_is_map<val>::type;

    /// \ingroup map
    /// ...
    template<typename... pairs>
    using map = if_<is_map<list<pairs...>>, list<pairs...>>;
}

#include <metal/pair/pair.hpp>
#include <metal/list/empty.hpp>
#include <metal/list/distinct.hpp>
#include <metal/number/and.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _is_map :
            false_
        {};

        template<template<typename...> class seq>
        struct _is_map<seq<>> :
            empty<seq<>>
        {};

        template<
            template<typename...> class seq,
            template<typename...> class... pairs,
            typename... keys,
            typename... vals
        >
        struct _is_map<seq<pairs<keys, vals>...>> :
            and_<is_pair<pairs<keys, vals>>..., distinct<seq<keys...>>>
        {};
    }
}

#endif
