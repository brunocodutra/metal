// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_nil.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

METAL_ASSERT((is_nil<test::a0>));
METAL_ASSERT((is_nil<test::a1>));
METAL_ASSERT((is_nil<test::a2>));
METAL_ASSERT((is_nil<test::a3>));
METAL_ASSERT((is_nil<test::a4>));
METAL_ASSERT((is_nil<test::a5>));
METAL_ASSERT((is_nil<test::a6>));
METAL_ASSERT((is_nil<test::a7>));
METAL_ASSERT((is_nil<test::a9>));
METAL_ASSERT((is_nil<test::a9>));

METAL_ASSERT((is_nil<test::alias<>>));
METAL_ASSERT((is_nil<test::empty<>>));
METAL_ASSERT((is_nil<test::call<>>));
METAL_ASSERT((not_<is_nil<test::evaluable<>>>));
METAL_ASSERT((not_<is_nil<test::evaluable_union<>>>));
