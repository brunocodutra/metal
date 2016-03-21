// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_AT_KEY_HPP
#define METAL_MAP_AT_KEY_HPP

namespace metal
{
    namespace detail
    {
        template<typename map, typename key>
        struct at_key;
    }

    /// \ingroup map
    /// ...
    template<typename map, typename key>
    using at_key = detail::at_key<map, key>;

    /// \ingroup map
    /// Eager adaptor for \ref at_key.
    template<typename map, typename key>
    using at_key_t = typename metal::at_key<map, key>::type;
}

#include <metal/map/map.hpp>
#include <metal/map/keys.hpp>
#include <metal/map/values.hpp>
#include <metal/number/number.hpp>

#include <metal/detail/lookup.hpp>

namespace metal
{
    namespace detail
    {
        template<typename map, typename key, typename = boolean<true>>
        struct at_key_impl
        {};

        template<typename map, typename key>
        struct at_key_impl<map, key, is_map_t<map>> :
            lookup<keys_t<map>, values_t<map>, key>
        {};

        template<typename map, typename key>
        struct at_key :
            at_key_impl<map, key>
        {};
    }
}

#endif
