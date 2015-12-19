// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

ANONYMOUS(namespace)
{
/// [ex1]
template<typename...>
struct many;

template<typename, typename>
union couple;

using map = many<couple<int, int*>, many<void, void*>, couple<float, float*>>;
/// [ex1]

static_assert(metal::is_map_t<map>::value, "");
}

ANONYMOUS(namespace)
{
/// [ex2]
template<typename...>
struct many;

using map = many<>;
/// [ex2]

static_assert(metal::is_map_t<map>::value, "");
}

ANONYMOUS(namespace)
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

ANONYMOUS(namespace)
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
