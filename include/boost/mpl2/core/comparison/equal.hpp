// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_COMPARISON_EQUAL_HPP
#define BOOST_MPL2_CORE_COMPARISON_EQUAL_HPP

#include <boost/mpl2/core/tag.hpp>
#include <boost/mpl2/core/integral_fwd.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename tagX, typename tagY>
        struct equal_impl;

        template<typename typeX, typename typeY>
        struct equal_impl<integral_tag<typeX>, integral_tag<typeY> >
        {
            template<typename x, typename y>
            struct apply :
                    integral<bool, x::value == y::value>
            {};
        };

        template<typename x, typename y>
        struct equal :
                equal_impl<typename tag<x>::type, typename tag<y>::type>::template apply<x, y>
        {};
    }
}

#endif
