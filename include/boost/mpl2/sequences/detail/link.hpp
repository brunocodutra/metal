/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_SEQUENCES_DETAIL_LINK_HPP_
#define _BOOST_MPL2_SEQUENCES_DETAIL_LINK_HPP_

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            struct nil
            {
                enum {size = 0U};
            };

            template<typename key, typename value, typename rest>
            struct link :
                    rest::type
            {
                enum {size = 1U + rest::size};
            };
        }
    }
}

#endif
