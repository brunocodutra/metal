// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/bind.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>

#include "test.hpp"

using namespace metal;

using lbd0 = test::expr0<>;
using lbd1 = test::expr1<_1>;
using lbd2 = test::expr2<_1, _2>;
using lbd3 = test::expr<_1, _2, _3>;
using lbd4 = test::expr<_1, _2, _3, _4>;

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd0, _4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd1, _4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr1<test::val3>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd2, _4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr2<test::val3, test::val2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd3, _4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr<test::val3, test::val2, test::val1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd4, _4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr<test::val3, test::val2, test::val1, test::val0>::type>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<quote_t<lbd0>, _4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, lbd0>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<quote_t<lbd1>, _4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, lbd1>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<quote_t<lbd2>, _4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, lbd2>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<quote_t<lbd3>, _4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, lbd3>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<quote_t<lbd4>, _4, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, lbd4>::value));

METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd0, quote_t<_4>, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd1, quote_t<_4>, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr1<_4>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd2, quote_t<_4>, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr2<_4, test::val2>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd3, quote_t<_4>, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr<_4, test::val2, test::val1>::type>::value));
METAL_TEST_ASSERT((std::is_same<apply_t<bind_t<lbd4, quote_t<_4>, _3, _2, _1>, test::val0, test::val1, test::val2, test::val3>, test::expr<_4, test::val2, test::val1, test::val0>::type>::value));
