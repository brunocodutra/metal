// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_NEG_HPP
#define METAL_NUMBER_ARITHMETIC_NEG_HPP

#include <metal/number/number.hpp>

namespace metal
{
    template<typename x>
    struct neg;

    template<typename x>
    using neg_t = typename neg<x>::type;

    template<typename x, x xv>
    struct neg<number<x, xv>> :
            number<decltype(-number<x, xv>::value), -number<x, xv>::value>
    {};
}

#endif
