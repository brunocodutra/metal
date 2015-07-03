/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/algorithm/size.hpp>
#include <boost/metal/functional/traits/is_evaluable.hpp>

#include "test/integrals.hpp"
#include "test/main.hpp"

using namespace boost::metal;

namespace test
{
    struct sized
    {
        using size = test::three;
    };

    struct not_sized
    {
        using size = void;
    };

    struct size
    {};
}

BOOST_METAL_ASSERT((is_evaluable<size, test::sized>));
BOOST_METAL_ASSERT((not_<is_evaluable<size, test::not_sized>>));
BOOST_METAL_ASSERT((not_<is_evaluable<size, test::size>>));

BOOST_METAL_ASSERT((equal_to<size<test::sized>, test::three>));
