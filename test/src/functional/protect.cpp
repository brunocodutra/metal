// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/protect.hpp>
#include <metal/functional/apply.hpp>
#include <metal/functional/arg.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((std::is_same<apply_t<protect_t<_1>, test::v0, test::v1, test::v2, test::v3>, test::v0>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<protect_t<_2>, test::v0, test::v1, test::v2, test::v3>, test::v1>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<protect_t<_3>, test::v0, test::v1, test::v2, test::v3>, test::v2>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<protect_t<_4>, test::v0, test::v1, test::v2, test::v3>, test::v3>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<test::e1<protect_t<_1>>, test::v0, test::v1, test::v2, test::v3>, test::e1<protect_t<_1>>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::e2<protect_t<_1>, _2>, test::v0, test::v1, test::v2, test::v3>, test::e2<protect_t<_1>, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::en<protect_t<_1>, _2, _3>, test::v0, test::v1, test::v2, test::v3>, test::en<protect_t<_1>, test::v1, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::en<protect_t<_1>, _2, _3, _4>, test::v0, test::v1, test::v2, test::v3>, test::en<protect_t<_1>, test::v1, test::v2, test::v3>::type>::value));
