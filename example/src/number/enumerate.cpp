// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/enumerate.hpp>
#include <metal/number/number.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [enumerate]
using w = metal::enumerate<metal::int_<2>, metal::int_<2>>;
using x = metal::enumerate<metal::char_<'a'>, metal::int_<3>>;
using y = metal::enumerate<metal::number<long, 2>, metal::int_<3>, metal::int_<-5>>;
using z = metal::enumerate<metal::size_t<2>, metal::int_<-3>, metal::int_<-5>>;

static_assert(std::is_same<w, metal::list<metal::int_<2>, metal::int_<3>>>::value, "");
static_assert(std::is_same<x, metal::list<metal::char_<'a'>, metal::char_<'b'>, metal::char_<'c'>>>::value, "");
static_assert(std::is_same<y, metal::list<metal::number<long, 2>, metal::number<long, -3>, metal::number<long, -8>>>::value, "");
static_assert(std::is_same<z, metal::list<metal::size_t<2>, metal::size_t<7>, metal::size_t<12>>>::value, "");
/// [enumerate]
}
