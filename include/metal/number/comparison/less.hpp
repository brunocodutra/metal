// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_COMPARISON_LESS_HPP
#define METAL_NUMBER_COMPARISON_LESS_HPP

namespace metal
{
    /// \ingroup comparison
    /// \brief ...
    template<typename x, typename y>
    struct less
    {};

    /// \ingroup comparison
    /// \brief Eager adaptor for \ref less.
    template<typename x, typename y>
    using less_t = typename less<x, y>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename x, x xv, typename y, y yv>
    struct less<number<x, xv>, number<y, yv>> :
        boolean<(xv < yv)>
    {};
}

#endif
