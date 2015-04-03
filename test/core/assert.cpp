// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/integrals/boolean.hpp>

int main()
{
    BOOST_MPL2_ASSERT(boost::mpl2::true_);
    BOOST_MPL2_ASSERT((boost::mpl2::true_));
    BOOST_MPL2_ASSERT(((boost::mpl2::true_)));
    BOOST_MPL2_ASSERT((((boost::mpl2::true_))));

    BOOST_MPL2_ASSERT_MSG(boost::mpl2::true_, "");
    BOOST_MPL2_ASSERT_MSG((boost::mpl2::true_), "");
    BOOST_MPL2_ASSERT_MSG(((boost::mpl2::true_)), "");
    BOOST_MPL2_ASSERT_MSG((((boost::mpl2::true_))), "");

    return 0;
}
