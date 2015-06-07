// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/call.hpp>

#include "test/functions.hpp"
#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace boost::mpl2;

using f0 = test::nullary<test::wrap>;
using f1 = test::unary<test::wrap>;
using f2 = test::binary<test::wrap>;
using fn = test::n_ary<test::wrap>;

BOOST_MPL2_ASSERT((std::is_same<call_t<f0>, f0::call<>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<f1, void>, f1::call<void>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<f2, void, void*>, f2::call<void, void*>::type>));

BOOST_MPL2_ASSERT((std::is_same<call_t<fn>, fn::call<>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<fn, short>, fn::call<short>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<fn, short, int>, fn::call<short, int>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<fn, short, int, long>, fn::call<short, int, long>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<fn, short, int, long, long long>, fn::call<short, int, long, long long>::type>));
