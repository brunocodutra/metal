/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_LEGACY_SIZE_T_HPP_
#define _BOOST_MPL2_LEGACY_SIZE_T_HPP_

#include <boost/mpl2/datatypes/size_t.hpp>

namespace boost
{
    namespace mpl
    {
        template<std::size_t constant>
        struct size_t :
                boost::mpl2::size_t_<constant>
        {};
    }
}

#endif
