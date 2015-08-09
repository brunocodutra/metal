// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/sequence/map.hpp>
#include <metal/optional/just.hpp>
#include <metal/sequence/at_key.hpp>
#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((is_just_t<map<>>::value));
METAL_TEST_ASSERT((!is_just_t<map<test::val0>>::value));
METAL_TEST_ASSERT((!is_just_t<map<test::val0, test::val1>>::value));
METAL_TEST_ASSERT((!is_just_t<map<test::val0, test::val1, test::val2>>::value));
METAL_TEST_ASSERT((!is_just_t<map<test::val0, test::val1, test::val2, test::val3>>::value));

METAL_TEST_ASSERT((is_just_t<map<test::list2>>::value));
METAL_TEST_ASSERT((!is_just_t<map<test::list2, test::list2>>::value));
METAL_TEST_ASSERT((!is_just_t<map<test::list2, test::list2, test::list2>>::value));
METAL_TEST_ASSERT((!is_just_t<map<test::list2, test::list2, test::list2, test::list2>>::value));

METAL_TEST_ASSERT((is_map_t<map<>>::value));
METAL_TEST_ASSERT((!is_map_t<map<test::val0>>::value));
METAL_TEST_ASSERT((!is_map_t<map<test::val0, test::val1>>::value));
METAL_TEST_ASSERT((!is_map_t<map<test::val0, test::val1, test::val2>>::value));
METAL_TEST_ASSERT((!is_map_t<map<test::val0, test::val1, test::val2, test::val3>>::value));

METAL_TEST_ASSERT((is_map_t<map<test::list2>>::value));
METAL_TEST_ASSERT((!is_map_t<map<test::list2, test::list2>>::value));
METAL_TEST_ASSERT((!is_map_t<map<test::list2, test::list2, test::list2>>::value));
METAL_TEST_ASSERT((!is_map_t<map<test::list2, test::list2, test::list2, test::list2>>::value));

METAL_TEST_ASSERT((!is_map_t<map<test::val0>>::value));
METAL_TEST_ASSERT((!is_map_t<map<test::val0, test::val1>>::value));
METAL_TEST_ASSERT((!is_map_t<map<test::val0, test::val1, test::val2>>::value));
METAL_TEST_ASSERT((!is_map_t<map<test::val0, test::val1, test::val2, test::val3>>::value));

METAL_TEST_ASSERT((!is_map_t<test::val0>::value));
METAL_TEST_ASSERT((!is_map_t<test::val1>::value));
METAL_TEST_ASSERT((!is_map_t<test::val2>::value));
METAL_TEST_ASSERT((!is_map_t<test::val3>::value));
METAL_TEST_ASSERT((!is_map_t<test::val4>::value));
METAL_TEST_ASSERT((!is_map_t<test::val5>::value));
METAL_TEST_ASSERT((!is_map_t<test::val6>::value));
METAL_TEST_ASSERT((!is_map_t<test::val7>::value));
METAL_TEST_ASSERT((!is_map_t<test::val8>::value));
METAL_TEST_ASSERT((!is_map_t<test::val9>::value));

METAL_TEST_ASSERT((!is_map_t<test::num0>::value));
METAL_TEST_ASSERT((!is_map_t<test::num1>::value));
METAL_TEST_ASSERT((!is_map_t<test::num2>::value));
METAL_TEST_ASSERT((!is_map_t<test::num3>::value));
METAL_TEST_ASSERT((!is_map_t<test::num4>::value));
METAL_TEST_ASSERT((!is_map_t<test::num5>::value));
METAL_TEST_ASSERT((!is_map_t<test::num6>::value));
METAL_TEST_ASSERT((!is_map_t<test::num7>::value));
METAL_TEST_ASSERT((!is_map_t<test::num8>::value));
METAL_TEST_ASSERT((!is_map_t<test::num9>::value));

METAL_TEST_ASSERT((is_map_t<test::map0>::value));
METAL_TEST_ASSERT((is_map_t<test::map1>::value));
METAL_TEST_ASSERT((is_map_t<test::map2>::value));
METAL_TEST_ASSERT((is_map_t<test::map3>::value));
METAL_TEST_ASSERT((is_map_t<test::map4>::value));
METAL_TEST_ASSERT((is_map_t<test::map5>::value));
METAL_TEST_ASSERT((is_map_t<test::map6>::value));
METAL_TEST_ASSERT((is_map_t<test::map7>::value));
METAL_TEST_ASSERT((is_map_t<test::map8>::value));
METAL_TEST_ASSERT((is_map_t<test::map9>::value));
