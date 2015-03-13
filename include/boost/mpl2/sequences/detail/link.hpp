/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_SEQUENCES_DETAIL_LINK_HPP_
#define _BOOST_MPL2_SEQUENCES_DETAIL_LINK_HPP_

#include <boost/mpl2/core/integral/size_t.hpp>
#include <boost/mpl2/core/arithmetic/inc.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            struct nil
            {
                typedef size_t_<0U> size;
            };

            template<typename key, typename value, typename rest>
            struct link :
                    rest::type
            {
                typedef inc<typename rest::size> size;
            };
        }
    }
}

#endif
