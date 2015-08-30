// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_AT_KEY_HPP
#define METAL_MAP_AT_KEY_HPP

#include <metal/map/map.hpp>
#include <metal/list/list.hpp>
#include <metal/core/inherit.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>

namespace metal
{
    /// \ingroup map
    /// \brief ...
    template<typename map, typename val>
    struct at_key;

    /// \ingroup map
    /// \brief Eager adaptor for \ref at_key.
    template<typename map, typename val>
    using at_key_t = typename at_key<map, val>::type;

    namespace detail
    {
        template<typename key, typename val>
        just<val> lookup(list<key, val>*);
        template<typename>
        nothing lookup(...);

        template<typename, typename>
        struct at_key_impl;

        template<
            template<typename...> class map,
            template<typename...> class... pairs,
            typename... keys,
            typename... vals,
            typename key
        >
        struct at_key_impl<map<pairs<keys, vals>...>, key> :
                decltype(lookup<key>(static_cast<inherit<list<keys, vals>...>*>(0)))
        {};
    }

    template<typename map, typename val>
    struct at_key :
            conditional<is_map_t<map>, detail::at_key_impl<map, val>>
    {};
}

#endif
