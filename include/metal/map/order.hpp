// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_ORDER_HPP
#define METAL_MAP_ORDER_HPP

#include <metal/config.hpp>

#include <metal/map/keys.hpp>
#include <metal/map/at_key.hpp>
#include <metal/list/indices.hpp>
#include <metal/list/transpose.hpp>
#include <metal/pair/pair.hpp>

namespace metal
{
    /// \ingroup map
    /// ...
    template<typename seq, typename key>
    using order = metal::at_key<
        metal::transpose<metal::pair<metal::keys<seq>, metal::indices<seq>>>,
        key
    >;
}

#endif
