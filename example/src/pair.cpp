// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [pair1]
using pair = metal::list<int, unsigned>;
/// [pair1]

ASSERT(metal::is_pair<pair>);
)

HIDE(
/// [is_pair]
ASSERT(metal::is_pair<metal::list<int, unsigned>>);
ASSERT(!metal::is_pair<metal::list<int>>);
/// [is_pair]
)

HIDE(
/// [first]
ASSERT(std::is_same<metal::first<metal::pair<void, void*>>, void>);
/// [first]
)

HIDE(
/// [second]
ASSERT(std::is_same<metal::second<metal::pair<void, void*>>, void*>);
/// [second]
)
