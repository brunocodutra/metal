// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/metafunctional/traits.hpp>

#include "test.hpp"

using namespace boost::mpl2;

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

BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, call<_0>::type>::type, test::wrap<> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, call<_0, short>::type>::type, test::wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, call<_0, short, int>::type>::type, test::wrap<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, call<_0, short, int, long>::type>::type, test::wrap<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, call<_0, short, int, long, long long>::type>::type, test::wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<call<_1, short, int, long, long long>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<call<_2, short, int, long, long long>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<call<_3, short, int, long, long long>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<call<_4, short, int, long, long long>::type, long long>));

BOOST_MPL2_ASSERT((std::is_same<detail::args<test::args0>::type, detail::args<> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<test::args1>::type, detail::args<short> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<test::args2>::type, detail::args<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<test::args3>::type, detail::args<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<test::args4>::type, detail::args<long long, long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<detail::args<long long, long, int, short, test::args0, char>::type, detail::args<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<long long, long, int, test::args1, char>::type, detail::args<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<long long, long, test::args2, char>::type, detail::args<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<long long, test::args3, char>::type, detail::args<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<detail::args<test::args4, char>::type, detail::args<long long, long, int, short, char> >));

int main()
{
    return 0;
}
