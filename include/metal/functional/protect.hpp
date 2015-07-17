// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_PROTECT_HPP
#define METAL_FUNCTIONAL_PROTECT_HPP

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename, typename = std::true_type, int = 0>
        struct protect_impl
        {
            using type = protect_impl;
        };

        template<typename value>
        struct protect_impl<value, typename std::is_class<value>::type, 0> :
                value
        {
            using type = protect_impl;
        };
    }

    template<typename null>
    using protect = detail::protect_impl<null>;
}

#endif
