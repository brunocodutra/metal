// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_MAP_HPP
#define METAL_MAP_MAP_HPP

#include <metal/number/number.hpp>

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
    using is_map_t = typename metal::is_map<seq>::type;

    template<
        template<typename...> class... pairs,
        typename... keys,
        typename... vals
    >
    struct map<pairs<keys, vals>...>
    {
        using type = map;
    };

    template<typename>
    struct is_map :
            boolean<false>
    {};

    template<
        template<typename...> class map,
        template<typename...> class... pairs,
        typename... keys,
        typename... vals
    >
    struct is_map<map<pairs<keys, vals>...>> :
            boolean<true>
    {};
}

#endif
