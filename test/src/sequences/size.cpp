// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/sequences/size.hpp>
#include <boost/mpl2/metafunctional/traits/is_evaluable.hpp>

#include "test/integrals.hpp"
#include "test/main.hpp"

using namespace boost::mpl2;

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

    template<typename...>
    struct size
    {};
}

BOOST_MPL2_ASSERT((is_evaluable<size, test::sized>));
BOOST_MPL2_ASSERT((not_<is_evaluable<size, test::not_sized> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<size, test::eponym<test::size>>>));

BOOST_MPL2_ASSERT((equal_to<size<test::sized>, test::three>));
