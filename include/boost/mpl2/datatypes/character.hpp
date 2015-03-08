/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_DATATYPES_CHARACTER_HPP_
#define _BOOST_MPL2_DATATYPES_CHARACTER_HPP_

#include <boost/mpl2/datatypes/integral_c.hpp>

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        template<char constant>
        struct char_ :
                boost::mpl2::integral_c<char, constant>
        {};

        template<unsigned char constant>
        struct uchar_ :
                boost::mpl2::integral_c<unsigned char, constant>
        {};

        template<signed char constant>
        struct schar_ :
                boost::mpl2::integral_c<signed char, constant>
        {};

        template<wchar_t constant>
        struct wchar_t_ :
                boost::mpl2::integral_c<wchar_t, constant>
        {};

#if defined(BOOST_HAS_CHAR16_T)
        template<char16_t constant>
        struct char16_t_ :
                boost::mpl2::integral_c<char16_t, constant>
        {};
#endif

#if defined(BOOST_HAS_CHAR16_T)
        template<char32_t constant>
        struct char32_t_ :
                boost::mpl2::integral_c<char32_t, constant>
        {};
#endif
    }
}

#endif
