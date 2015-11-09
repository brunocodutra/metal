// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_HAS_KEY_HPP
#define METAL_MAP_HAS_KEY_HPP

namespace metal
{
    /// \ingroup map
    /// ...
    template<typename map, typename key>
    struct has_key;

    /// \ingroup map
    /// Eager adaptor for \ref has_key.
    template<typename map, typename key>
    using has_key_t = typename metal::has_key<map, key>::type;
}

#include <metal/map/map.hpp>
#include <metal/map/at_key.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    template<typename map, typename key>
    struct has_key:
        conditional<is_map_t<map>, is_just<at_key<map, key>>>
    {};
}

#endif
