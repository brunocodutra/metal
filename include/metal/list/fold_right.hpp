// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FOLD_RIGHT_HPP
#define METAL_LIST_FOLD_RIGHT_HPP

#include <metal/config.hpp>

#include <metal/list/reverse.hpp>
#include <metal/list/fold_left.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq, typename state, typename lbd>
    using fold_right = metal::fold_left<metal::reverse<seq>, state, lbd>;
}

#endif
