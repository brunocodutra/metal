// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_AT_KEY_HPP
#define METAL_MAP_AT_KEY_HPP

#include <metal/map/keys.hpp>
#include <metal/map/values.hpp>

#include <metal/detail/lookup.hpp>

namespace metal
{
    /// \ingroup map
    /// ...
    template<typename seq, typename key>
    using at_key = detail::lookup<values<seq>, keys<seq>, key>;
}

#endif
