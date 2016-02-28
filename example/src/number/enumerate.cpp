// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/enumerate.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [enumerate]
using x = metal::enumerate_t</**/metal::integer<2>>;
using y = metal::enumerate_t</**/metal::integer<2>, metal::integer<3>>;
using z = metal::enumerate_t</**/metal::integer<2>, metal::integer<3>, metal::integer<-5>>;

static_assert(std::is_same<x, metal::list</**/metal::integer<0>, metal::integer<1>>>::value, "");
static_assert(std::is_same<y, metal::list</**/metal::integer<2>, metal::integer<3>, metal::integer<4>>>::value, "");
static_assert(std::is_same<z, metal::list</**/metal::integer<2>, metal::integer<-3>, metal::integer<-8>>>::value, "");
/// [enumerate]
}
