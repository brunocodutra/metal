// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/nothing.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((is_nothing_t<nothing>::value));

METAL_TEST_ASSERT((is_nothing_t<test::v0>::value));
METAL_TEST_ASSERT((is_nothing_t<test::v1>::value));
METAL_TEST_ASSERT((is_nothing_t<test::v2>::value));
METAL_TEST_ASSERT((is_nothing_t<test::v3>::value));
METAL_TEST_ASSERT((is_nothing_t<test::v4>::value));
METAL_TEST_ASSERT((is_nothing_t<test::v5>::value));
METAL_TEST_ASSERT((is_nothing_t<test::v6>::value));
METAL_TEST_ASSERT((is_nothing_t<test::v7>::value));
METAL_TEST_ASSERT((is_nothing_t<test::v8>::value));
METAL_TEST_ASSERT((is_nothing_t<test::v9>::value));

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
