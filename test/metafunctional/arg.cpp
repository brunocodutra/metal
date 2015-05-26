// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/metafunctional/traits.hpp>
#include <boost/mpl2/core/logical/not.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using p0 = detail::args<detail::args<>, detail::args<detail::args<>, detail::args<>, detail::args<> > >;
using p1 = detail::args<p0, short, p0>;
using p2 = detail::args<int, p1>;
using p3 = detail::args<detail::args<long>, detail::args<detail::args<p2> > >;
using p4 = detail::args<p0, p0, p0, long long, detail::args<detail::args<p3> > >;

BOOST_MPL2_ASSERT(is_evaluable<_0>);
BOOST_MPL2_ASSERT(is_evaluable<_1>);
BOOST_MPL2_ASSERT(is_evaluable<_2>);
BOOST_MPL2_ASSERT(is_evaluable<_3>);
BOOST_MPL2_ASSERT(is_evaluable<_4>);

BOOST_MPL2_ASSERT(is_function<_0>);
BOOST_MPL2_ASSERT(is_function<_1>);
BOOST_MPL2_ASSERT(is_function<_2>);
BOOST_MPL2_ASSERT(is_function<_3>);
BOOST_MPL2_ASSERT(is_function<_4>);

BOOST_MPL2_ASSERT((is_callable<_0, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<_1, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<_2, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<_3, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<_4, short, int, long, long long>));

BOOST_MPL2_ASSERT((is_callable<_0>));
BOOST_MPL2_ASSERT((not_<is_callable<_1> >));
BOOST_MPL2_ASSERT((not_<is_callable<_2, int> >));
BOOST_MPL2_ASSERT((not_<is_callable<_3, int, long> >));
BOOST_MPL2_ASSERT((not_<is_callable<_4, int, long, long long> >));

template<typename... args>
struct wrap
{
    using type = wrap<args...>;
};

struct wrapper
{
    template<typename... args>
    using call = wrap<args...>;
};

BOOST_MPL2_ASSERT((std::is_same<call<wrapper, call<_0>::type>::type, wrap<> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, call<_0, short>::type>::type, wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, call<_0, short, int>::type>::type, wrap<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, call<_0, short, int, long>::type>::type, wrap<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, call<_0, short, int, long, long long>::type>::type, wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<call<_1, short, int, long, long long>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<call<_2, short, int, long, long long>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<call<_3, short, int, long, long long>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<call<_4, short, int, long, long long>::type, long long>));

BOOST_MPL2_ASSERT((std::is_same<detail::args<p0>::type, detail::args<> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<p1>::type, detail::args<short> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<p2>::type, detail::args<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<p3>::type, detail::args<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<p4>::type, detail::args<long long, long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<detail::args<long long, long, int, short, p0, char>::type, detail::args<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<long long, long, int, p1, char>::type, detail::args<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<long long, long, p2, char>::type, detail::args<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<long long, p3, char>::type, detail::args<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<p4, char>::type, detail::args<long long, long, int, short, char> >));

int main()
{
    return 0;
}
