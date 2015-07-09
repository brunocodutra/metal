// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_FUNCTION_HPP
#define METAL_FUNCTIONAL_FUNCTION_HPP

#include <metal/functional/traits/is_function.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename, typename = std::true_type, int = 0>
        struct function_impl
        {
            using type = function_impl;

            template<typename...>
            struct call
            {};
        };

        template<typename func>
        struct function_impl<func, is_function_t<func>, 0> :
                func
        {
            using type = function_impl;
        };
    }

    template<typename func>
    using function = detail::function_impl<func>;
}

#endif
