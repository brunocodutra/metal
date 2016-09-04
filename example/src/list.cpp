// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [list1]
using l = metal::list<>; // an empty list
/// [list1]

IS_SAME(metal::is_list<l>, metal::true_);
)

HIDE(
/// [list2]
using l = metal::list<int, int*, int&>;
/// [list2]

IS_SAME(metal::is_list<l>, metal::true_);
)
