// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/and.hpp>
#include <metal/number/if.hpp>
#include <metal/number/not.hpp>
#include <metal/number/or.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [not_]
static_assert(std::is_same<metal::not_<metal::int_<-10>>, metal::false_>::value, "");
static_assert(std::is_same<metal::not_<metal::number<short, 0>>, metal::true_>::value, "");
static_assert(std::is_same<metal::not_<metal::false_>, metal::true_>::value, "");
static_assert(std::is_same<metal::not_<metal::true_>, metal::false_>::value, "");
/// [not_]
}

HIDDEN(namespace)
{
/// [and_]
using x = metal::and_<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::false_
>;

static_assert(std::is_same<x, metal::false_>::value, "");
/// [and_]
}

HIDDEN(namespace)
{
/// [or_]
using x = metal::or_<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::false_
>;

static_assert(std::is_same<x, metal::true_>::value, "");
/// [or_]
}
