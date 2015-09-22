// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_SUB_HPP
#define METAL_NUMBER_ARITHMETIC_SUB_HPP

namespace metal
{
    /// \ingroup arithmetic
    /// \brief ...
    template<typename... nums>
    struct sub
    {};

    /// \ingroup arithmetic
    /// \brief Eager adaptor for \ref sub.
    template<typename... nums>
    using sub_t = typename sub<nums...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename x, x xv>
    struct sub<number<x, xv>> :
        number<x, xv>
    {};

    template<typename x, x xv, typename y, y yv, typename... nums>
    struct sub<number<x, xv>, number<y, yv>, nums...> :
        sub<number<decltype(xv - yv), xv - yv>, nums...>
    {};
}

#endif
