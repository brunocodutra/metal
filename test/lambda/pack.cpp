// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/comparison/equal_to.hpp>
#include <boost/mpl2/lambda/integral/size_t.hpp>
#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using p0 = pack<pack<>, pack<pack<>, pack<>, pack<> > >;
using p1 = pack<p0, short, p0>;
using p2 = pack<int, p1>;
using p3 = pack<pack<long>, pack<pack<p2> > >;
using p4 = pack<p0, p0, p0, long long, pack<pack<p3> > >;

BOOST_MPL2_ASSERT((std::is_same<typename head<p1>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<typename head<p2>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<typename head<p3>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<typename head<p4>::type, long long>));

BOOST_MPL2_ASSERT((std::is_same<typename head<tail<p2> >::type, typename head<p1>::type>));
BOOST_MPL2_ASSERT((std::is_same<typename head<tail<p3> >::type, typename head<p2>::type>));
BOOST_MPL2_ASSERT((std::is_same<typename head<tail<p4> >::type, typename head<p3>::type>));

BOOST_MPL2_ASSERT((std::is_same<typename head<tail<tail<p3> > >::type, typename head<p1>::type>));
BOOST_MPL2_ASSERT((std::is_same<typename head<tail<tail<p4> > >::type, typename head<p2>::type>));

BOOST_MPL2_ASSERT((std::is_same<typename head<tail<tail<tail<p4> > > >::type, typename head<p1>::type>));

BOOST_MPL2_ASSERT((equal_to<sizeof_<p0>, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<p1>, size_t_<1> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<p2>, size_t_<2> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<p3>, size_t_<3> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<p4>, size_t_<4> >));

BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<p0> >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<p1> >, sizeof_<p0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<p2> >, sizeof_<p1> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<p3> >, sizeof_<p2> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<p4> >, sizeof_<p3> >));

int main()
{
    return 0;
}
