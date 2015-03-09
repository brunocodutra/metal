/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_DATATYPES_INTEGER_HPP_
#define _BOOST_MPL2_DATATYPES_INTEGER_HPP_

#include <boost/mpl2/datatypes/integral_concept.hpp>

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        template<short constant>
        struct short_ :
                integral_concept<short_<constant>, short, constant>
        {};

        template<unsigned short constant>
        struct ushort_ :
                integral_concept<ushort_<constant>, unsigned short, constant>
        {};

        template<int constant>
        struct int_ :
                integral_concept<int_<constant>, int, constant>
        {};

        template<unsigned int constant>
        struct uint_ :
                integral_concept<uint_<constant>, unsigned int, constant>
        {};

        template<long constant>
        struct long_ :
                integral_concept<long_<constant>, long, constant>
        {};

        template<unsigned long constant>
        struct ulong_ :
                integral_concept<ulong_<constant>, unsigned long, constant>
        {};

#if defined(BOOST_HAS_LONG_LONG)
        template<long_long_type constant>
        struct long_long_ :
                integral_concept<long_long_<constant>, long_long_type, constant>
        {};

        template<ulong_long_type constant>
        struct ulong_long_ :
                integral_concept<ulong_long_<constant>, ulong_long_type, constant>
        {};
#endif
    }
}

#endif
