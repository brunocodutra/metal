/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_ALGEBRA_ARITHMETIC_INC_HPP
#define METAL_ALGEBRA_ARITHMETIC_INC_HPP

#include <type_traits>

namespace metal
{
    template<typename x>
    struct inc :
            std::integral_constant<
                typename x::value_type,
                static_cast<typename x::value_type>(x::value + 1)
            >
    {};
}

#endif
