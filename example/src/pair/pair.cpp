// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/pair/pair.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [is_pair]
static_assert(metal::is_pair<metal::pair<int, int*>>::value, "");
static_assert(metal::is_pair<metal::list<int, unsigned>>::value, "");
static_assert(!metal::is_pair<metal::list<int>>::value, "");
/// [is_pair]
}
