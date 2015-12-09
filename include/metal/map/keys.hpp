// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_KEYS_HPP
#define METAL_MAP_KEYS_HPP

namespace metal
{
    namespace detail
    {
        template<typename map>
        struct keys;
    }

    /// \ingroup map
    /// ...
    template<typename map>
    using keys = detail::keys<map>;

    /// \ingroup map
    /// Eager adaptor for \ref keys.
    template<typename map>
    using keys_t = typename metal::keys<map>::type;
}

#include <metal/map/map.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename map>
        struct keys_impl
        {
            using type = map;
        };

        template<
            template<typename...> class map,
            template<typename...> class... pairs,
            typename... ks,
            typename... vs
        >
        struct keys_impl<map<pairs<ks, vs>...>>
        {
            using type = map<ks...>;
        };

        template<typename map>
        struct keys :
            conditional<is_map_t<map>, keys_impl<map>>
        {};
    }
}

#endif
