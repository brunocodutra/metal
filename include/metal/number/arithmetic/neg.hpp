// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_NEG_HPP
#define METAL_NUMBER_ARITHMETIC_NEG_HPP

#include <metal/number/number.hpp>
#include <metal/optional/extract.hpp>

namespace metal
{
    /// \ingroup arithmetic
    /// \brief ...
    template<typename num>
    struct neg
    {};

    /// \ingroup arithmetic
    /// \brief Eager adaptor for \ref neg.
    template<typename num>
    using neg_t = extract<neg<num>>;

    template<typename t, t v>
    struct neg<number<t, v>> :
            number<decltype(static_cast<t>(0) - v), static_cast<t>(0) - v>
    {};
}

#endif
