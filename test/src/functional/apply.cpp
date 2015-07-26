// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/apply.hpp>
#include <metal/functional/arg.hpp>
#include <metal/functional/protect.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((std::is_same<apply_t<_1, test::v0, test::v1, test::v2, test::v3>, test::v0>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<_2, test::v0, test::v1, test::v2, test::v3>, test::v1>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<_3, test::v0, test::v1, test::v2, test::v3>, test::v2>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<_4, test::v0, test::v1, test::v2, test::v3>, test::v3>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<test::e0<>, test::v0, test::v1, test::v2, test::v3>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::e1<_1>, test::v0, test::v1, test::v2, test::v3>, test::e1<test::v0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::e2<_2, _1>, test::v0, test::v1, test::v2, test::v3>, test::e2<test::v1, test::v0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::en<_3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::en<test::v2, test::v1, test::v0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::en<_4, _3, _2, _1>, test::v0, test::v1, test::v2, test::v3>, test::en<test::v3, test::v2, test::v1, test::v0>::type>::value));

METAL_TEST_ASSERT((
    std::is_same<apply_t<
        test::en<test::e0<>>,
        test::v0, test::v1, test::v2, test::v3
    >,
    test::en<test::e0<>::type>::type
    >::value
));

METAL_TEST_ASSERT((
    std::is_same<apply_t<
        test::en<test::e0<>, test::e1<_1>>,
        test::v0, test::v1, test::v2, test::v3
    >,
    test::en<test::e0<>::type, test::e1<test::v0>::type>::type
    >::value
));

METAL_TEST_ASSERT((
    std::is_same<apply_t<
        test::en<test::e0<>, test::e1<_1>, test::e2<_1, _2>>,
        test::v0, test::v1, test::v2, test::v3
    >,
    test::en<
        test::e0<>::type,
        test::e1<test::v0>::type,
        test::e2<test::v0, test::v1>::type
    >::type
    >::value
));

METAL_TEST_ASSERT((
    std::is_same<apply_t<
        test::en<
            test::e0<>,
            test::e1<_1>,
            test::e2<_1, _2>,
            test::en<_1, _2, _3>
        >,
        test::v0, test::v1, test::v2, test::v3
    >,
    test::en<
        test::e0<>::type,
        test::e1<test::v0>::type,
        test::e2<test::v0, test::v1>::type,
        test::en<test::v0, test::v1, test::v2>::type
    >::type
    >::value
));

METAL_TEST_ASSERT((
    std::is_same<apply_t<
        test::en<
            test::e0<>,
            test::e1<_1>,
            test::e2<_1, _2>,
            test::en<_1, _2, _3>,
            test::en<_1, _2, _3, _4>
        >,
        test::v0, test::v1, test::v2, test::v3
    >,
    test::en<
        test::e0<>::type,
        test::e1<test::v0>::type,
        test::e2<test::v0, test::v1>::type,
        test::en<test::v0, test::v1, test::v2>::type,
        test::en<test::v0, test::v1, test::v2, test::v3>::type
    >::type
    >::value
));
