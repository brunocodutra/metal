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
#include <metal/pair/pair.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/optional.hpp>

#include <metal/detail/declptr.hpp>

namespace metal
{
    namespace detail
    {
        template<typename key, typename val>
        just<val> lookup(pair<key, val>*);

        template<typename>
        nothing lookup(...);

        template<typename, typename>
        struct hash;

        template<
            template<typename...> class expr,
            typename... keys, typename... vals
        >
        struct hash<expr<keys...>, expr<vals...>> :
            pair<keys, vals>...
        {};

        template<typename map, typename key, typename = boolean<true>>
        struct at_key_impl
        {};

        template<typename map, typename key>
        struct at_key_impl<map, key, is_map_t<map>> :
            decltype(lookup<key>(declptr<hash<keys_t<map>, values_t<map>>>()))
        {};

        template<typename map, typename key>
        struct at_key :
            at_key_impl<map, key>
        {};
    }
}

#endif
