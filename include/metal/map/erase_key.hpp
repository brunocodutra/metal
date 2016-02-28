// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_ERASE_KEY_HPP
#define METAL_MAP_ERASE_KEY_HPP

namespace metal
{
    namespace detail
    {
        template<typename map, typename key>
        struct erase_key;
    }

    /// \ingroup map
    /// ...
    template<typename map, typename key>
    using erase_key = detail::erase_key<map, key>;

    /// \ingroup map
    /// Eager adaptor for \ref erase_key.
    template<typename map, typename key>
    using erase_key_t = typename metal::erase_key<map, key>::type;
}

#include <metal/map/has_key.hpp>
#include <metal/map/order.hpp>
#include <metal/list/erase.hpp>
#include <metal/number/number.hpp>
#include <metal/number/logical/not.hpp>

namespace metal
{
    namespace detail
    {
        template<typename map, typename key, typename = boolean<true>>
        struct erase_key_impl
        {};

        template<typename map, typename key>
        struct erase_key_impl<map, key, not_t<has_key_t<map, key>>>
        {
            using type = map;
        };

        template<typename map, typename key>
        struct erase_key_impl<map, key, has_key_t<map, key>> :
            erase<map, order_t<map, key>>
        {};

        template<typename map, typename key>
        struct erase_key :
            erase_key_impl<map, key>
        {};
    }
}

#endif
