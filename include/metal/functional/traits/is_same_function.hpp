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
        template<typename func1, typename func2>
        struct is_same_function_impl :
                is_same_expression<func1::template call, func2::template call>
        {};

    }

    /// \ingroup functional_traits
    /// \brief ...
    template<typename func1, typename func2>
    struct is_same_function :
            and_<
                is_function<func1>,
                is_function<func2>,
                detail::is_same_function_impl<func1, func2>
            >
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for \ref is_same_function.
    template<typename func1, typename func2>
    using is_same_function_t = typename is_same_function<func1, func2>::type;
}

#endif
