// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_nothing.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((is_nothing_t<test::a0>::value));
METAL_TEST_ASSERT((is_nothing_t<test::a1>::value));
METAL_TEST_ASSERT((is_nothing_t<test::a2>::value));
METAL_TEST_ASSERT((is_nothing_t<test::a3>::value));
METAL_TEST_ASSERT((is_nothing_t<test::a4>::value));
METAL_TEST_ASSERT((is_nothing_t<test::a5>::value));
METAL_TEST_ASSERT((is_nothing_t<test::a6>::value));
METAL_TEST_ASSERT((is_nothing_t<test::a7>::value));
METAL_TEST_ASSERT((is_nothing_t<test::a8>::value));
METAL_TEST_ASSERT((is_nothing_t<test::a9>::value));

METAL_TEST_ASSERT((!is_nothing_t<test::n0>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::n1>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::n2>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::n3>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::n4>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::n5>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::n6>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::n7>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::n9>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::n9>::value));
