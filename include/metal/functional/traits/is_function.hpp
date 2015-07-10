// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_FUNCTION_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_FUNCTION_HPP

#include <metal/functional/traits/is_nil.hpp>
#include <metal/functional/traits/is_same_expression.hpp>
#include <metal/core/introspection.hpp>
#include <metal/algebra/logical/or.hpp>
#include <metal/algebra/logical/and.hpp>
#include <metal/algebra/logical/not.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        METAL_DEFINE_NESTED_TYPE_TRAIT(has_call, call);
        METAL_DEFINE_NESTED_TEMPLATE_TRAIT(has_template_call, call);

        template<typename func, typename = std::true_type>
        struct is_function_impl :
                and_<
                    std::is_base_of<typename func::type, func>,
                    is_same_expression<
                        func::type::template call,
                        func::template call
                    >
                >
        {};
    }

    template<typename func>
    struct is_function :
            and_<
                not_<is_nil<func>>,
                detail::has_template_call<func>,
                not_<detail::has_call<func>>,
                detail::is_function_impl<func>
            >
    {};

    template<typename func>
    using is_function_t = typename is_function<func>::type;
}

#endif
