// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_DETAIL_FUNCTION_HPP
#define METAL_FUNCTIONAL_DETAIL_FUNCTION_HPP

#include <metal/functional/traits/is_function.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename, typename = std::true_type>
        struct function
        {
            template<typename...>
            struct call
            {};
        };

        template<typename func>
        struct function<func, is_function_t<func>> :
                func
        {};
    }
}

#endif
