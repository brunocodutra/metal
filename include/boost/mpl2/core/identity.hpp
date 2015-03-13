/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_CORE_IDENTITY_HPP_
#define _BOOST_MPL2_CORE_IDENTITY_HPP_

namespace boost
{
    namespace mpl2
    {
        template<typename x>
        struct identity
        {
            typedef x type;
        };
    }
}

#endif
