// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_ERASE_KEY_HPP
#define METAL_MAP_ERASE_KEY_HPP

#include <metal/config.hpp>

#include <metal/map/order.hpp>
#include <metal/list/erase.hpp>

namespace metal
{
    /// \ingroup map
    /// ...
    template<typename seq, typename key>
    using erase_key = metal::erase<seq, metal::order<seq, key>>;
}

#endif
