// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_NIL_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_NIL_HPP

#include <metal/core/introspection.hpp>
#include <metal/algebra/logical/not.hpp>

namespace metal
{
    namespace detail
    {
        METAL_DEFINE_NESTED_TYPE_TRAIT(has_type, type);
    }

    template<typename x>
    struct is_nil :
            not_<detail::has_type<x>>
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for is_nil.
    template<typename x>
    using is_nil_t = typename is_nil<x>::type;
}

#endif
