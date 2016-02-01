// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/logical.hpp>
#include <metal/optional/optional.hpp>

#include "example.hpp"

ANONYMOUS(namespace)
{
/// [not_]
static_assert(std::is_same</**/metal::not_t</**/metal::integer<-10>>, metal::boolean<false>>::value, "");
static_assert(std::is_same</**/metal::not_t</**/metal::number<short, 0>>, metal::boolean<true>>::value, "");
static_assert(std::is_same</**/metal::not_t</**/metal::boolean<false>>, metal::boolean<true>>::value, "");
static_assert(std::is_same</**/metal::not_t</**/metal::boolean<true>>, metal::boolean<false>>::value, "");
/// [not_]
}

ANONYMOUS(namespace)
{
/// [and_]
using x = metal::and_t<
    metal::integer<-7>,
    metal::number<long, 5>,
    metal::boolean<false>
>;

static_assert(std::is_same<x, metal::boolean<false>>::value, "");
/// [and_]
}

ANONYMOUS(namespace)
{
/// [or_]
using x = metal::or_t<
    metal::integer<-7>,
    metal::number<long, 5>,
    metal::boolean<false>
>;

static_assert(std::is_same<x, metal::boolean<true>>::value, "");
/// [or_]
}
