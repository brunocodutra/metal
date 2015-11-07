// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

ANONYMOUS
{
/// [ex1]
template<typename _, typename = _*>
struct couple;

using pair = couple<int>; // beware of hidden elements!
/// [ex1]

static_assert(metal::is_pair_t<pair>::value, "");
}

ANONYMOUS
{
/// [nex1]
template<typename...>
struct many;

using not_a_pair = many<>; // size != 2
/// [nex1]

static_assert(!metal::is_pair_t<not_a_pair>::value, "");
}
