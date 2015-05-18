// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using p0 = pack<pack<>, pack<pack<>, pack<>, pack<> > >;
using p1 = pack<p0, short, p0>;
using p2 = pack<int, p1>;
using p3 = pack<pack<long>, pack<pack<p2> > >;
using p4 = pack<p0, p0, p0, long long, pack<pack<p3> > >;

BOOST_MPL2_ASSERT((std::is_same<head<p1>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<head<p2>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<head<p3>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<head<p4>::type, long long>));

BOOST_MPL2_ASSERT((std::is_same<head<tail<p2> >::type, short>));
BOOST_MPL2_ASSERT((std::is_same<head<tail<p3> >::type, int>));
BOOST_MPL2_ASSERT((std::is_same<head<tail<p4> >::type, long>));

BOOST_MPL2_ASSERT((std::is_same<head<tail<tail<p3> > >::type, short>));
BOOST_MPL2_ASSERT((std::is_same<head<tail<tail<p4> > >::type, int>));

BOOST_MPL2_ASSERT((std::is_same<head<tail<tail<tail<p4> > > >::type, short>));

int main()
{
    return 0;
}
