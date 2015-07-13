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
        template<typename f1, typename f2>
        struct is_same_function_impl :
                is_same_expression<f1::template call, f2::template call>
        {};

    }

    template<typename f1, typename f2>
    struct is_same_function :
            and_<
                is_function<f1>,
                is_function<f2>,
                detail::is_same_function_impl<f1, f2>
            >
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for is_same_function.
    template<typename f1, typename f2>
    using is_same_function_t = typename is_same_function<f1, f2>::type;
}

#endif
