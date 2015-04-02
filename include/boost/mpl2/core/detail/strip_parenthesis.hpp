// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_DETAIL_STRIP_PARENTHESIS_HPP
#define BOOST_MPL2_CORE_DETAIL_STRIP_PARENTHESIS_HPP

#include <boost/mpl2/core/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename>
            struct strip_parenthesis;

            template<typename x>
            struct strip_parenthesis<void (x)> :
                identity<x>
            {};
        }
    }
}

#define BOOST_MPL2_DETAIL_STRIP_PARENTHESIS(x) \
    boost::mpl2::detail::strip_parenthesis<void (x)>::type

#endif
