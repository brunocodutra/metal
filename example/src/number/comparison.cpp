// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/comparison.hpp>
#include <metal/optional/optional.hpp>

#include "example.hpp"

ANONYMOUS(namespace)
{
/// [equal_to]
static_assert(std::is_same<metal::equal_to_t<metal::integer<-10>, metal::number<long, 10>>, metal::boolean<false>>::value, "");
static_assert(std::is_same<metal::equal_to_t<metal::number<short, 0>, metal::boolean<false>>, metal::boolean<true>>::value, "");
static_assert(!metal::is_just<metal::equal_to<metal::integer<0>, void>>::value, "");
/// [equal_to]
}

ANONYMOUS(namespace)
{
/// [greater]
static_assert(std::is_same<metal::greater_t<metal::integer<-10>, metal::number<long, 10>>, metal::boolean<false>>::value, "");
static_assert(std::is_same<metal::greater_t<metal::number<short, 0>, metal::boolean<false>>, metal::boolean<false>>::value, "");
static_assert(!metal::is_just<metal::greater<metal::integer<0>, void>>::value, "");
/// [greater]
}

ANONYMOUS(namespace)
{
/// [less]
static_assert(std::is_same<metal::less_t<metal::integer<-10>, metal::number<long, 10>>, metal::boolean<true>>::value, "");
static_assert(std::is_same<metal::less_t<metal::number<short, 0>, metal::boolean<false>>, metal::boolean<false>>::value, "");
static_assert(!metal::is_just<metal::less<metal::integer<0>, void>>::value, "");
/// [less]
}
