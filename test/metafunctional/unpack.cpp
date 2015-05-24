// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/pack.hpp>
#include <boost/mpl2/metafunctional/unpack.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

template<typename...>
struct wrapper
{
    using type = wrapper;
};

using p0 = pack<pack<>, pack<pack<>, pack<>, pack<> > >;
using p1 = pack<p0, short, p0>;
using p2 = pack<int, p1>;
using p3 = pack<pack<long>, pack<pack<p2> > >;
using p4 = pack<p0, p0, p0, long long, pack<pack<p3> > >;

BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, p0>::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, p1>::type, wrapper<short> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, p2>::type, wrapper<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, p3>::type, wrapper<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, p4>::type, wrapper<long long, long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, p0>::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, p1>::type, wrapper<short> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, p2>::type, wrapper<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, p3>::type, wrapper<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, p4>::type, wrapper<long long, long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<p0> >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<p1> >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<p2> >::type, wrapper<short> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<p3> >::type, wrapper<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<p4> >::type, wrapper<long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<p0> > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<p1> > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<p2> > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<p3> > >::type, wrapper<short> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<p4> > >::type, wrapper<int, short> >));

BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<tail<p0> > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<tail<p1> > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<tail<p2> > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<tail<p3> > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<tail<p4> > > >::type, wrapper<short> >));

BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<tail<tail<p0> > > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<tail<tail<p1> > > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<tail<tail<p2> > > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<tail<tail<p3> > > > >::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<unpack<wrapper, tail<tail<tail<tail<p4> > > > >::type, wrapper<> >));

int main()
{
    return 0;
}
