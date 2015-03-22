/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef BOOST_MPL2_CORE_COMPAT_DETAIL_NA_HPP
#define BOOST_MPL2_CORE_COMPAT_DETAIL_NA_HPP

#include <boost/mpl2/core/integral/boolean.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            // not available
            struct na;

            template<typename>
            struct is_na :
                    false_
            {};

            template<>
            struct is_na<na> :
                    true_
            {};

        }
    }
}

#endif
