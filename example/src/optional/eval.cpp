// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/eval.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [eval]
struct none
{};

struct some
{
    struct type;
};

static_assert(std::is_same</**/metal::eval<some>, some::type>::value, "");
static_assert(std::is_same</**/metal::eval<some, void>, some::type>::value, "");
static_assert(std::is_same</**/metal::eval<none, void>, void>::value, "");
/// [eval]
}
