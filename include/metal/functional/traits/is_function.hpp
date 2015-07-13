// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_FUNCTION_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_FUNCTION_HPP

#include <metal/functional/traits/is_strict.hpp>
#include <metal/functional/traits/is_same_expression.hpp>
#include <metal/algebra/logical/and.hpp>
#include <metal/algebra/logical/not.hpp>
#include <metal/core/introspection.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        METAL_DEFINE_NESTED_TYPE_TRAIT(has_call, call);
        METAL_DEFINE_NESTED_TEMPLATE_TRAIT(has_template_call, call);

        template<typename value>
        struct is_function_impl :
                is_same_expression<
                    value::type::template call,
                    value::template call
                >
        {};
    }

    template<typename value>
    struct is_function :
            and_<
                is_strict<value>,
                detail::has_template_call<value>,
                not_<detail::has_call<value>>,
                detail::is_function_impl<value>
            >
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for is_function.
    template<typename value>
    using is_function_t = typename is_function<value>::type;
}

#endif
