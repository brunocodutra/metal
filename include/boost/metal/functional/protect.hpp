// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_PROTECT_HPP
#define BOOST_METAL_FUNCTIONAL_PROTECT_HPP

#include <type_traits>

namespace boost
{
    namespace metal
    {
        namespace detail
        {
            template<typename, typename = std::true_type>
            struct protect
            {};

            template<typename base>
            struct protect<base, typename std::is_class<base>::type> :
                    base
            {};
        }

        template<typename arg>
        struct protect :
                detail::protect<arg>
        {};
    }
}

#endif
