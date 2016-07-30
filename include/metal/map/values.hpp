// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_VALUES_HPP
#define METAL_MAP_VALUES_HPP

#include <metal/map/map.hpp>
#include <metal/list/list.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _values;
    }

    /// \ingroup map
    /// ...
    template<typename seq>
    using values = typename if_<is_map<seq>, detail::_values<seq>>::type;

    namespace detail
    {
        template<typename seq>
        struct _values
        {
            using type = seq;
        };

        template<typename... ks, typename... vs>
        struct _values<list<list<ks, vs>...>>
        {
            using type = list<vs...>;
        };
    }
}

#endif
