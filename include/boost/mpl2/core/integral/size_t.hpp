/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef BOOST_MPL2_CORE_INTEGRAL_SIZE_T_HPP
#define BOOST_MPL2_CORE_INTEGRAL_SIZE_T_HPP

#include <boost/mpl2/core/integral.hpp>

#include <cstddef>

namespace boost
{
    namespace mpl2
    {
        template<std::size_t constant>
        struct size_t_ :
                integral<std::size_t, constant>
        {};
    }
}

#endif
