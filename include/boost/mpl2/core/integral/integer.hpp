// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_INTEGRAL_INTEGER_HPP
#define BOOST_MPL2_CORE_INTEGRAL_INTEGER_HPP

#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/compat/template_alias.hpp>

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        template<short constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(short_, (integral<short, constant>));

        template<unsigned short constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(ushort_, (integral<unsigned short, constant>));

        template<int constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(int_, (integral<int, constant>));

        template<unsigned int constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(uint_, (integral<unsigned int, constant>));

        template<long constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(long_, (integral<long, constant>));

        template<unsigned long constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(ulong_, (integral<unsigned long, constant>));

#if !defined(BOOST_NO_LONG_LONG)
        template<long_long_type constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(long_long_, (integral<long_long_type, constant>));

        template<ulong_long_type constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(ulong_long_, (integral<ulong_long_type, constant>));
#endif
    }
}

#endif
