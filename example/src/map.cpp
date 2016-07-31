// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [map1]
using map = metal::list<>; // an empty map
/// [map1]

ASSERT(metal::is_map<map>);
)

HIDE(
/// [map2]
using map = metal::list<
    metal::list<int, long>,
    metal::list<float, double>
>;
/// [map2]

ASSERT(metal::is_map<map>);
)

HIDE(
/// [not_a_map1]
using not_a_map = metal::list< // repeated keys
    metal::list<int, int*>,
    metal::list<int, int&>
>;
/// [not_a_map1]

ASSERT(!metal::is_map<not_a_map>);
)

HIDE(
/// [not_a_map2]
using not_a_map = metal::list< // not a list of pairs
    metal::list<int>,
    metal::list<int, int&>
>;
/// [not_a_map2]

ASSERT(!metal::is_map<not_a_map>);
)
