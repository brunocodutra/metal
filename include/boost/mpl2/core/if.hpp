/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef BOOST_MPL2_CORE_IF_HPP
#define BOOST_MPL2_CORE_IF_HPP

#include <boost/mpl2/core/if_c.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename cond, typename yes, typename no>
        struct if_ :
                if_c<cond::type::value ? true : false, yes, no>
        {};
    }
}

#endif
