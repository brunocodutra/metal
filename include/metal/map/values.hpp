// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_VALUES_HPP
#define METAL_MAP_VALUES_HPP

namespace metal
{
    namespace detail
    {
        template<typename map>
        struct values;
    }

    /// \ingroup map
    /// ...
    template<typename map>
    using values = detail::values<map>;

    /// \ingroup map
    /// Eager adaptor for \ref values.
    template<typename map>
    using values_t = typename metal::values<map>::type;
}

#include <metal/map/map.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename map>
        struct values_impl
        {
            using type = map;
        };

        template<
            template<typename...> class map,
            template<typename...> class... pairs,
            typename... ks,
            typename... vs
        >
        struct values_impl<map<pairs<ks, vs>...>>
        {
            using type = map<vs...>;
        };

        template<typename map>
        struct values :
            conditional<is_map_t<map>, values_impl<map>>
        {};
    }
}

#endif
