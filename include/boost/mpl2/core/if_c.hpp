/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef BOOST_MPL2_CORE_IF_C_HPP
#define BOOST_MPL2_CORE_IF_C_HPP

namespace boost
{
    namespace mpl2
    {
        template<bool cond, typename yes, typename no>
        struct if_c :
                yes
        {};

        template<typename yes, typename no>
        struct if_c<false, yes, no> :
                no
        {};
    }
}

#endif
