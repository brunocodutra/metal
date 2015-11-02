// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_ERASE_KEY_HPP
#define METAL_MAP_ERASE_KEY_HPP

namespace metal
{
    /// \ingroup map
    /// \brief ...
    template<typename map, typename key>
    struct erase_key;

    /// \ingroup map
    /// \brief Eager adaptor for \ref erase_key.
    template<typename map, typename key>
    using erase_key_t = typename erase_key<map, key>::type;
}

#include <metal/map/has_key.hpp>
#include <metal/map/order.hpp>
#include <metal/list/erase.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/optional.hpp>
#include <metal/optional/eval.hpp>

namespace metal
{
    template<typename map, typename key>
    struct erase_key:
        conditional<
            eval<has_key<map, key>, nothing>,
            invoke<erase<_1, order<_1, _2>>, map, key>,
            just<map>
        >
    {};
}

#endif
