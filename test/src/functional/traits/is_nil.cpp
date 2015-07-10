// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_nil.hpp>

#include "test/atoms.hpp"
#include "test/expressions.hpp"
#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((is_nil<test::a>));
METAL_ASSERT((is_nil<test::b>));
METAL_ASSERT((is_nil<test::c>));
METAL_ASSERT((is_nil<test::d>));
METAL_ASSERT((is_nil<test::e>));
METAL_ASSERT((is_nil<test::f>));
METAL_ASSERT((is_nil<test::g>));
METAL_ASSERT((is_nil<test::h>));
METAL_ASSERT((is_nil<test::i>));
METAL_ASSERT((is_nil<test::j>));

METAL_ASSERT((is_nil<test::alias<>>));
METAL_ASSERT((is_nil<test::empty<>>));
METAL_ASSERT((is_nil<test::call<>>));
METAL_ASSERT((not_<is_nil<test::evaluable<>>>));
METAL_ASSERT((not_<is_nil<test::evaluable_union<>>>));
