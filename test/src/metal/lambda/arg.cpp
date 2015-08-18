// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/arg.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((std::is_same<_1, arg<1U>>::value));
METAL_TEST_ASSERT((std::is_same<_2, arg<2U>>::value));
METAL_TEST_ASSERT((std::is_same<_3, arg<3U>>::value));
METAL_TEST_ASSERT((std::is_same<_4, arg<4U>>::value));
METAL_TEST_ASSERT((std::is_same<_5, arg<5U>>::value));
METAL_TEST_ASSERT((std::is_same<_6, arg<6U>>::value));
METAL_TEST_ASSERT((std::is_same<_7, arg<7U>>::value));
METAL_TEST_ASSERT((std::is_same<_8, arg<8U>>::value));
METAL_TEST_ASSERT((std::is_same<_9, arg<9U>>::value));
