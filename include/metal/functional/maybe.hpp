// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_MAYBE_HPP
#define METAL_FUNCTIONAL_MAYBE_HPP

#include <metal/functional/traits/is_nothing.hpp>
#include <metal/algebra/logical/or.hpp>
#include <metal/algebra/logical/not.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename, typename = std::false_type>
        struct maybe_impl
        {};

        template<typename value>
        struct maybe_impl<value, not_t<std::is_class<value>>> :
                value
        {};

        template<typename value>
        struct maybe_impl<value, or_t<std::is_class<value>, is_nothing<value>>>
        {
            using type = typename value::type;
        };
    }

    template<typename value>
    struct maybe :
            detail::maybe_impl<value>
    {};
}

#endif
