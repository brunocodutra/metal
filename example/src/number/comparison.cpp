// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/comparison.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [equal_to]
static_assert(std::is_same</**/metal::equal_to_t</**/metal::integer<-10>, metal::number<long, 10>>, metal::boolean<false>>::value, "");
static_assert(std::is_same</**/metal::equal_to_t</**/metal::number<short, 0>, metal::boolean<false>>, metal::boolean<true>>::value, "");
/// [equal_to]
}

HIDDEN(namespace)
{
/// [greater]
static_assert(std::is_same</**/metal::greater_t</**/metal::integer<-10>, metal::number<long, 10>>, metal::boolean<false>>::value, "");
static_assert(std::is_same</**/metal::greater_t</**/metal::number<short, 0>, metal::boolean<false>>, metal::boolean<false>>::value, "");
/// [greater]
}

HIDDEN(namespace)
{
/// [less]
static_assert(std::is_same</**/metal::less_t</**/metal::integer<-10>, metal::number<long, 10>>, metal::boolean<true>>::value, "");
static_assert(std::is_same</**/metal::less_t</**/metal::number<short, 0>, metal::boolean<false>>, metal::boolean<false>>::value, "");
/// [less]
}
