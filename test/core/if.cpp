// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/if.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using tautology = std::integral_constant<char, 'c'>;
using contradiction = std::integral_constant<unsigned long, 0UL>;

struct x;
struct y;
struct z;
struct w;

BOOST_MPL2_ASSERT((std::is_same<if_t<std::true_type, identity<x>, identity<y>>, x>));
BOOST_MPL2_ASSERT((std::is_same<if_t<std::false_type, identity<x>, identity<y>>, y>));

BOOST_MPL2_ASSERT((std::is_same<if_t<std::true_type, identity<x>, std::true_type, identity<y>, identity<z>>, x>));
BOOST_MPL2_ASSERT((std::is_same<if_t<std::false_type, identity<x>, std::true_type, identity<y>, identity<z>>, y>));
BOOST_MPL2_ASSERT((std::is_same<if_t<std::false_type, identity<x>, std::false_type, identity<y>, identity<z>>, z>));

BOOST_MPL2_ASSERT((std::is_same<if_t<std::true_type, identity<x>, std::true_type, identity<y>, std::true_type, identity<z>, identity<w>>, x>));
BOOST_MPL2_ASSERT((std::is_same<if_t<std::false_type, identity<x>, std::true_type, identity<y>, std::true_type, identity<z>, identity<w>>, y>));
BOOST_MPL2_ASSERT((std::is_same<if_t<std::false_type, identity<x>, std::false_type, identity<y>, std::true_type, identity<z>, identity<w>>, z>));
BOOST_MPL2_ASSERT((std::is_same<if_t<std::false_type, identity<x>, std::false_type, identity<y>, std::false_type, identity<z>, identity<w>>, w>));

BOOST_MPL2_ASSERT((if_<tautology, std::true_type, std::false_type>::type));
BOOST_MPL2_ASSERT((if_<contradiction, std::false_type, std::true_type>::type));

int main()
{
    return 0;
}
