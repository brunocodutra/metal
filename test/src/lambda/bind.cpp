// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/bind.hpp>

#include "test.hpp"

using namespace metal;

using lbd0 = protect_t<test::e0<>>;
using lbd1 = protect_t<test::e1<_1>>;
using lbd2 = protect_t<test::e2<_1, _2>>;
using lbd3 = protect_t<test::expr<_1, _2, _3>>;
using lbd4 = protect_t<test::seq<_1, _2, _3, _4>>;

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd0, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd1, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e1<test::v3>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd2, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e2<test::v3, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd3, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::expr<test::v3, test::v2, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd4, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::seq<test::v3, test::v2, test::v1, test::v0>>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<lbd0>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<lbd1>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e1<test::v3>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<lbd2>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e2<test::v3, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<lbd3>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::expr<test::v3, test::v2, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<lbd4>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::seq<test::v3, test::v2, test::v1, test::v0>>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd0, protect_t<_4>, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd1, protect_t<_4>, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e1<protect_t<_4>>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd2, protect_t<_4>, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e2<protect_t<_4>, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd3, protect_t<_4>, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::expr<protect_t<_4>, test::v2, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd4, protect_t<_4>, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::seq<protect_t<_4>, test::v2, test::v1, test::v0>>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<bind_t<lbd0, _4, _3, _2, _1>>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<bind_t<lbd1, _4, _3, _2, _1>>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e1<test::v0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<bind_t<lbd2, _4, _3, _2, _1>>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e2<test::v0, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<bind_t<lbd3, _4, _3, _2, _1>>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::expr<test::v0, test::v1, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<protect_t<bind_t<lbd4, _4, _3, _2, _1>>, _4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::seq<test::v0, test::v1, test::v2, test::v3>>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<_1, _2, _3, _4, _5>, lbd0, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<_1, _2, _3, _4, _5>, lbd1, test::v0, test::v1, test::v2, test::v3>, test::e1<test::v0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<_1, _2, _3, _4, _5>, lbd2, test::v0, test::v1, test::v2, test::v3>, test::e2<test::v0, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<_1, _2, _3, _4, _5>, lbd3, test::v0, test::v1, test::v2, test::v3>, test::expr<test::v0, test::v1, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<_1, _2, _3, _4, _5>, lbd4, test::v0, test::v1, test::v2, test::v3>, test::seq<test::v0, test::v1, test::v2, test::v3>>::value));
