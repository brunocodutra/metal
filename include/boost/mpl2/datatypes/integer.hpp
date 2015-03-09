/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_DATATYPES_INTEGER_HPP_
#define _BOOST_MPL2_DATATYPES_INTEGER_HPP_

#include <boost/mpl2/datatypes/integral.hpp>

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        template<short constant>
        struct short_ :
                boost::mpl2::integral<short, constant>
        {};

        template<unsigned short constant>
        struct ushort_ :
                boost::mpl2::integral<unsigned short, constant>
        {};

        template<int constant>
        struct int_ :
                boost::mpl2::integral<int, constant>
        {};

        template<unsigned int constant>
        struct uint_ :
                boost::mpl2::integral<unsigned int, constant>
        {};

        template<long constant>
        struct long_ :
                boost::mpl2::integral<long, constant>
        {};

        template<unsigned long constant>
        struct ulong_ :
                boost::mpl2::integral<unsigned long, constant>
        {};

#if defined(BOOST_HAS_LONG_LONG)
        template<long_long_type constant>
        struct long_long_ :
                boost::mpl2::integral<long_long_type, constant>
        {};

        template<ulong_long_type constant>
        struct ulong_long_ :
                boost::mpl2::integral<ulong_long_type, constant>
        {};
#endif
    }
}

#endif
