// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_BACK_HPP
#define METAL_LIST_BACK_HPP

#include <metal/list/at.hpp>
#include <metal/list/size.hpp>
#include <metal/number/dec.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq>
    using back = metal::at<seq, metal::dec<metal::size<seq>>>;
}

#endif
