// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/nullary.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using f = nullary<std::add_pointer<void> >;

BOOST_MPL2_ASSERT(is_function<f>);

BOOST_MPL2_ASSERT((is_callable<f>));
BOOST_MPL2_ASSERT((is_callable<f, short>));
BOOST_MPL2_ASSERT((is_callable<f, short, void>));
BOOST_MPL2_ASSERT((is_callable<f, short, void, long>));
BOOST_MPL2_ASSERT((is_callable<f, short, void, long, long long>));

BOOST_MPL2_ASSERT((std::is_same<call<f>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<f, short>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<f, short, void>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<f, short, void, long>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<f, short, void, long, long long>::type, void*>));

struct empty {};

using g = nullary<empty>;

BOOST_MPL2_ASSERT(is_function<g>);

BOOST_MPL2_ASSERT((not_<is_callable<g> >));
BOOST_MPL2_ASSERT((not_<is_callable<g, short> >));
BOOST_MPL2_ASSERT((not_<is_callable<g, short, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<g, short, void, long> >));
BOOST_MPL2_ASSERT((not_<is_callable<g, short, void, long, long long> >));

int main()
{
    return 0;
}
