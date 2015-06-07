// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/algebra/if.hpp>

#include "test/main.hpp"

using namespace boost::metal;

using tautology = std::integral_constant<char, 'c'>;
using contradiction = std::integral_constant<unsigned long, 0UL>;

struct x {using type = x;};
struct y {using type = y;};
struct z {using type = z;};
struct w {using type = w;};

BOOST_METAL_ASSERT((std::is_same<if_t<std::true_type, x, y>, x>));
BOOST_METAL_ASSERT((std::is_same<if_t<std::false_type, x, y>, y>));

BOOST_METAL_ASSERT((std::is_same<if_t<std::true_type, x, std::true_type, y, z>, x>));
BOOST_METAL_ASSERT((std::is_same<if_t<std::false_type, x, std::true_type, y, z>, y>));
BOOST_METAL_ASSERT((std::is_same<if_t<std::false_type, x, std::false_type, y, z>, z>));

BOOST_METAL_ASSERT((std::is_same<if_t<std::true_type, x, std::true_type, y, std::true_type, z, w>, x>));
BOOST_METAL_ASSERT((std::is_same<if_t<std::false_type, x, std::true_type, y, std::true_type, z, w>, y>));
BOOST_METAL_ASSERT((std::is_same<if_t<std::false_type, x, std::false_type, y, std::true_type, z, w>, z>));
BOOST_METAL_ASSERT((std::is_same<if_t<std::false_type, x, std::false_type, y, std::false_type, z, w>, w>));

BOOST_METAL_ASSERT((if_<tautology, std::true_type, std::false_type>::type));
BOOST_METAL_ASSERT((if_<contradiction, std::false_type, std::true_type>::type));

