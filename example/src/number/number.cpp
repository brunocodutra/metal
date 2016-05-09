// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/number.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [is_number]
static_assert(metal::is_number<metal::number<short, 0>>::value, "");
static_assert(metal::is_number<metal::int_<-10>>::value, "");
static_assert(metal::is_number<metal::false_>::value, "");
static_assert(metal::is_number<metal::true_>::value, "");
static_assert(!metal::is_number<void>::value, "");
/// [is_number]
}
