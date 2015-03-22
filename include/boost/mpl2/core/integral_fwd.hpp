// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_INTEGRAL_FWD_HPP
#define BOOST_MPL2_CORE_INTEGRAL_FWD_HPP

namespace boost
{
    namespace mpl2
    {
        template<typename>
        struct integral_tag;

        template<typename integral_type, integral_type constant>
        struct integral;
    }
}

#endif
