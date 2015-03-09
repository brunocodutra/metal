/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_DATATYPES_INTEGRAL_HPP_
#define _BOOST_MPL2_DATATYPES_INTEGRAL_HPP_

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename>
        struct integral_tag;

        template<typename integral_type, integral_type constant>
        struct integral
        {
            typedef integral                    type;
            typedef integral_type               value_type;
            typedef integral_tag<value_type>    tag;

            enum {value = constant};

            typedef integral<value_type, static_cast<value_type>(value + 1)> next;
            typedef integral<value_type, static_cast<value_type>(value - 1)> prior;

            BOOST_CONSTEXPR operator value_type () const
            {
                return value;
            }
        };
    }
}

#endif
