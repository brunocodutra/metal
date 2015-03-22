/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef BOOST_MPL2_CORE_ARITHMETIC_INC_HPP
#define BOOST_MPL2_CORE_ARITHMETIC_INC_HPP

#include <boost/mpl2/core/tag.hpp>
#include <boost/mpl2/core/integral_fwd.hpp>
#include <boost/mpl2/core/arithmetic/negate.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename tag>
        struct inc_impl;

        template<typename type>
        struct inc_impl<integral_tag<type> >
        {
            template<typename n>
            struct apply :
                    integral<
                        typename n::value_type,
                        static_cast<typename n::value_type>(n::value + 1)
                    >
            {};
        };

        template<>
        struct inc_impl<integral_tag<bool> >
        {
            template<typename n>
            struct apply :
                    negate<n>
            {};
        };

        template<typename n>
        struct inc :
                inc_impl<typename tag<n>::type>::template apply<n>
        {};
    }
}

#endif
