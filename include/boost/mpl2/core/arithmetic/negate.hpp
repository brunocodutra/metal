// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_ARITHMETIC_NEGATE_HPP
#define BOOST_MPL2_CORE_ARITHMETIC_NEGATE_HPP

#include <boost/mpl2/core/arithmetic/detail/unary.hpp>

namespace boost
{
    namespace mpl2
    {
        BOOST_MPL2_DETAIL_DEFINE_UNARY_ARITHMETIC_OPERATION(negate, -);
    }
}

#endif
