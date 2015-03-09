/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_DATATYPES_INTEGRAL_HPP_
#define _BOOST_MPL2_DATATYPES_INTEGRAL_HPP_

#include <boost/mpl2/datatypes/integral_concept.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename integer, integer constant>
        struct integral :
                integral_concept<integral<integer, constant>, integer, constant>
        {};
    }
}

#endif
