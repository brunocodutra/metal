// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/traits/is_function.hpp>

#include "test.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((not_<is_function<test::fundamental<>>>));
BOOST_MPL2_ASSERT((not_<is_function<test::function<>>>));
BOOST_MPL2_ASSERT((not_<is_function<test::incomplete<>>>));
BOOST_MPL2_ASSERT((not_<is_function<test::empty<>>>));
BOOST_MPL2_ASSERT((not_<is_function<test::eponym<test::call>>>));
BOOST_MPL2_ASSERT((not_<is_function<test::evaluable<>>>));

BOOST_MPL2_ASSERT((is_function<test::unary<test::incomplete>>));
BOOST_MPL2_ASSERT((is_function<test::unary<test::empty>>));
BOOST_MPL2_ASSERT((is_function<test::unary<test::evaluable>>));

BOOST_MPL2_ASSERT((is_function<test::binary<test::incomplete>>));
BOOST_MPL2_ASSERT((is_function<test::binary<test::empty>>));
BOOST_MPL2_ASSERT((is_function<test::binary<test::evaluable>>));

BOOST_MPL2_ASSERT((is_function<test::n_ary<test::incomplete>>));
BOOST_MPL2_ASSERT((is_function<test::n_ary<test::empty>>));
BOOST_MPL2_ASSERT((is_function<test::n_ary<test::evaluable>>));

int main()
{
    return 0;
}
