// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_NOT_HPP
#define METAL_NUMBER_LOGICAL_NOT_HPP

namespace metal
{
    /// \ingroup logical
    /// ...
    template<typename num>
    struct not_
    {};

    /// \ingroup logical
    /// Eager adaptor for \ref not_.
    template<typename num>
    using not_t = typename metal::not_<num>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename t, t v>
    struct not_<number<t, v>> :
        boolean<v ? false : true>
    {};
}

#endif
