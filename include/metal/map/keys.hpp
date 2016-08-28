// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_KEYS_HPP
#define METAL_MAP_KEYS_HPP

#include <metal/config.hpp>

#include <metal/map/map.hpp>
#include <metal/pair/first.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup map
    /// ...
    template<typename seq>
    using keys = metal::if_<
        metal::is_map<seq>,
        metal::transform<metal::lambda<metal::first>, seq>
    >;
}

#endif
