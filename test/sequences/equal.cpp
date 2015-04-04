// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/integrals/logical/not.hpp>
#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/sequences/equal.hpp>

using boost::mpl2::equal;
using boost::mpl2::not_;

BOOST_MPL2_ASSERT((equal<void, void>));
BOOST_MPL2_ASSERT((not_<equal<void, void*> >));

int main()
{
    return 0;
}
