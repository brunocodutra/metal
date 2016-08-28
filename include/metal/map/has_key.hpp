// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_HAS_KEY_HPP
#define METAL_MAP_HAS_KEY_HPP

#include <metal/config.hpp>

#include <metal/map/keys.hpp>
#include <metal/list/contains.hpp>

namespace metal
{
    /// \ingroup map
    ///
    /// ### Description
    /// ...
    template<typename seq, typename key>
    using has_key = metal::contains<metal::keys<seq>, key>;
}

#endif
