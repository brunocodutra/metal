// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_EQUAL_HPP
#define BOOST_MPL2_CORE_EQUAL_HPP

#include <boost/mpl2/core/tag.hpp>
#include <boost/mpl2/core/integral/boolean.hpp>
#include <boost/mpl2/core/compat/alias.hpp>

#include <boost/type_traits/is_same.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename x, typename y>
            BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(is_same, (bool_<boost::is_same<x, y>::type::value>));
        }

        template<typename tagX, typename tagY>
        struct equal_impl
        {
            template<typename x, typename y>
            BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(apply, (detail::is_same<x, y>));
        };

        template<typename x, typename y>
        struct equal :
                equal_impl<typename tag<x>::type, typename tag<y>::type>::template apply<x, y>
        {};
    }
}

#endif
