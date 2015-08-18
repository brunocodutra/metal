// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_ENUMERATE_HPP
#define METAL_SEQUENCE_ENUMERATE_HPP

#include <metal/sequence/range.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup sequence
    /// \brief ...
    template<typename n>
    struct enumerate
    {};

    /// \ingroup optional
    /// \brief Eager adaptor for \ref enumerate.
    template<typename n>
    using enumerate_t = extract<metal::enumerate<n>>;

    template<typename t, t v>
    struct enumerate<number<t, v>> :
            range<number<t, 0>, number<t, v>>
    {};
}

#endif
