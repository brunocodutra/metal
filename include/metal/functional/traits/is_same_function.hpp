// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_SAME_FUNCTION_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_SAME_FUNCTION_HPP

#include <metal/functional/traits/is_function.hpp>
#include <metal/functional/traits/is_same_expression.hpp>
#include <metal/algebra/logical/and.hpp>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct is_same_function_impl :
                is_same_expression<x::template call, y::template call>
        {};

    }

    template<typename x, typename y>
    struct is_same_function :
            and_<
                is_function<x>,
                is_function<y>,
                detail::is_same_function_impl<x, y>
            >
    {};

    template<typename x, typename y>
    using is_same_function_t = typename is_same_function<x, y>::type;
}

#endif
