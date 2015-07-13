// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_NIL_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_NIL_HPP

#include <metal/algebra/logical/not.hpp>
#include <metal/algebra/logical/and.hpp>
#include <metal/detail/introspection.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        METAL_DEFINE_NESTED_TYPE_TRAIT(has_type, type);
    }

    template<typename value>
    struct is_nil :
            not_<and_<std::is_class<value>, detail::has_type<value>>>
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for is_nil.
    template<typename value>
    using is_nil_t = typename is_nil<value>::type;
}

#endif
