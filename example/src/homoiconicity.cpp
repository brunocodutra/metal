// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

HIDDEN(namespace)
{
/// [1]
using sum = metal::add</**/metal::integer<2>, metal::integer<3>, metal::integer<5>>;
/// [1]

/// [2]
static_assert(std::is_same<metal::eval<sum>, metal::integer<10>>::value, "");
/// [2]

/// [3]
static_assert(metal::is_list<sum>::value, "");
static_assert(metal::size_t<sum>::value == 3, "");
/// [3]

/// [4]
using sqsum = metal::transform_t<metal::pow<metal::_1, metal::integer<2>>, sum>;
/// [4]

/// [5]
static_assert(std::is_same<metal::eval<sqsum>, metal::integer<38>>::value, "");
/// [5]
}
