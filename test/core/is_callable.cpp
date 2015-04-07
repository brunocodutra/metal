// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/integrals/logical/not.hpp>
#include <boost/mpl2/core/is_callable.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/bind.hpp>
#include <boost/mpl2/core/assert.hpp>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT(not_<is_callable<void> >);
BOOST_MPL2_ASSERT(not_<is_callable<identity<void> > >);
BOOST_MPL2_ASSERT(is_callable<function<identity> >);
BOOST_MPL2_ASSERT((is_callable<bind<function<identity>, void> >));

int main()
{
    return 0;
}
