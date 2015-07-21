// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_evaluable.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!is_evaluable_t<test::alias>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::empty>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::call>::value));
METAL_TEST_ASSERT((is_evaluable_t<test::e0>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::e1>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::e2>::value));
METAL_TEST_ASSERT((is_evaluable_t<test::en>::value));

METAL_TEST_ASSERT((!is_evaluable_t<test::alias, test::a0>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::empty, test::a0>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::call, test::a0>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::e0, test::a0>::value));
METAL_TEST_ASSERT((is_evaluable_t<test::e1, test::a0>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::e2, test::a0>::value));
METAL_TEST_ASSERT((is_evaluable_t<test::en, test::a0>::value));

METAL_TEST_ASSERT((!is_evaluable_t<test::alias, test::a0, test::a1>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::empty, test::a0, test::a1>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::call, test::a0, test::a1>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::e0, test::a0, test::a1>::value));
METAL_TEST_ASSERT((!is_evaluable_t<test::e1, test::a0, test::a1>::value));
METAL_TEST_ASSERT((is_evaluable_t<test::e2, test::a0, test::a1>::value));
METAL_TEST_ASSERT((is_evaluable_t<test::en, test::a0, test::a1>::value));
