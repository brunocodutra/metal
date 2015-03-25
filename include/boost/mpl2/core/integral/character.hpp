// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_INTEGRAL_CHARACTER_HPP
#define BOOST_MPL2_CORE_INTEGRAL_CHARACTER_HPP

#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/compat/alias.hpp>

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        template<char constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(char_, (integral<char, constant>));

        template<unsigned char constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(uchar_, (integral<unsigned char, constant>));

        template<signed char constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(schar_, (integral<signed char, constant>));

        template<wchar_t constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(wchar_t_, (integral<wchar_t, constant>));

#if !defined(BOOST_NO_CXX11_CHAR16_T)
        template<char16_t constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(char16_t_, (integral<char16_t, constant>));
#endif

#if !defined(BOOST_NO_CXX11_CHAR32_T)
        template<char32_t constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(char32_t_, (integral<char32_t, constant>));
#endif
    }
}

#endif
