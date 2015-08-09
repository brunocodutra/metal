// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/apply.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((is_just<apply<test::val0>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val1>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val2>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val3>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val4>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val5>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val6>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val7>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val8>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val9>>::value));

METAL_TEST_ASSERT((is_just<apply<test::val0, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val1, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val2, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val3, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val4, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val5, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val6, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val7, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val8, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val9, void>>::value));

METAL_TEST_ASSERT((is_just<apply<test::val0, void, void*>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val1, void, void*>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val2, void, void*>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val3, void, void*>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val4, void, void*>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val5, void, void*>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val6, void, void*>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val7, void, void*>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val8, void, void*>>::value));
METAL_TEST_ASSERT((is_just<apply<test::val9, void, void*>>::value));

METAL_TEST_ASSERT((!is_just<apply<test::list0>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list1>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list2>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list3>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list4>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list5>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list6>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list7>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list8>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list9>>::value));

METAL_TEST_ASSERT((!is_just<apply<test::list0, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list1, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list2, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list3, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list4, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list5, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list6, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list7, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list8, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list9, void>>::value));

METAL_TEST_ASSERT((!is_just<apply<test::list0, void, void*>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list1, void, void*>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list2, void, void*>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list3, void, void*>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list4, void, void*>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list5, void, void*>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list6, void, void*>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list7, void, void*>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list8, void, void*>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::list9, void, void*>>::value));

METAL_TEST_ASSERT((!is_just<apply<test::empty<>>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::empty<>, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::empty<>, void, void*>>::value));

METAL_TEST_ASSERT((is_just<apply<test::expr0<>>>::value));
METAL_TEST_ASSERT((is_just<apply<test::expr0<>, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::expr0<>, void, void*>>::value));

METAL_TEST_ASSERT((!is_just<apply<test::expr1<arg<0>>>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::expr1<arg<0>>, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::expr1<arg<0>>, void, void*>>::value));

METAL_TEST_ASSERT((!is_just<apply<test::expr1<_1>>>::value));
METAL_TEST_ASSERT((is_just<apply<test::expr1<_1>, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::expr1<_1>, void, void*>>::value));

METAL_TEST_ASSERT((!is_just<apply<test::expr2<_1, _2>>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::expr2<_1, _2>, void>>::value));
METAL_TEST_ASSERT((is_just<apply<test::expr2<_1, _2>, void, void*>>::value));

METAL_TEST_ASSERT((!is_just<apply<test::expr<_1, _2, _3>>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::expr<_1, _2, _3>, void>>::value));
METAL_TEST_ASSERT((!is_just<apply<test::expr<_1, _2, _3>, void, void*>>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<_1, test::val0, test::val1, test::val2, test::val3>, test::val0>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<_2, test::val0, test::val1, test::val2, test::val3>, test::val1>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<_3, test::val0, test::val1, test::val2, test::val3>, test::val2>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<_4, test::val0, test::val1, test::val2, test::val3>, test::val3>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<test::expr0<>, test::val0, test::val1, test::val2, test::val3>, test::expr0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::expr1<_1>, test::val0, test::val1, test::val2, test::val3>, test::expr1<test::val0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::expr2<_2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr2<test::val1, test::val0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::expr<_3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr<test::val2, test::val1, test::val0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<test::expr<_4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr<test::val3, test::val2, test::val1, test::val0>::type>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<apply<_1, _2, _3, _4, _5>, test::expr0<>, test::val0, test::val1, test::val2, test::val3>, test::expr0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<apply<_1, _2, _3, _4, _5>, test::expr1<_1>, test::val0, test::val1, test::val2, test::val3>, test::expr1<test::val0>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<apply<_1, _2, _3, _4, _5>, test::expr2<_1, _2>, test::val0, test::val1, test::val2, test::val3>, test::expr2<test::val0, test::val1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<apply<_1, _2, _3, _4, _5>, test::expr<_1, _2, _3>, test::val0, test::val1, test::val2, test::val3>, test::expr<test::val0, test::val1, test::val2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<apply<_1, _2, _3, _4, _5>, test::expr<_1, _2, _3, _4>, test::val0, test::val1, test::val2, test::val3>, test::expr<test::val0, test::val1, test::val2, test::val3>::type>::value));

METAL_TEST_ASSERT((
    std::is_same<apply_t<
        test::expr<test::expr0<>>,
        test::val0, test::val1, test::val2, test::val3
    >,
    test::expr<test::expr0<>::type>::type
    >::value
));

METAL_TEST_ASSERT((
    std::is_same<apply_t<
        test::expr<test::expr0<>, test::expr1<_1>>,
        test::val0, test::val1, test::val2, test::val3
    >,
    test::expr<test::expr0<>::type, test::expr1<test::val0>::type>::type
    >::value
));

METAL_TEST_ASSERT((
    std::is_same<apply_t<
        test::expr<test::expr0<>, test::expr1<_1>, test::expr2<_1, _2>>,
        test::val0, test::val1, test::val2, test::val3
    >,
    test::expr<
        test::expr0<>::type,
        test::expr1<test::val0>::type,
        test::expr2<test::val0, test::val1>::type
    >::type
    >::value
));

METAL_TEST_ASSERT((
    std::is_same<apply_t<
        test::expr<
            test::expr0<>,
            test::expr1<_1>,
            test::expr2<_1, _2>,
            test::expr<_1, _2, _3>
        >,
        test::val0, test::val1, test::val2, test::val3
    >,
    test::expr<
        test::expr0<>::type,
        test::expr1<test::val0>::type,
        test::expr2<test::val0, test::val1>::type,
        test::expr<test::val0, test::val1, test::val2>::type
    >::type
    >::value
));

METAL_TEST_ASSERT((
    std::is_same<apply_t<
        test::expr<
            test::expr0<>,
            test::expr1<_1>,
            test::expr2<_1, _2>,
            test::expr<_1, _2, _3>,
            test::expr<_1, _2, _3, _4>
        >,
        test::val0, test::val1, test::val2, test::val3
    >,
    test::expr<
        test::expr0<>::type,
        test::expr1<test::val0>::type,
        test::expr2<test::val0, test::val1>::type,
        test::expr<test::val0, test::val1, test::val2>::type,
        test::expr<test::val0, test::val1, test::val2, test::val3>::type
    >::type
    >::value
));
