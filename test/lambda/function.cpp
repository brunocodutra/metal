// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/function.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using f = function<std::add_pointer>;

BOOST_MPL2_ASSERT(is_function<f>);
BOOST_MPL2_ASSERT((is_evaluable<f, void>));
BOOST_MPL2_ASSERT((std::is_same<eval<f, void>, void*>));

using h = nullary<std::add_pointer<void> >;

BOOST_MPL2_ASSERT(is_function<h>);

BOOST_MPL2_ASSERT((is_evaluable<h>));
BOOST_MPL2_ASSERT((is_evaluable<h, short>));
BOOST_MPL2_ASSERT((is_evaluable<h, short, void>));
BOOST_MPL2_ASSERT((is_evaluable<h, short, void, long>));
BOOST_MPL2_ASSERT((is_evaluable<h, short, void, long, long long>));

BOOST_MPL2_ASSERT((std::is_same<eval<h>, void*>));
BOOST_MPL2_ASSERT((std::is_same<eval<h, short>, void*>));
BOOST_MPL2_ASSERT((std::is_same<eval<h, short, void>, void*>));
BOOST_MPL2_ASSERT((std::is_same<eval<h, short, void, long>, void*>));
BOOST_MPL2_ASSERT((std::is_same<eval<h, short, void, long, long long>, void*>));

struct empty {};

using g = nullary<empty>;

BOOST_MPL2_ASSERT(is_function<g>);

BOOST_MPL2_ASSERT((not_<is_evaluable<g> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<g, short> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<g, short, void> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<g, short, void, long> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<g, short, void, long, long long> >));

int main()
{
    return 0;
}
