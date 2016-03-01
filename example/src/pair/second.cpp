// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/pair/second.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [second]
static_assert(std::is_same<metal::second_t</**/metal::pair<int, int*>>, int*>::value, "");
static_assert(std::is_same<metal::second_t</**/metal::list<int, unsigned>>, unsigned>::value, "");
/// [second]
}
