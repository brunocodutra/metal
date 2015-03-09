/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_DATATYPES_INTEGRAL_CONCEPT_HPP_
#define _BOOST_MPL2_DATATYPES_INTEGRAL_CONCEPT_HPP_

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        struct integral_tag;

        template<typename model, typename integral, integral constant>
        struct integral_concept
        {
            typedef integral_tag    tag;
            typedef model           type;
            typedef integral        value_type;

            enum {value = constant};

            typedef integral_concept<model, value_type, static_cast<value_type>(value + 1)> next;
            typedef integral_concept<model, value_type, static_cast<value_type>(value - 1)> prior;

            BOOST_CONSTEXPR operator value_type () const
            {
                return value;
            }
        };
}
}

#endif
