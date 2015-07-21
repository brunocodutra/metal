// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_same_function.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!is_same_function_t<test::a1, test::a1>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::a2, test::a2>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::a3, test::a3>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::a4, test::a4>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::a5, test::a5>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::a6, test::a6>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::a7, test::a7>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::a8, test::a8>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::a9, test::a9>::value));

METAL_TEST_ASSERT((is_same_function_t<test::f0, test::f0>::value));
METAL_TEST_ASSERT((is_same_function_t<test::f1, test::f1>::value));
METAL_TEST_ASSERT((is_same_function_t<test::f2, test::f2>::value));
METAL_TEST_ASSERT((is_same_function_t<test::fn, test::fn>::value));

METAL_TEST_ASSERT((!is_same_function_t<test::f0, test::fn>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::f1, test::f0>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::f2, test::f1>::value));
METAL_TEST_ASSERT((!is_same_function_t<test::fn, test::f2>::value));
