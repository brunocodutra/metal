// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [val1]
using val = int;
/// [val1]

IS_SAME(metal::is_value<val>, metal::true_);
)

HIDE(
/// [val2]
using val = decltype(3.14);
/// [val2]

IS_SAME(metal::is_value<val>, metal::true_);
)

HIDE(
/// [val3]
struct val
{
    //...
};
/// [val3]

IS_SAME(metal::is_value<val>, metal::true_);
)

HIDE(
/// [not_a_val1]
int not_a_val;
/// [not_a_val1]
)

HIDE(
static constexpr
/// [not_a_val2]
decltype(auto) not_a_val = 3.14;
/// [not_a_val2]
)

HIDE(
/// [not_a_val3]
template<typename...>
struct not_a_val
{
    //...
};
/// [not_a_val3]
)
