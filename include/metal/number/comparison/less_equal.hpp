// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_COMPARISON_LESS_EQUAL_HPP
#define METAL_NUMBER_COMPARISON_LESS_EQUAL_HPP

#include <metal/number/number.hpp>

namespace metal
{
    template<typename x, typename y>
    struct less_equal;

    template<typename x, x xv, typename y, y yv>
    struct less_equal<number<x, xv>, number<y, yv>> :
            boolean<(xv <= yv)>
    {};
}

#endif
