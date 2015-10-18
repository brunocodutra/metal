// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_INC_HPP
#define METAL_NUMBER_ARITHMETIC_INC_HPP

namespace metal
{
    /// \ingroup arithmetic
    /// \brief ...
    template<typename num>
    struct inc
    {};

    /// \ingroup arithmetic
    /// \brief Eager adaptor for \ref inc.
    template<typename num>
    using inc_t = typename inc<num>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename t, t v>
    struct inc<number<t, v>> :
        number<t, v + 1>
    {};
}

#endif
