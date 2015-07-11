// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/algebra/arithmetic.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(equal_to<inc<test::_00_>, test::_01_>::value, "");
static_assert(equal_to<dec<test::_00_>, neg<test::_01_>>::value, "");
static_assert(equal_to<inc<dec<test::_01_>>, test::_01_>::value, "");
static_assert(equal_to<inc<dec<test::_01_>>, dec<inc<test::_01_>>>::value, "");
static_assert(equal_to<neg<test::_00_>, test::_00_>::value, "");
static_assert(equal_to<inc<neg<test::_01_>>, test::_00_>::value, "");
static_assert(equal_to<neg<neg<test::_01_>>, test::_01_>::value, "");

static_assert(equal_to<add<test::_00_, test::_01_>, mul<test::_01_, test::_01_>>::value, "");
static_assert(equal_to<add<test::_00_, test::_01_, test::_02_>, mul<test::_01_, test::_03_>>::value, "");
static_assert(equal_to<add<test::_00_, test::_01_, test::_02_, test::_03_>, mul<test::_02_, test::_03_>>::value, "");
static_assert(equal_to<add<test::_00_, test::_01_, test::_02_, test::_03_, test::_04_>, mul<test::_02_, test::_05_>>::value, "");
static_assert(equal_to<add<test::_00_, test::_01_, test::_02_, test::_03_, test::_04_, test::_05_>, mul<test::_03_, test::_05_>>::value, "");
static_assert(equal_to<add<test::_00_, test::_01_, test::_02_, test::_03_, test::_04_, test::_05_, test::_06_>, mul<test::_03_, test::_07_>>::value, "");
static_assert(equal_to<add<test::_00_, test::_01_, test::_02_, test::_03_, test::_04_, test::_05_, test::_06_, test::_07_>, mul<test::_04_, test::_07_>>::value, "");

static_assert(equal_to<sub<test::_01_, test::_01_>, test::_00_>::value, "");
static_assert(equal_to<sub<test::_02_, test::_01_, test::_01_>, test::_00_>::value, "");
static_assert(equal_to<sub<test::_03_, test::_01_, test::_01_, test::_01_>, test::_00_>::value, "");
static_assert(equal_to<sub<test::_04_, test::_01_, test::_01_, test::_01_, test::_01_>, test::_00_>::value, "");
static_assert(equal_to<sub<test::_05_, test::_01_, test::_01_, test::_01_, test::_01_, test::_01_>, test::_00_>::value, "");
static_assert(equal_to<sub<test::_06_, test::_01_, test::_01_, test::_01_, test::_01_, test::_01_, test::_01_>, test::_00_>::value, "");
static_assert(equal_to<sub<test::_07_, test::_01_, test::_01_, test::_01_, test::_01_, test::_01_, test::_01_, test::_01_>, test::_00_>::value, "");

static_assert(equal_to<mul<test::_02_, test::_02_>, std::integral_constant<int, 4>>::value, "");
static_assert(equal_to<mul<test::_02_, test::_02_, test::_02_>, std::integral_constant<int, 8>>::value, "");
static_assert(equal_to<mul<test::_02_, test::_02_, test::_02_, test::_02_>, std::integral_constant<int, 16>>::value, "");
static_assert(equal_to<mul<test::_02_, test::_02_, test::_02_, test::_02_, test::_02_>, std::integral_constant<int, 32>>::value, "");
static_assert(equal_to<mul<test::_02_, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_>, std::integral_constant<int, 64>>::value, "");
static_assert(equal_to<mul<test::_02_, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_>, std::integral_constant<int, 128>>::value, "");
static_assert(equal_to<mul<test::_02_, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_>, std::integral_constant<int, 256>>::value, "");

static_assert(equal_to<metal::div<std::integral_constant<int, 2>, test::_02_>, test::_01_>::value, "");
static_assert(equal_to<metal::div<std::integral_constant<int, 4>, test::_02_, test::_02_>, test::_01_>::value, "");
static_assert(equal_to<metal::div<std::integral_constant<int, 8>, test::_02_, test::_02_, test::_02_>, test::_01_>::value, "");
static_assert(equal_to<metal::div<std::integral_constant<int, 16>, test::_02_, test::_02_, test::_02_, test::_02_>, test::_01_>::value, "");
static_assert(equal_to<metal::div<std::integral_constant<int, 32>, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_>, test::_01_>::value, "");
static_assert(equal_to<metal::div<std::integral_constant<int, 64>, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_>, test::_01_>::value, "");
static_assert(equal_to<metal::div<std::integral_constant<int, 128>, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_, test::_02_>, test::_01_>::value, "");
