// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_INVARIANT_HPP
#define BOOST_MPL2_CORE_INVARIANT_HPP

#include <boost/mpl2/core/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename x>
        struct invariant
        {
            template<typename...>
            using type = identity<x>;
        };
    }
}

#endif
