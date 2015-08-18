// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_INC_HPP
#define METAL_NUMBER_ARITHMETIC_INC_HPP

#include <metal/number/number.hpp>
#include <metal/optional/extract.hpp>

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
    using inc_t = extract<inc<num>>;

    template<typename t, t v>
    struct inc<number<t, v>> :
            number<t, static_cast<t>(v + 1)>
    {};
}

#endif
