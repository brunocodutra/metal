// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_INTEGRAL_HPP
#define BOOST_MPL2_CORE_INTEGRAL_HPP

#include <boost/mpl2/core/compat/static_constant.hpp>

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

            BOOST_MPL2_DEFINE_STATIC_CONSTANT(value_type, value = constant);

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
