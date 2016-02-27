// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

HIDDEN(namespace)
{
/// [ex1]
template<typename, typename>
struct couple;

using pair = couple<int, unsigned>;
/// [ex1]

static_assert(metal::is_pair_t<pair>::value, "");
}

HIDDEN(namespace)
{
/// [nex1]
template<typename...>
struct many;

using not_a_pair = many<>; // size != 2
/// [nex1]

static_assert(!metal::is_pair_t<not_a_pair>::value, "");
}
