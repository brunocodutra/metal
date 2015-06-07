// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/sequences/size.hpp>

#include "test/integrals.hpp"
#include "test/main.hpp"

using namespace boost::mpl2;

struct sized
{
    using size = test::three;
};

BOOST_MPL2_ASSERT((equal_to<size<sized>, test::three>));
BOOST_MPL2_ASSERT((equal_to<size_t<sized>, test::three>));

BOOST_MPL2_ASSERT((std::is_same<size_t<sized>, test::three>));
