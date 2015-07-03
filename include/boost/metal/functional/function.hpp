// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_FUNCTION_HPP
#define BOOST_METAL_FUNCTIONAL_FUNCTION_HPP

#include <boost/metal/functional/traits/is_function.hpp>

#include <type_traits>

namespace boost
{
    namespace metal
    {
        namespace detail
        {
            template<typename, typename = std::true_type, int = 0>
            struct function
            {
                using type = function;

                template<typename...>
                struct call
                {};
            };

            template<typename func>
            struct function<func, is_function_t<func>, 0> :
                    func
            {
                using type = function;
            };
        }

        template<typename func>
        using function = detail::function<func>;
    }
}

#endif
