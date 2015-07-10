// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_function.hpp>

#include "test/atoms.hpp"
#include "test/expressions.hpp"
#include "test/functions.hpp"
#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((not_<is_function<test::a0>>));
METAL_ASSERT((not_<is_function<test::a1>>));
METAL_ASSERT((not_<is_function<test::a2>>));
METAL_ASSERT((not_<is_function<test::a3>>));
METAL_ASSERT((not_<is_function<test::a4>>));
METAL_ASSERT((not_<is_function<test::a5>>));
METAL_ASSERT((not_<is_function<test::a6>>));
METAL_ASSERT((not_<is_function<test::a7>>));
METAL_ASSERT((not_<is_function<test::a9>>));
METAL_ASSERT((not_<is_function<test::a9>>));

METAL_ASSERT((not_<is_function<test::alias<>>>));
METAL_ASSERT((not_<is_function<test::empty<>>>));
METAL_ASSERT((not_<is_function<test::call<>>>));
METAL_ASSERT((not_<is_function<test::evaluable<>>>));
METAL_ASSERT((not_<is_function<test::evaluable_union<>>>));

METAL_ASSERT((is_function<test::unary<test::alias>>));
METAL_ASSERT((is_function<test::unary<test::empty>>));
METAL_ASSERT((is_function<test::unary<test::call>>));
METAL_ASSERT((is_function<test::unary<test::evaluable>>));
METAL_ASSERT((is_function<test::unary<test::evaluable_union>>));

METAL_ASSERT((is_function<test::binary<test::alias>>));
METAL_ASSERT((is_function<test::binary<test::empty>>));
METAL_ASSERT((is_function<test::binary<test::call>>));
METAL_ASSERT((is_function<test::binary<test::evaluable>>));
METAL_ASSERT((is_function<test::binary<test::evaluable_union>>));

METAL_ASSERT((is_function<test::n_ary<test::alias>>));
METAL_ASSERT((is_function<test::n_ary<test::empty>>));
METAL_ASSERT((is_function<test::n_ary<test::call>>));
METAL_ASSERT((is_function<test::n_ary<test::evaluable>>));
METAL_ASSERT((is_function<test::n_ary<test::evaluable_union>>));
