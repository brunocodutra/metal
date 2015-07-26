// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/conditional.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((conditional_t<test::n0, std::false_type, std::true_type>::value));
METAL_TEST_ASSERT((conditional_t<test::n1, std::true_type, std::false_type>::value));

struct x {using type = x;};
struct y {using type = y;};
struct z {using type = z;};
struct w {using type = w;};

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x>, x>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x, y>, x>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, y>, y>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x, std::true_type, y>, x>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::true_type, y>, y>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x, std::true_type, y, z>, x>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::true_type, y, z>, y>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::false_type, y, z>, z>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x, std::true_type, y, std::true_type, z>, x>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::true_type, y, std::true_type, z>, y>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::false_type, y, std::true_type, z>, z>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x, std::true_type, y, std::true_type, z, w>, x>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::true_type, y, std::true_type, z, w>, y>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::false_type, y, std::true_type, z, w>, z>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::false_type, y, std::false_type, z, w>, w>::value));





