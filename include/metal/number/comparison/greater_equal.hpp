// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_COMPARISON_GREATER_EQUAL_HPP
#define METAL_NUMBER_COMPARISON_GREATER_EQUAL_HPP

#include <type_traits>

namespace metal
{
    template<typename x, typename y>
    struct greater_equal :
            std::integral_constant<bool, (x::value >= y::value)>
    {};
}

#endif
