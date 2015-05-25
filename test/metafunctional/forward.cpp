// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/forward.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

template<typename...>
struct wrap
{
    using type = wrap;
};

using p0 = detail::args<detail::args<>, detail::args<detail::args<>, detail::args<>, detail::args<> > >;
using p1 = detail::args<p0, short, p0>;
using p2 = detail::args<int, p1>;
using p3 = detail::args<detail::args<long>, detail::args<detail::args<p2> > >;
using p4 = detail::args<p0, p0, p0, long long, detail::args<detail::args<p3> > >;

BOOST_MPL2_ASSERT((std::is_same<forward<wrap, p0>::type, wrap<> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrap, p1>::type, wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrap, p2>::type, wrap<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrap, p3>::type, wrap<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrap, p4>::type, wrap<long long, long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<forward<wrap, long long, long, int, short, p0, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrap, long long, long, int, p1, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrap, long long, long, p2, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrap, long long, p3, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrap, p4, char>::type, wrap<long long, long, int, short, char> >));

int main()
{
    return 0;
}
