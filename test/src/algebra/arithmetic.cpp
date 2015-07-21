// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/algebra/arithmetic.hpp>
#include <metal/algebra/comparison/equal_to.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((equal_to<inc<test::n0>, test::n1>::value));
METAL_TEST_ASSERT((equal_to<dec<test::n0>, neg<test::n1>>::value));
METAL_TEST_ASSERT((equal_to<inc<dec<test::n1>>, test::n1>::value));
METAL_TEST_ASSERT((equal_to<inc<dec<test::n1>>, dec<inc<test::n1>>>::value));
METAL_TEST_ASSERT((equal_to<neg<test::n0>, test::n0>::value));
METAL_TEST_ASSERT((equal_to<inc<neg<test::n1>>, test::n0>::value));
METAL_TEST_ASSERT((equal_to<neg<neg<test::n1>>, test::n1>::value));

METAL_TEST_ASSERT((equal_to<add<test::n0, test::n1>, mul<test::n1, test::n1>>::value));
METAL_TEST_ASSERT((equal_to<add<test::n0, test::n1, test::n2>, mul<test::n1, test::n3>>::value));
METAL_TEST_ASSERT((equal_to<add<test::n0, test::n1, test::n2, test::n3>, mul<test::n2, test::n3>>::value));
METAL_TEST_ASSERT((equal_to<add<test::n0, test::n1, test::n2, test::n3, test::n4>, mul<test::n2, test::n5>>::value));
METAL_TEST_ASSERT((equal_to<add<test::n0, test::n1, test::n2, test::n3, test::n4, test::n5>, mul<test::n3, test::n5>>::value));
METAL_TEST_ASSERT((equal_to<add<test::n0, test::n1, test::n2, test::n3, test::n4, test::n5, test::n6>, mul<test::n3, test::n7>>::value));
METAL_TEST_ASSERT((equal_to<add<test::n0, test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7>, mul<test::n4, test::n7>>::value));

METAL_TEST_ASSERT((equal_to<sub<test::n1, test::n1>, test::n0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::n2, test::n1, test::n1>, test::n0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::n3, test::n1, test::n1, test::n1>, test::n0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::n4, test::n1, test::n1, test::n1, test::n1>, test::n0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::n5, test::n1, test::n1, test::n1, test::n1, test::n1>, test::n0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::n6, test::n1, test::n1, test::n1, test::n1, test::n1, test::n1>, test::n0>::value));
METAL_TEST_ASSERT((equal_to<sub<test::n7, test::n1, test::n1, test::n1, test::n1, test::n1, test::n1, test::n1>, test::n0>::value));

METAL_TEST_ASSERT((equal_to<mul<test::n2, test::n2>, std::integral_constant<int, 4>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::n2, test::n2, test::n2>, std::integral_constant<int, 8>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::n2, test::n2, test::n2, test::n2>, std::integral_constant<int, 16>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::n2, test::n2, test::n2, test::n2, test::n2>, std::integral_constant<int, 32>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::n2, test::n2, test::n2, test::n2, test::n2, test::n2>, std::integral_constant<int, 64>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::n2, test::n2, test::n2, test::n2, test::n2, test::n2, test::n2>, std::integral_constant<int, 128>>::value));
METAL_TEST_ASSERT((equal_to<mul<test::n2, test::n2, test::n2, test::n2, test::n2, test::n2, test::n2, test::n2>, std::integral_constant<int, 256>>::value));

METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 2>, test::n2>, test::n1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 4>, test::n2, test::n2>, test::n1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 8>, test::n2, test::n2, test::n2>, test::n1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 16>, test::n2, test::n2, test::n2, test::n2>, test::n1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 32>, test::n2, test::n2, test::n2, test::n2, test::n2>, test::n1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 64>, test::n2, test::n2, test::n2, test::n2, test::n2, test::n2>, test::n1>::value));
METAL_TEST_ASSERT((equal_to<metal::div<std::integral_constant<int, 128>, test::n2, test::n2, test::n2, test::n2, test::n2, test::n2, test::n2>, test::n1>::value));
