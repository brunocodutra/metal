// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_just.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!is_just_t<test::a0>::value));
METAL_TEST_ASSERT((!is_just_t<test::a1>::value));
METAL_TEST_ASSERT((!is_just_t<test::a2>::value));
METAL_TEST_ASSERT((!is_just_t<test::a3>::value));
METAL_TEST_ASSERT((!is_just_t<test::a4>::value));
METAL_TEST_ASSERT((!is_just_t<test::a5>::value));
METAL_TEST_ASSERT((!is_just_t<test::a6>::value));
METAL_TEST_ASSERT((!is_just_t<test::a7>::value));
METAL_TEST_ASSERT((!is_just_t<test::a8>::value));
METAL_TEST_ASSERT((!is_just_t<test::a9>::value));

METAL_TEST_ASSERT((is_just_t<test::_0>::value));
METAL_TEST_ASSERT((is_just_t<test::_1>::value));
METAL_TEST_ASSERT((is_just_t<test::_2>::value));
METAL_TEST_ASSERT((is_just_t<test::_3>::value));
METAL_TEST_ASSERT((is_just_t<test::_4>::value));
METAL_TEST_ASSERT((is_just_t<test::_5>::value));
METAL_TEST_ASSERT((is_just_t<test::_6>::value));
METAL_TEST_ASSERT((is_just_t<test::_7>::value));
METAL_TEST_ASSERT((is_just_t<test::_9>::value));
METAL_TEST_ASSERT((is_just_t<test::_9>::value));

METAL_TEST_ASSERT((!is_just_t<test::alias<>>::value));
METAL_TEST_ASSERT((!is_just_t<test::empty<>>::value));
METAL_TEST_ASSERT((!is_just_t<test::call<>>::value));
METAL_TEST_ASSERT((is_just_t<test::evaluable<>>::value));
