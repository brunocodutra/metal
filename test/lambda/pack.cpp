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

BOOST_MPL2_ASSERT((std::is_same<typename head<short>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<typename head<int, short>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<typename head<long, int, short>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<typename head<long long, long, int, short>::type, long long>));

BOOST_MPL2_ASSERT((std::is_same<typename head<tail<int, short> >::type, short>));
BOOST_MPL2_ASSERT((std::is_same<typename head<tail<long, int, short> >::type, int>));
BOOST_MPL2_ASSERT((std::is_same<typename head<tail<long long, long, int, short> >::type, long>));

BOOST_MPL2_ASSERT((std::is_same<typename head<tail<tail<long, int, short> > >::type, short>));
BOOST_MPL2_ASSERT((std::is_same<typename head<tail<tail<long long, long, int, short> > >::type, int>));

BOOST_MPL2_ASSERT((std::is_same<typename head<tail<tail<tail<long long, long, int, short> > > >::type, short>));

BOOST_MPL2_ASSERT((equal_to<sizeof_<>, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<short>, size_t_<1> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<int, short>, size_t_<2> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<long, int, short>, size_t_<3> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<long long, long, int, short>, size_t_<4> >));

BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<> >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<short> >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<int, short> >, size_t_<1> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<long, int, short> >, size_t_<2> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<long long, long, int, short> >, size_t_<3> >));

BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<> > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<short> > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<int, short> > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<long, int, short> > >, size_t_<1> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<long long, long, int, short> > >, size_t_<2> >));

BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<> > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<short> > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<int, short> > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<long, int, short> > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<long long, long, int, short> > > >, size_t_<1> >));

BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<tail<> > > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<tail<short> > > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<tail<int, short> > > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<tail<long, int, short> > > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<tail<long long, long, int, short> > > > >, size_t_<0> >));

using p0 = pack<pack<>, pack<pack<>, pack<>, pack<> > >;
using p1 = pack<p0, short, p0>;
using p2 = pack<int, p1>;
using p3 = pack<pack<long>, pack<pack<p2> > >;
using p4 = pack<p0, p0, p0, long long, pack<pack<p3> > >;

BOOST_MPL2_ASSERT((std::is_same<typename head<p1>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<typename head<p2>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<typename head<p3>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<typename head<p4>::type, long long>));

BOOST_MPL2_ASSERT((std::is_same<typename head<tail<p2> >::type, short>));
BOOST_MPL2_ASSERT((std::is_same<typename head<tail<p3> >::type, int>));
BOOST_MPL2_ASSERT((std::is_same<typename head<tail<p4> >::type, long>));

BOOST_MPL2_ASSERT((std::is_same<typename head<tail<tail<p3> > >::type, short>));
BOOST_MPL2_ASSERT((std::is_same<typename head<tail<tail<p4> > >::type, int>));

BOOST_MPL2_ASSERT((std::is_same<typename head<tail<tail<tail<p4> > > >::type, short>));

BOOST_MPL2_ASSERT((equal_to<sizeof_<p0>, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<p1>, size_t_<1> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<p2>, size_t_<2> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<p3>, size_t_<3> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<p4>, size_t_<4> >));

BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<p0> >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<p1> >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<p2> >, size_t_<1> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<p3> >, size_t_<2> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<p4> >, size_t_<3> >));

BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<p0> > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<p1> > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<p2> > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<p3> > >, size_t_<1> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<p4> > >, size_t_<2> >));

BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<p0> > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<p1> > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<p2> > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<p3> > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<p4> > > >, size_t_<1> >));

BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<tail<p0> > > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<tail<p1> > > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<tail<p2> > > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<tail<p3> > > > >, size_t_<0> >));
BOOST_MPL2_ASSERT((equal_to<sizeof_<tail<tail<tail<tail<p4> > > > >, size_t_<0> >));

template<typename...>
struct wrapper
{
    using type = wrapper;
};

BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, p0>::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, p1>::type, wrapper<short> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, p2>::type, wrapper<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, p3>::type, wrapper<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, p4>::type, wrapper<long long, long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, p0>::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, p1>::type, wrapper<short> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, p2>::type, wrapper<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, p3>::type, wrapper<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, p4>::type, wrapper<long long, long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<p0> >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<p1> >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<p2> >::type, wrapper<short> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<p3> >::type, wrapper<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<p4> >::type, wrapper<long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<p0> > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<p1> > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<p2> > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<p3> > >::type, wrapper<short> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<p4> > >::type, wrapper<int, short> >));

BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<tail<p0> > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<tail<p1> > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<tail<p2> > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<tail<p3> > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<tail<p4> > > >::type, wrapper<short> >));

BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<tail<tail<p0> > > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<tail<tail<p1> > > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<tail<tail<p2> > > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<tail<tail<p3> > > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<typename unpack<wrapper, tail<tail<tail<tail<p4> > > > >::type, wrapper<> >));

int main()
{
    return 0;
}
