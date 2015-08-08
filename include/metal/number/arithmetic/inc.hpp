// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_INC_HPP
#define METAL_NUMBER_ARITHMETIC_INC_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup arithmetic
    /// \brief ...
    template<typename n>
    struct inc;

    /// \ingroup arithmetic
    /// \brief Eager adaptor for \ref inc.
    template<typename n>
    using inc_t = typename inc<n>::type;

    template<typename n, n xv>
    struct inc<number<n, xv>> :
            number<n, static_cast<n>(xv + 1)>
    {};
}

#endif
