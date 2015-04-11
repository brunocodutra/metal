// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/integrals/logical/not.hpp>
#include <boost/mpl2/core/function.hpp>
#include <boost/mpl2/core/call.hpp>
#include <boost/mpl2/core/traits.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using f = function<std::add_pointer>;

BOOST_MPL2_ASSERT(is_function<f>);
BOOST_MPL2_ASSERT((is_callable<f, void>));
BOOST_MPL2_ASSERT((std::is_same<call<f, void>::type, void*>));

using h = nullary<std::add_pointer<void> >;

BOOST_MPL2_ASSERT(is_function<h>);

BOOST_MPL2_ASSERT((is_callable<h>));
BOOST_MPL2_ASSERT((is_callable<h, short>));
BOOST_MPL2_ASSERT((is_callable<h, short, void>));
BOOST_MPL2_ASSERT((is_callable<h, short, void, long>));
BOOST_MPL2_ASSERT((is_callable<h, short, void, long, long long>));

BOOST_MPL2_ASSERT((std::is_same<call<h>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<h, short>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<h, short, void>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<h, short, void, long>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<h, short, void, long, long long>::type, void*>));

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
