// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/bind.hpp>

#include "test.hpp"

using namespace metal;

using l0 = protect_t<test::e0<>>;
using l1 = protect_t<test::e1<_1>>;
using l2 = protect_t<test::e2<_1, _2>>;
using l3 = protect_t<test::en<_1, _2, _3>>;
using l4 = protect_t<test::en<_1, _2, _3, _4>>;

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<l0, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<l1, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e1<test::v3>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<l2, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e2<test::v3, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<l3, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::en<test::v3, test::v2, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<l4, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::en<test::v3, test::v2, test::v1, test::v0>::type>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<l0>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<l1>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e1<test::v3>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<l2>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e2<test::v3, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<l3>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::en<test::v3, test::v2, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<l4>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::en<test::v3, test::v2, test::v1, test::v0>::type>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<l0, protect_t<_4>, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<l1, protect_t<_4>, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e1<protect_t<_4>>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<l2, protect_t<_4>, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e2<protect_t<_4>, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<l3, protect_t<_4>, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::en<protect_t<_4>, test::v2, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<l4, protect_t<_4>, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::en<protect_t<_4>, test::v2, test::v1, test::v0>::type>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<bind_t<l0, _4, _3, _2, _1>>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<bind_t<l1, _4, _3, _2, _1>>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e1<test::v0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<bind_t<l2, _4, _3, _2, _1>>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e2<test::v0, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<bind_t<l3, _4, _3, _2, _1>>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::en<test::v0, test::v1, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<bind_t<l4, _4, _3, _2, _1>>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::en<test::v0, test::v1, test::v2, test::v3>::type>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<_1, _2, _3, _4, _5>, l0, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<_1, _2, _3, _4, _5>, l1, test::v0, test::v1, test::v2, test::v3>, test::e1<test::v0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<_1, _2, _3, _4, _5>, l2, test::v0, test::v1, test::v2, test::v3>, test::e2<test::v0, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<_1, _2, _3, _4, _5>, l3, test::v0, test::v1, test::v2, test::v3>, test::en<test::v0, test::v1, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<_1, _2, _3, _4, _5>, l4, test::v0, test::v1, test::v2, test::v3>, test::en<test::v0, test::v1, test::v2, test::v3>::type>::value));
