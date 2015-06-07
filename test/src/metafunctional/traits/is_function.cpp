// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/traits/is_function.hpp>

#include "test/variadic.hpp"
#include "test/types.hpp"
#include "test/functions.hpp"
#include "test/main.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((not_<is_function<test::a>>));
BOOST_MPL2_ASSERT((not_<is_function<test::b>>));
BOOST_MPL2_ASSERT((not_<is_function<test::c>>));
BOOST_MPL2_ASSERT((not_<is_function<test::d>>));
BOOST_MPL2_ASSERT((not_<is_function<test::e>>));
BOOST_MPL2_ASSERT((not_<is_function<test::f>>));
BOOST_MPL2_ASSERT((not_<is_function<test::g>>));
BOOST_MPL2_ASSERT((not_<is_function<test::h>>));
BOOST_MPL2_ASSERT((not_<is_function<test::i>>));
BOOST_MPL2_ASSERT((not_<is_function<test::j>>));

BOOST_MPL2_ASSERT((not_<is_function<test::call<>>>));

BOOST_MPL2_ASSERT((is_function<test::unary<test::incomplete>>));
BOOST_MPL2_ASSERT((is_function<test::unary<test::empty>>));
BOOST_MPL2_ASSERT((is_function<test::unary<test::evaluable>>));
BOOST_MPL2_ASSERT((is_function<test::unary<test::call>>));

BOOST_MPL2_ASSERT((is_function<test::binary<test::incomplete>>));
BOOST_MPL2_ASSERT((is_function<test::binary<test::empty>>));
BOOST_MPL2_ASSERT((is_function<test::binary<test::evaluable>>));
BOOST_MPL2_ASSERT((is_function<test::binary<test::call>>));

BOOST_MPL2_ASSERT((is_function<test::n_ary<test::incomplete>>));
BOOST_MPL2_ASSERT((is_function<test::n_ary<test::empty>>));
BOOST_MPL2_ASSERT((is_function<test::n_ary<test::evaluable>>));
BOOST_MPL2_ASSERT((is_function<test::n_ary<test::call>>));
