// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_PLACEHOLDERS_HPP
#define BOOST_MPL2_METAFUNCTIONAL_PLACEHOLDERS_HPP

#include <boost/mpl2/metafunctional/arg.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace placeholders
        {
            struct _;
            using _0 = arg<0>;
            using _1 = arg<1>;
            using _2 = arg<2>;
            using _3 = arg<3>;
            using _4 = arg<4>;
            using _5 = arg<5>;
            using _6 = arg<6>;
            using _7 = arg<7>;
            using _8 = arg<8>;
            using _9 = arg<9>;
        }

        using namespace ::boost::mpl2::placeholders;
    }
}

#endif
