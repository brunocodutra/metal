/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_SEQUENCES_DETAIL_REF_HPP_
#define _BOOST_MPL2_SEQUENCES_DETAIL_REF_HPP_

#include <boost/mpl2/preprocessor/args.hpp>
#include <boost/mpl2/core/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<BOOST_MPL2_OPTIONAL_PARAMS(1, value)>
            struct ref :
                    identity<BOOST_MPL2_ARGS(1, value)>
            {};

            //NULL
            template<>
            struct ref<>;
        }
    }
}

#endif
