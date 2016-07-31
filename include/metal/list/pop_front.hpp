// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_POP_FRONT_HPP
#define METAL_LIST_POP_FRONT_HPP

#include <metal/list/size.hpp>
#include <metal/list/range.hpp>
#include <metal/number/number.hpp>

#include <cstddef>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename n = size_t<1>>
    using pop_front = metal::range<seq, n, metal::size<seq>>;
}

#endif
