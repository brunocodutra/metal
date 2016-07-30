// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [list1]
using list = metal::list<>; // an empty list
/// [list1]

static_assert(metal::is_list<list>::value, "");
)

HIDE(
/// [list2]
using list = metal::list<int, int*, int&>;
/// [list2]

static_assert(metal::is_list<list>::value, "");
)
