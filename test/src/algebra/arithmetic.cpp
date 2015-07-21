// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/algebra/arithmetic.hpp>
#include <metal/algebra/comparison/equal_to.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((equal_to<inc<test::_0>, test::_1>::value));
METAL_TEST_ASSERT((equal_to<dec<test::_0>, neg<test::_1>>::value));
METAL_TEST_ASSERT((equal_to<inc<dec<test::_1>>, test::_1>::value));
METAL_TEST_ASSERT((equal_to<inc<dec<test::_1>>, dec<inc<test::_1>>>::value));
METAL_TEST_ASSERT((equal_to<neg<test::_0>, test::_0>::value));
METAL_TEST_ASSERT((equal_to<inc<neg<test::_1>>, test::_0>::value));
METAL_TEST_ASSERT((equal_to<neg<neg<test::_1>>, test::_1>::value));

METAL_TEST_ASSERT((equal_to<add<test::_0, test::_1>, mul<test::_1, test::_1>>::value));
METAL_TEST_ASSERT((equal_to<add<test::_0, test::_1, test::_2>, mul<test::_1, test::_3>>::value));
METAL_TEST_ASSERT((equal_to<add<test::_0, test::_1, test::_2, test::_3>, mul<test::_2, test::_3>>::value));
METAL_TEST_ASSERT((equal_to<add<test::_0, test::_1, test::_2, test::_3, test::_4>, mul<test::_2, test::_5>>::value));
METAL_TEST_ASSERT((equal_to<add<test::_0, test::_1, test::_2, test::_3, test::_4, test::_5>, mul<test::_3, test::_5>>::value));
METAL_TEST_ASSERT((equal_to<add<test::_0, test::_1, test::_2, test::_3, test::_4, test::_5, test::_6>, mul<test::_3, test::_7>>::value));
METAL_TEST_ASSERT((equal_to<add<test::_0, test::_1, test::_2, test::_3, test::_4, test::_5, test::_6, test::_7>, mul<test::_4, test::_7>>::value));

METAL_TEST_ASSERT((equal_to<sub<test::_1, test::_1>, test::_0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::_2, test::_1, test::_1>, test::_0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::_3, test::_1, test::_1, test::_1>, test::_0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::_4, test::_1, test::_1, test::_1, test::_1>, test::_0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::_5, test::_1, test::_1, test::_1, test::_1, test::_1>, test::_0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::_6, test::_1, test::_1, test::_1, test::_1, test::_1, test::_1>, test::_0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::_7, test::_1, test::_1, test::_1, test::_1, test::_1, test::_1, test::_1>, test::_0>::value));

METAL_TEST_ASSERT((equal_to<mul<test::_2, test::_2>, std::integral_constant<int, 4>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::_2, test::_2, test::_2>, std::integral_constant<int, 8>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::_2, test::_2, test::_2, test::_2>, std::integral_constant<int, 16>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::_2, test::_2, test::_2, test::_2, test::_2>, std::integral_constant<int, 32>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::_2, test::_2, test::_2, test::_2, test::_2, test::_2>, std::integral_constant<int, 64>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::_2, test::_2, test::_2, test::_2, test::_2, test::_2, test::_2>, std::integral_constant<int, 128>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::_2, test::_2, test::_2, test::_2, test::_2, test::_2, test::_2, test::_2>, std::integral_constant<int, 256>>::value));

METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 2>, test::_2>, test::_1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 4>, test::_2, test::_2>, test::_1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 8>, test::_2, test::_2, test::_2>, test::_1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 16>, test::_2, test::_2, test::_2, test::_2>, test::_1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 32>, test::_2, test::_2, test::_2, test::_2, test::_2>, test::_1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 64>, test::_2, test::_2, test::_2, test::_2, test::_2, test::_2>, test::_1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 128>, test::_2, test::_2, test::_2, test::_2, test::_2, test::_2, test::_2>, test::_1>::value));
