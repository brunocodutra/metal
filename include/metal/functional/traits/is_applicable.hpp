// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_APPLICABLE_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_APPLICABLE_HPP

#include <metal/functional/apply.hpp>
#include <metal/functional/traits/is_just.hpp>

namespace metal
{
    /// \ingroup functional_traits
    /// \brief ...
    template<typename lambda, typename... args>
    struct is_applicable :
            is_just<apply<lambda, args...>>
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for \ref is_applicable.
    template<typename lambda, typename... args>
    using is_applicable_t = typename is_applicable<lambda, args...>::type;
}

#endif
