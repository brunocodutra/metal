// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_INTEGRAL_HPP
#define BOOST_MPL2_CORE_INTEGRAL_HPP

#include <boost/mpl2/core/arithmetic.hpp>

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename>
        struct integral_tag
        {
            typedef integral_tag type;
        };

        template<typename integral_type, integral_type constant>
        struct integral
        {
            typedef integral                    type;
            typedef integral_type               value_type;
            typedef integral_tag<value_type>    tag;

            BOOST_STATIC_CONSTEXPR value_type value = constant;

            typedef inc<type> next;
            typedef dec<type> prior;

            BOOST_CONSTEXPR operator value_type () const
            {
                return value;
            }
        };
    }
}

#include <boost/mpl2/core/integral/boolean.hpp>
#include <boost/mpl2/core/integral/character.hpp>
#include <boost/mpl2/core/integral/integer.hpp>
#include <boost/mpl2/core/integral/size_t.hpp>

#endif
