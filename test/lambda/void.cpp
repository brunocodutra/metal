// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/void.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT(is_function<void_>);

BOOST_MPL2_ASSERT((not_<is_evaluable<void_> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<void_, short> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<void_, short, int> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<void_, short, int, long> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<void_, short, int, long, long long> >));

int main()
{
    return 0;
}
