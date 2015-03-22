// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_VOID_HPP
#define BOOST_MPL2_CORE_VOID_HPP

#include <boost/mpl2/core/integral/boolean.hpp>
#include <boost/mpl2/core/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        struct void_ :
                identity<void_>
        {};

        template<typename>
        struct is_void_ :
                false_
        {};

        template<>
        struct is_void_<void_> :
                true_
        {};

        template<typename>
        struct is_not_void_ :
                true_
        {};

        template<>
        struct is_not_void_<void_> :
                false_
        {};
    }
}

#endif
