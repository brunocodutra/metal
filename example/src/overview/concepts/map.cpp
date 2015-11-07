// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

ANONYMOUS
{
/// [ex1]
template<typename...>
struct many;

template<typename, typename>
union couple;

using map = many<couple<int, int*>, many<float, float*>, couple<void, void>>;
/// [ex1]

static_assert(metal::is_map_t<map>::value, "");
}

ANONYMOUS
{
/// [ex2]
template<typename...>
struct none;

using map = none<>;
/// [ex2]

static_assert(metal::is_map_t<map>::value, "");
}

ANONYMOUS
{
/// [nex1]
template<typename...>
struct many;

template<typename, typename>
union couple;

using not_a_map = many<couple<int, int*>, couple<int, int&>>; // repeated keys
/// [nex1]

static_assert(!metal::is_map_t<not_a_map>::value, "");
}

ANONYMOUS
{
/// [nex2]
template<typename...>
struct many;

template<typename>
class single;

using not_a_map = many<single<void>, many<int, int>>; // not a list of pairs
/// [nex2]

static_assert(!metal::is_map_t<not_a_map>::value, "");
}
