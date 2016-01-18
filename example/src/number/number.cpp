// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/number.hpp>
#include <metal/optional/optional.hpp>

#include "example.hpp"

ANONYMOUS(namespace)
{
/// [is_number]
static_assert(metal::is_number_t<metal::number<short, 0>>::value, "");
static_assert(metal::is_number_t<metal::integer<-10>>::value, "");
static_assert(metal::is_number_t<metal::boolean<false>>::value, "");
static_assert(metal::is_number_t<metal::boolean<true>>::value, "");
static_assert(!metal::is_number_t<void>::value, "");
/// [is_number]
}
