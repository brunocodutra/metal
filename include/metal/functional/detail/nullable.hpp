// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_DETAIL_NULLABLE_HPP
#define METAL_FUNCTIONAL_DETAIL_NULLABLE_HPP

#include <metal/functional/traits/is_nil.hpp>
#include <metal/algebra/logical/or.hpp>
#include <metal/algebra/logical/not.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename, typename = std::false_type>
        struct nullable
        {};

        template<typename value>
        struct nullable<value, not_t<std::is_class<value>>> :
                value
        {};

        template<typename value>
        struct nullable<value, or_t<std::is_class<value>, is_nil<value>>>
        {
            using type = typename value::type;
        };
    }
}

#endif
