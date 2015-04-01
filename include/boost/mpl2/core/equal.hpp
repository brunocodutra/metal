// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_EQUAL_HPP
#define BOOST_MPL2_CORE_EQUAL_HPP

#include <boost/mpl2/core/tag.hpp>
#include <boost/mpl2/core/integral/boolean.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename x, typename y>
            using is_same = bool_<std::is_same<x, y>::type::value>;
        }

        template<typename tagX, typename tagY>
        struct equal_impl
        {
            template<typename x, typename y>
            using apply = detail::is_same<x, y>;
        };

        template<typename x, typename y>
        struct equal :
                equal_impl<typename tag<x>::type, typename tag<y>::type>::template apply<x, y>
        {};
    }
}

#endif
