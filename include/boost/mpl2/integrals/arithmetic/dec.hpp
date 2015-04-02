// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_INTEGRALS_ARITHMETIC_DEC_HPP
#define BOOST_MPL2_INTEGRALS_ARITHMETIC_DEC_HPP

#include <boost/mpl2/integrals/integral.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename x>
        using dec = integral<
            typename x::value_type,
            static_cast<typename x::value_type>(x::value - 1)
        >;
    }
}

#endif
