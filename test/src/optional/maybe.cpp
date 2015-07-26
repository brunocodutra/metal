// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/maybe.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((is_nothing_t<maybe<test::v0>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::v1>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::v2>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::v3>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::v4>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::v5>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::v6>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::v7>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::v8>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::v9>>::value));

METAL_TEST_ASSERT((is_just_t<maybe<test::n0>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::n1>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::n2>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::n3>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::n4>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::n5>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::n6>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::n7>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::n9>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::n9>>::value));

METAL_TEST_ASSERT((std::is_same<maybe<test::n0>::type, test::n0>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::n1>::type, test::n1>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::n2>::type, test::n2>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::n3>::type, test::n3>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::n4>::type, test::n4>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::n5>::type, test::n5>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::n6>::type, test::n6>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::n7>::type, test::n7>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::n8>::type, test::n8>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::n9>::type, test::n9>::value));
