// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_MAP_ORDER_HPP
#define METAL_MAP_ORDER_HPP

namespace metal
{
    /// \ingroup map
    /// ...
    template<typename map, typename key>
    struct order;

    /// \ingroup map
    /// Eager adaptor for \ref order.
    template<typename map, typename key>
    using order_t = typename metal::order<map, key>::type;
}

#include <metal/map/keys.hpp>
#include <metal/map/at_key.hpp>
#include <metal/list/indices.hpp>
#include <metal/list/transpose.hpp>
#include <metal/pair/pair.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/arg.hpp>

namespace metal
{
    template<typename map, typename key>
    struct order :
        invoke<at_key<transpose<pair<keys<_1>, indices<_1>>>, _2>, map, key>
    {};
}

#endif
