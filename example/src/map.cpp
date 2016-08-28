// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [map1]
using map = metal::list<>; // an empty map
/// [map1]

IS_SAME(metal::is_map<map>, metal::true_);
)

HIDE(
/// [map2]
using map = metal::list<
    metal::list<int, long>,
    metal::list<float, double>
>;
/// [map2]

IS_SAME(metal::is_map<map>, metal::true_);
)

HIDE(
/// [not_a_map1]
using not_a_map = metal::list< // repeated keys
    metal::list<int, int*>,
    metal::list<int, int&>
>;
/// [not_a_map1]

IS_SAME(metal::is_map<not_a_map>, metal::false_);
)

HIDE(
/// [not_a_map2]
using not_a_map = metal::list< // not a list of pairs
    metal::list<int>,
    metal::list<int, int&>
>;
/// [not_a_map2]

IS_SAME(metal::is_map<not_a_map>, metal::false_);
)

HIDE(
/// [keys]
using map = metal::map<
    metal::pair<int, metal::number<sizeof(int)>>,
    metal::pair<char, metal::number<sizeof(char)>>,
    metal::pair<float, metal::number<sizeof(float)>>
>;

IS_SAME(metal::keys<map>, metal::list<int, char, float>);
/// [keys]
)

HIDE(
/// [values]
using map = metal::map<
    metal::pair<int, metal::number<sizeof(int)>>,
    metal::pair<char, metal::number<sizeof(char)>>,
    metal::pair<float, metal::number<sizeof(float)>>
>;

IS_SAME(
    metal::values<map>,
    metal::list<
        metal::number<sizeof(int)>,
        metal::number<sizeof(char)>,
        metal::number<sizeof(float)>
    >
);
/// [values]
)
