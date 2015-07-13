// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_DETAIL_NULLABLE_HPP
#define METAL_FUNCTIONAL_DETAIL_NULLABLE_HPP

#include <metal/functional/traits/is_nil.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename, typename = std::false_type>
        struct nullable
        {};

        template<typename null>
        struct nullable<null, is_nil_t<null>> :
                null
        {};

    }
}

#endif
