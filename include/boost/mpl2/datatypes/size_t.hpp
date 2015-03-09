/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_DATATYPES_SIZE_T_HPP_
#define _BOOST_MPL2_DATATYPES_SIZE_T_HPP_

#include <boost/mpl2/datatypes/integral.hpp>

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
