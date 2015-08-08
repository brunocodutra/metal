// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_NOT_HPP
#define METAL_NUMBER_LOGICAL_NOT_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup logical
    /// \brief ...
    template<typename n>
    struct not_;

    /// \ingroup logical
    /// \brief Eager adaptor for \ref not_.
    template<typename value>
    using not_t = typename not_<value>::type;

    template<typename t, t v>
    struct not_<number<t, v>> :
            boolean<!number<t, v>::value>
    {};
}

#endif
