/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_CORE_REF_HPP_
#define _BOOST_MPL2_CORE_REF_HPP_

#include <boost/mpl2/compat/numbered.hpp>
#include <boost/mpl2/core/identity.hpp>

namespace boost
{
    namespace mpl2
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

#endif
