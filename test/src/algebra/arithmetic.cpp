/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/algebra/arithmetic.hpp>

#include "test/integrals.hpp"
#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((equal_to<inc<test::zero>, test::one>));
METAL_ASSERT((equal_to<dec<test::zero>, neg<test::one>>));
METAL_ASSERT((equal_to<inc<dec<test::one>>, test::one>));
METAL_ASSERT((equal_to<inc<dec<test::one>>, dec<inc<test::one>>>));
METAL_ASSERT((equal_to<neg<test::zero>, test::zero>));
METAL_ASSERT((equal_to<inc<neg<test::one>>, test::zero>));
METAL_ASSERT((equal_to<neg<neg<test::one>>, test::one>));

METAL_ASSERT((equal_to<add<test::zero, test::one>, mul<test::one, test::one>>));
METAL_ASSERT((equal_to<add<test::zero, test::one, test::two>, mul<test::one, test::three>>));
METAL_ASSERT((equal_to<add<test::zero, test::one, test::two, test::three>, mul<test::two, test::three>>));
METAL_ASSERT((equal_to<add<test::zero, test::one, test::two, test::three, test::four>, mul<test::two, test::five>>));
METAL_ASSERT((equal_to<add<test::zero, test::one, test::two, test::three, test::four, test::five>, mul<test::three, test::five>>));
METAL_ASSERT((equal_to<add<test::zero, test::one, test::two, test::three, test::four, test::five, test::six>, mul<test::three, test::seven>>));
METAL_ASSERT((equal_to<add<test::zero, test::one, test::two, test::three, test::four, test::five, test::six, test::seven>, mul<test::four, test::seven>>));

METAL_ASSERT((equal_to<sub<test::one, test::one>, test::zero>));
METAL_ASSERT((equal_to<sub<test::two, test::one, test::one>, test::zero>));
METAL_ASSERT((equal_to<sub<test::three, test::one, test::one, test::one>, test::zero>));
METAL_ASSERT((equal_to<sub<test::four, test::one, test::one, test::one, test::one>, test::zero>));
METAL_ASSERT((equal_to<sub<test::five, test::one, test::one, test::one, test::one, test::one>, test::zero>));
METAL_ASSERT((equal_to<sub<test::six, test::one, test::one, test::one, test::one, test::one, test::one>, test::zero>));
METAL_ASSERT((equal_to<sub<test::seven, test::one, test::one, test::one, test::one, test::one, test::one, test::one>, test::zero>));

METAL_ASSERT((equal_to<mul<test::two, test::two>, std::integral_constant<int, 4>>));
METAL_ASSERT((equal_to<mul<test::two, test::two, test::two>, std::integral_constant<int, 8>>));
METAL_ASSERT((equal_to<mul<test::two, test::two, test::two, test::two>, std::integral_constant<int, 16>>));
METAL_ASSERT((equal_to<mul<test::two, test::two, test::two, test::two, test::two>, std::integral_constant<int, 32>>));
METAL_ASSERT((equal_to<mul<test::two, test::two, test::two, test::two, test::two, test::two>, std::integral_constant<int, 64>>));
METAL_ASSERT((equal_to<mul<test::two, test::two, test::two, test::two, test::two, test::two, test::two>, std::integral_constant<int, 128>>));
METAL_ASSERT((equal_to<mul<test::two, test::two, test::two, test::two, test::two, test::two, test::two, test::two>, std::integral_constant<int, 256>>));

METAL_ASSERT((equal_to<metal::div<std::integral_constant<int, 2>, test::two>, test::one>));
METAL_ASSERT((equal_to<metal::div<std::integral_constant<int, 4>, test::two, test::two>, test::one>));
METAL_ASSERT((equal_to<metal::div<std::integral_constant<int, 8>, test::two, test::two, test::two>, test::one>));
METAL_ASSERT((equal_to<metal::div<std::integral_constant<int, 16>, test::two, test::two, test::two, test::two>, test::one>));
METAL_ASSERT((equal_to<metal::div<std::integral_constant<int, 32>, test::two, test::two, test::two, test::two, test::two>, test::one>));
METAL_ASSERT((equal_to<metal::div<std::integral_constant<int, 64>, test::two, test::two, test::two, test::two, test::two, test::two>, test::one>));
METAL_ASSERT((equal_to<metal::div<std::integral_constant<int, 128>, test::two, test::two, test::two, test::two, test::two, test::two, test::two>, test::one>));
