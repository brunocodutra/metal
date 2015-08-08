// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/logical.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((or_t<test::n1>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n2>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n3>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n4>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n0, test::n5>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n6>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n7>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n8>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n8, test::n9>::value));

METAL_TEST_ASSERT((!or_t<test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0>::value));

METAL_TEST_ASSERT((and_t<test::n1>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4, test::n5>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7, test::n8>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7, test::n8, test::n9>::value));

METAL_TEST_ASSERT((!and_t<test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n4, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7, test::n8, test::n0>::value));
