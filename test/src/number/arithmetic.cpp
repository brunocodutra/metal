// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/arithmetic.hpp>
#include <metal/number/number.hpp>
#include <metal/number/comparison/equal_to.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((equal_to<inc_t<test::num0>, test::num1>::value));
METAL_TEST_ASSERT((equal_to<dec_t<test::num0>, neg_t<test::num1>>::value));
METAL_TEST_ASSERT((equal_to<inc_t<dec_t<test::num1>>, test::num1>::value));
METAL_TEST_ASSERT((equal_to<inc_t<dec_t<test::num1>>, dec_t<inc_t<test::num1>>>::value));
METAL_TEST_ASSERT((equal_to<neg_t<test::num0>, test::num0>::value));
METAL_TEST_ASSERT((equal_to<inc_t<neg_t<test::num1>>, test::num0>::value));
METAL_TEST_ASSERT((equal_to<neg_t<neg_t<test::num1>>, test::num1>::value));

METAL_TEST_ASSERT((equal_to<add_t<test::num0>, mul_t<test::num0, test::num1>>::value));
METAL_TEST_ASSERT((equal_to<add_t<test::num0, test::num1>, mul_t<test::num1, test::num1>>::value));
METAL_TEST_ASSERT((equal_to<add_t<test::num0, test::num1, test::num2>, mul_t<test::num1, test::num3>>::value));
METAL_TEST_ASSERT((equal_to<add_t<test::num0, test::num1, test::num2, test::num3>, mul_t<test::num2, test::num3>>::value));
METAL_TEST_ASSERT((equal_to<add_t<test::num0, test::num1, test::num2, test::num3, test::num4>, mul_t<test::num2, test::num5>>::value));
METAL_TEST_ASSERT((equal_to<add_t<test::num0, test::num1, test::num2, test::num3, test::num4, test::num5>, mul_t<test::num3, test::num5>>::value));
METAL_TEST_ASSERT((equal_to<add_t<test::num0, test::num1, test::num2, test::num3, test::num4, test::num5, test::num6>, mul_t<test::num3, test::num7>>::value));
METAL_TEST_ASSERT((equal_to<add_t<test::num0, test::num1, test::num2, test::num3, test::num4, test::num5, test::num6, test::num7>, mul_t<test::num4, test::num7>>::value));

METAL_TEST_ASSERT((equal_to<sub_t<test::num0>, test::num0>::value));
METAL_TEST_ASSERT((equal_to<sub_t<test::num1, test::num1>, test::num0>::value));
METAL_TEST_ASSERT((equal_to<sub_t<test::num2, test::num1, test::num1>, test::num0>::value));
METAL_TEST_ASSERT((equal_to<sub_t<test::num3, test::num1, test::num1, test::num1>, test::num0>::value));
METAL_TEST_ASSERT((equal_to<sub_t<test::num4, test::num1, test::num1, test::num1, test::num1>, test::num0>::value));
METAL_TEST_ASSERT((equal_to<sub_t<test::num5, test::num1, test::num1, test::num1, test::num1, test::num1>, test::num0>::value));
METAL_TEST_ASSERT((equal_to<sub_t<test::num6, test::num1, test::num1, test::num1, test::num1, test::num1, test::num1>, test::num0>::value));
METAL_TEST_ASSERT((equal_to<sub_t<test::num7, test::num1, test::num1, test::num1, test::num1, test::num1, test::num1, test::num1>, test::num0>::value));

METAL_TEST_ASSERT((equal_to<mul_t<test::num2>, integer<2>>::value));
METAL_TEST_ASSERT((equal_to<mul_t<test::num2, test::num2>, integer<4>>::value));
METAL_TEST_ASSERT((equal_to<mul_t<test::num2, test::num2, test::num2>, integer<8>>::value));
METAL_TEST_ASSERT((equal_to<mul_t<test::num2, test::num2, test::num2, test::num2>, integer<16>>::value));
METAL_TEST_ASSERT((equal_to<mul_t<test::num2, test::num2, test::num2, test::num2, test::num2>, integer<32>>::value));
METAL_TEST_ASSERT((equal_to<mul_t<test::num2, test::num2, test::num2, test::num2, test::num2, test::num2>, integer<64>>::value));
METAL_TEST_ASSERT((equal_to<mul_t<test::num2, test::num2, test::num2, test::num2, test::num2, test::num2, test::num2>, integer<128>>::value));
METAL_TEST_ASSERT((equal_to<mul_t<test::num2, test::num2, test::num2, test::num2, test::num2, test::num2, test::num2, test::num2>, integer<256>>::value));

METAL_TEST_ASSERT((equal_to<metal::div_t<integer<1>>, test::num1>::value));
METAL_TEST_ASSERT((equal_to<metal::div_t<integer<2>, test::num2>, test::num1>::value));
METAL_TEST_ASSERT((equal_to<metal::div_t<integer<4>, test::num2, test::num2>, test::num1>::value));
METAL_TEST_ASSERT((equal_to<metal::div_t<integer<8>, test::num2, test::num2, test::num2>, test::num1>::value));
METAL_TEST_ASSERT((equal_to<metal::div_t<integer<16>, test::num2, test::num2, test::num2, test::num2>, test::num1>::value));
METAL_TEST_ASSERT((equal_to<metal::div_t<integer<32>, test::num2, test::num2, test::num2, test::num2, test::num2>, test::num1>::value));
METAL_TEST_ASSERT((equal_to<metal::div_t<integer<64>, test::num2, test::num2, test::num2, test::num2, test::num2, test::num2>, test::num1>::value));
METAL_TEST_ASSERT((equal_to<metal::div_t<integer<128>, test::num2, test::num2, test::num2, test::num2, test::num2, test::num2, test::num2>, test::num1>::value));
