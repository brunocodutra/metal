// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/if.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using boost::mpl2::if_;
using boost::mpl2::identity;
using boost::mpl2::true_;
using boost::mpl2::false_;

using tautology = boost::mpl2::char_<'c'>;
using contradiction = boost::mpl2::ulong_<0UL>;

struct x;
struct y;
struct z;
struct w;

BOOST_MPL2_ASSERT((std::is_same<if_<true_, identity<x>, identity<y> >::type, x>));
BOOST_MPL2_ASSERT((std::is_same<if_<false_, identity<x>, identity<y> >::type, y>));

BOOST_MPL2_ASSERT((std::is_same<if_<true_, identity<x>, true_, identity<y>, identity<z> >::type, x>));
BOOST_MPL2_ASSERT((std::is_same<if_<false_, identity<x>, true_, identity<y>, identity<z> >::type, y>));
BOOST_MPL2_ASSERT((std::is_same<if_<false_, identity<x>, false_, identity<y>, identity<z> >::type, z>));

BOOST_MPL2_ASSERT((std::is_same<if_<true_, identity<x>, true_, identity<y>, true_, identity<z>, identity<w> >::type, x>));
BOOST_MPL2_ASSERT((std::is_same<if_<false_, identity<x>, true_, identity<y>, true_, identity<z>, identity<w> >::type, y>));
BOOST_MPL2_ASSERT((std::is_same<if_<false_, identity<x>, false_, identity<y>, true_, identity<z>, identity<w> >::type, z>));
BOOST_MPL2_ASSERT((std::is_same<if_<false_, identity<x>, false_, identity<y>, false_, identity<z>, identity<w> >::type, w>));

BOOST_MPL2_ASSERT((if_<tautology, true_, false_>::type));
BOOST_MPL2_ASSERT((if_<contradiction, false_, true_>::type));

int main()
{
    return 0;
}
