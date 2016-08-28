// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FRONT_HPP
#define METAL_LIST_FRONT_HPP

#include <metal/config.hpp>

#include <metal/list/at.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq>
    using front = metal::at<seq, metal::number<0>>;
}

#endif
