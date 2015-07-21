// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_function.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!is_function_t<test::a0>::value));
METAL_TEST_ASSERT((!is_function_t<test::a1>::value));
METAL_TEST_ASSERT((!is_function_t<test::a2>::value));
METAL_TEST_ASSERT((!is_function_t<test::a3>::value));
METAL_TEST_ASSERT((!is_function_t<test::a4>::value));
METAL_TEST_ASSERT((!is_function_t<test::a5>::value));
METAL_TEST_ASSERT((!is_function_t<test::a6>::value));
METAL_TEST_ASSERT((!is_function_t<test::a7>::value));
METAL_TEST_ASSERT((!is_function_t<test::a8>::value));
METAL_TEST_ASSERT((!is_function_t<test::a9>::value));

METAL_TEST_ASSERT((!is_function_t<test::alias<>>::value));
METAL_TEST_ASSERT((!is_function_t<test::empty<>>::value));
METAL_TEST_ASSERT((!is_function_t<test::call<>>::value));
METAL_TEST_ASSERT((!is_function_t<test::evaluable<>>::value));

METAL_TEST_ASSERT((is_function_t<test::nullary<test::alias>>::value));
METAL_TEST_ASSERT((is_function_t<test::nullary<test::empty>>::value));
METAL_TEST_ASSERT((is_function_t<test::nullary<test::call>>::value));
METAL_TEST_ASSERT((is_function_t<test::nullary<test::evaluable>>::value));

METAL_TEST_ASSERT((is_function_t<test::unary<test::alias>>::value));
METAL_TEST_ASSERT((is_function_t<test::unary<test::empty>>::value));
METAL_TEST_ASSERT((is_function_t<test::unary<test::call>>::value));
METAL_TEST_ASSERT((is_function_t<test::unary<test::evaluable>>::value));

METAL_TEST_ASSERT((is_function_t<test::binary<test::alias>>::value));
METAL_TEST_ASSERT((is_function_t<test::binary<test::empty>>::value));
METAL_TEST_ASSERT((is_function_t<test::binary<test::call>>::value));
METAL_TEST_ASSERT((is_function_t<test::binary<test::evaluable>>::value));

METAL_TEST_ASSERT((is_function_t<test::n_ary<test::alias>>::value));
METAL_TEST_ASSERT((is_function_t<test::n_ary<test::empty>>::value));
METAL_TEST_ASSERT((is_function_t<test::n_ary<test::call>>::value));
METAL_TEST_ASSERT((is_function_t<test::n_ary<test::evaluable>>::value));
