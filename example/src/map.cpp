// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [map1]
template<typename...>
struct many;

using map = many<>; // an empty map
/// [map1]

static_assert(metal::is_map<map>::value, "");
)

HIDE(
/// [map2]
template<typename>
struct single;

template<typename, typename>
struct couple;

using map = single<couple<int, int*>>;
/// [map2]

static_assert(metal::is_map<map>::value, "");
)

HIDE(
/// [map3]
template<typename, typename>
struct couple;

using map = couple<couple<int, long>, couple<float, double>>;
/// [map3]

static_assert(metal::is_map<map>::value, "");
)

HIDE(
/// [not_a_map1]
template<typename, typename>
struct couple;

using not_a_map = couple<couple<int, int*>, couple<int, int&>>; // repeated keys
/// [not_a_map1]

static_assert(!metal::is_map<not_a_map>::value, "");
)

HIDE(
/// [not_a_map2]
template<typename...>
struct many;

using not_a_map = many<many<void>, many<int, int>>; // not a list of pairs
/// [not_a_map2]

static_assert(!metal::is_map<not_a_map>::value, "");
)
