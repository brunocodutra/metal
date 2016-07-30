// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [pair1]
using pair = metal::list<int, unsigned>;
/// [pair1]

static_assert(metal::is_pair<pair>::value, "");
)

HIDE(
/// [is_pair]
static_assert(metal::equal<metal::is_pair<metal::list<int, unsigned>>, metal::true_>::value, "");
static_assert(metal::equal<metal::is_pair<metal::list<int>>, metal::false_>::value, "");
/// [is_pair]
)

HIDE(
/// [first]
static_assert(metal::equal<metal::first<metal::pair<void, void*>>, void>::value, "");
/// [first]
)

HIDE(
/// [second]
static_assert(metal::equal<metal::second<metal::pair<void, void*>>, void*>::value, "");
/// [second]
)
