// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/core/integral.hpp>

using boost::mpl2::true_;

BOOST_MPL2_ASSERT((true_));
BOOST_MPL2_ASSERT_MSG((true_), "");
BOOST_MPL2_ASSERT_EXPR((true));
BOOST_MPL2_ASSERT_EXPR_MSG((true), "");

int main()
{
    return 0;
}
