// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

HIDDEN(namespace)
{
/// [ex1]
using lbd = metal::_2;
/// [ex1]

static_assert(std::is_same<metal::invoke<lbd, void, int>, int>::value, "");
}

HIDDEN(namespace)
{
/// [ex2]
using lbd = metal::lambda<std::add_pointer_t>;
/// [ex2]

static_assert(std::is_same<metal::invoke<lbd, void>, void*>::value, "");
}
