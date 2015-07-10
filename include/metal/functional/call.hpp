// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_CALL_HPP
#define METAL_FUNCTIONAL_CALL_HPP

#include <metal/functional/eval.hpp>
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

    template<typename func, typename... args>
    struct call :
            eval<detail::function<func>::template call, args...>
    {};

    template<typename... args>
    using call_t = typename call<args...>::type;
}

#endif
