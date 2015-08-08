// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_INC_HPP
#define METAL_NUMBER_ARITHMETIC_INC_HPP

#include <metal/number/number.hpp>

namespace metal
{
    template<typename x>
    struct inc;

    template<typename x>
    using inc_t = typename inc<x>::type;

    template<typename x, x xv>
    struct inc<number<x, xv>> :
            number<x, static_cast<x>(xv + 1)>
    {};
}

#endif
