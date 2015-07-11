// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_STRICT_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_STRICT_HPP

#include <metal/functional/traits/is_nil.hpp>
#include <metal/algebra/logical/not.hpp>
#include <metal/algebra/logical/and.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename x>
        struct is_strict_impl :
                std::is_base_of<typename x::type, x>
        {};
    }

    template<typename x>
    struct is_strict :
            and_<
                not_<is_nil<x>>,
                detail::is_strict_impl<x>
            >
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for is_strict.
    template<typename x>
    using is_strict_t = typename is_nil<x>::type;
}

#endif
