/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_DATATYPES_CHARACTER_HPP_
#define _BOOST_MPL2_DATATYPES_CHARACTER_HPP_

#include <boost/mpl2/datatypes/integral_concept.hpp>

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        template<char constant>
        struct char_ :
                integral_concept<char_<constant>, char, constant>
        {};

        template<unsigned char constant>
        struct uchar_ :
                integral_concept<uchar_<constant>, unsigned char, constant>
        {};

        template<signed char constant>
        struct schar_ :
                integral_concept<schar_<constant>, signed char, constant>
        {};

        template<wchar_t constant>
        struct wchar_t_ :
                integral_concept<wchar_t_<constant>, wchar_t, constant>
        {};

#if defined(BOOST_HAS_CHAR16_T)
        template<char16_t constant>
        struct char16_t_ :
                integral_concept<char16_t_<constant>, char16_t, constant>
        {};
#endif

#if defined(BOOST_HAS_CHAR16_T)
        template<char32_t constant>
        struct char32_t_ :
                integral_concept<char32_t_<constant>, char32_t, constant>
        {};
#endif
    }
}

#endif
