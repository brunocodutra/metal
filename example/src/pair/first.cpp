// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/pair/first.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [first]
static_assert(std::is_same<metal::first_t</**/metal::pair<int, int*>>, int>::value, "");
static_assert(std::is_same<metal::first_t</**/metal::list<int, unsigned>>, int>::value, "");
/// [first]
}
