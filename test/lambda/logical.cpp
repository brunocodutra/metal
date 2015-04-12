// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical.hpp>
#include <boost/mpl2/lambda/integral/boolean.hpp>
#include <boost/mpl2/lambda/comparison/equal_to.hpp>
#include <boost/mpl2/lambda/assert.hpp>

using namespace boost::mpl2;

struct undefined;

BOOST_MPL2_ASSERT((or_<false_, true_>));
BOOST_MPL2_ASSERT((or_<false_, false_, true_>));
BOOST_MPL2_ASSERT((or_<false_, false_, false_, true_>));
BOOST_MPL2_ASSERT((or_<false_, false_, false_, false_, true_>));
BOOST_MPL2_ASSERT((or_<false_, false_, false_, false_, false_, true_>));
BOOST_MPL2_ASSERT((or_<false_, false_, false_, false_, false_, false_, true_>));
BOOST_MPL2_ASSERT((or_<false_, false_, false_, false_, false_, false_, false_, true_>));

BOOST_MPL2_ASSERT((not_<or_<false_, false_> >));
BOOST_MPL2_ASSERT((not_<or_<false_, false_, false_> >));
BOOST_MPL2_ASSERT((not_<or_<false_, false_, false_, false_> >));
BOOST_MPL2_ASSERT((not_<or_<false_, false_, false_, false_, false_> >));
BOOST_MPL2_ASSERT((not_<or_<false_, false_, false_, false_, false_, false_> >));
BOOST_MPL2_ASSERT((not_<or_<false_, false_, false_, false_, false_, false_, false_> >));
BOOST_MPL2_ASSERT((not_<or_<false_, false_, false_, false_, false_, false_, false_, false_> >));

BOOST_MPL2_ASSERT((and_<true_, true_>));
BOOST_MPL2_ASSERT((and_<true_, true_, true_>));
BOOST_MPL2_ASSERT((and_<true_, true_, true_, true_>));
BOOST_MPL2_ASSERT((and_<true_, true_, true_, true_, true_>));
BOOST_MPL2_ASSERT((and_<true_, true_, true_, true_, true_, true_>));
BOOST_MPL2_ASSERT((and_<true_, true_, true_, true_, true_, true_, true_>));
BOOST_MPL2_ASSERT((and_<true_, true_, true_, true_, true_, true_, true_, true_>));

BOOST_MPL2_ASSERT((not_<and_<true_, false_> >));
BOOST_MPL2_ASSERT((not_<and_<true_, true_, false_> >));
BOOST_MPL2_ASSERT((not_<and_<true_, true_, true_, false_> >));
BOOST_MPL2_ASSERT((not_<and_<true_, true_, true_, true_, false_> >));
BOOST_MPL2_ASSERT((not_<and_<true_, true_, true_, true_, true_, false_> >));
BOOST_MPL2_ASSERT((not_<and_<true_, true_, true_, true_, true_, true_, false_> >));
BOOST_MPL2_ASSERT((not_<and_<true_, true_, true_, true_, true_, true_, true_, false_> >));

BOOST_MPL2_ASSERT((or_<true_, undefined>));
BOOST_MPL2_ASSERT((or_<true_, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<true_, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<true_, undefined, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<true_, undefined, undefined, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<true_, undefined, undefined, undefined, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<true_, undefined, undefined, undefined, undefined, undefined, undefined, undefined>));

BOOST_MPL2_ASSERT((not_<and_<false_, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<false_, undefined, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<false_, undefined, undefined, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<false_, undefined, undefined, undefined, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<false_, undefined, undefined, undefined, undefined, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<false_, undefined, undefined, undefined, undefined, undefined, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<false_, undefined, undefined, undefined, undefined, undefined, undefined, undefined> >));

BOOST_MPL2_ASSERT_EXPR((or_<false_, true_>{}));
BOOST_MPL2_ASSERT_EXPR((and_<true_, true_>{}));
BOOST_MPL2_ASSERT_EXPR((not_<or_<false_, false_> >{}));

int main()
{
    return 0;
}
