// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [list1]
template<typename...>
class many;

using list = many<>; // an empty list
/// [list1]

static_assert(metal::is_list<list>::value, "");
)

HIDE(
/// [list2]
template<typename>
union single;

using list = single<int>;
/// [list2]

static_assert(metal::is_list<list>::value, "");
)

HIDE(
/// [list3]
template<typename val, typename = val*, typename = val**>
struct some;

using list = some<void>; // a list of size 3
/// [list3]

static_assert(metal::is_list<list>::value, "");
)

HIDE(
/// [not_a_list1]
using not_a_list = struct{}; // not a template specialization
/// [not_a_list1]

static_assert(!metal::is_list<not_a_list>::value, "");
)

HIDE(
/// [not_a_list2]
template<typename t, t...>
struct numbers;

using not_a_list = numbers<int /*, ...*/>; // non-type arguments
/// [not_a_list2]

static_assert(!metal::is_list<not_a_list>::value, "");
)
