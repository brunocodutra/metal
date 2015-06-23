// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_PROTECT_HPP
#define BOOST_METAL_FUNCTIONAL_PROTECT_HPP

#include <boost/metal/functional/traits/is_function.hpp>

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

            template<typename function>
            struct protect<function, is_function_t<function>> :
                    function
            {};
        }

        template<typename arg>
        struct protect :
                detail::protect<arg>
        {
            using type = protect;
        };
    }
}

#endif
