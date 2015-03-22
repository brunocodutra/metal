/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef BOOST_MPL2_CORE_VOID_HPP
#define BOOST_MPL2_CORE_VOID_HPP

#include <boost/mpl2/core/integral/boolean.hpp>
#include <boost/mpl2/core/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        struct void_ :
                identity<void_>
        {};

        template<typename>
        struct is_void_ :
                false_
        {};

        template<>
        struct is_void_<void_> :
                true_
        {};

        template<typename>
        struct is_not_void_ :
                true_
        {};

        template<>
        struct is_not_void_<void_> :
                false_
        {};
    }
}

#endif
