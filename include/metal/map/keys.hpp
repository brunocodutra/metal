// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_KEYS_HPP
#define METAL_MAP_KEYS_HPP

#include <metal/map/map.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _keys;
    }

    /// \ingroup map
    /// ...
    template<typename seq>
    using keys = typename if_<is_map<seq>, detail::_keys<seq>>::type;

    namespace detail
    {
        template<typename seq>
        struct _keys
        {
            using type = seq;
        };

        template<
            template<typename...> class seq,
            template<typename...> class... pairs,
            typename... ks,
            typename... vs
        >
        struct _keys<seq<pairs<ks, vs>...>>
        {
            using type = seq<ks...>;
        };
    }
}

#endif
