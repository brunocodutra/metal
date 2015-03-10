/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_SEQUENCES_SEQUENCE_HPP_
#define _BOOST_MPL2_SEQUENCES_SEQUENCE_HPP_

namespace boost
{
    namespace mpl2
    {
        struct nil
        {
            typedef nil type;
            enum {size = 0U};
        };

        template<typename head, typename tail>
        struct sequence :
                tail::type
        {
            typedef sequence type;
            enum {size = 1U + tail::size};
        };

    }
}

#endif
