// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/core/inherit.hpp>

#include "test.hpp"

using namespace metal;

using odds = inherit<test::n1, test::n3, test::n5, test::n7, test::n9>;

METAL_TEST_ASSERT((!std::is_base_of<test::n0, odds>::value));
METAL_TEST_ASSERT((std::is_base_of<test::n1, odds>::value));
METAL_TEST_ASSERT((!std::is_base_of<test::n2, odds>::value));
METAL_TEST_ASSERT((std::is_base_of<test::n3, odds>::value));
METAL_TEST_ASSERT((!std::is_base_of<test::n4, odds>::value));
METAL_TEST_ASSERT((std::is_base_of<test::n5, odds>::value));
METAL_TEST_ASSERT((!std::is_base_of<test::n6, odds>::value));
METAL_TEST_ASSERT((std::is_base_of<test::n7, odds>::value));
METAL_TEST_ASSERT((!std::is_base_of<test::n8, odds>::value));
METAL_TEST_ASSERT((std::is_base_of<test::n9, odds>::value));
