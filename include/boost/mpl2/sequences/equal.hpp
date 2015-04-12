// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_EQUAL_HPP
#define BOOST_MPL2_SEQUENCES_EQUAL_HPP

#include <boost/mpl2/lambda/integral/boolean.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/sequences/tag.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        template<typename tagX, typename tagY>
        struct equal_impl
        {
            template<typename x, typename y>
            using call = bool_<std::is_same<x, y>::value>;
        };

        template<typename x, typename y>
        struct equal :
                call<equal_impl<typename tag<x>::type, typename tag<y>::type>, x, y>
        {};
    }
}

#endif
