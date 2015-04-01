// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_DETAIL_NA_HPP
#define BOOST_MPL2_CORE_DETAIL_NA_HPP

#include <boost/mpl2/core/integral/boolean.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            // not available
            struct na;

            template<typename>
            struct is_na :
                    false_
            {};

            template<>
            struct is_na<na> :
                    true_
            {};

        }
    }
}

#endif
