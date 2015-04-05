// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/integrals/logical/not.hpp>
#include <boost/mpl2/core/trait.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/always.hpp>
#include <boost/mpl2/core/assert.hpp>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT(not_<is_nullary_function<void> >);
BOOST_MPL2_ASSERT(not_<is_nullary_functional<void> >);

BOOST_MPL2_ASSERT(is_nullary_function<identity<void> >);
BOOST_MPL2_ASSERT(not_<is_nullary_functional<identity<void> > >);

BOOST_MPL2_ASSERT(not_<is_nullary_function<always<void> > >);
BOOST_MPL2_ASSERT(is_nullary_functional<always<void> >);

int main()
{
    return 0;
}
