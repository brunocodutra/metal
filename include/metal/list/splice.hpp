// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SPLICE_HPP
#define METAL_LIST_SPLICE_HPP

#include <metal/config.hpp>

#include <metal/list/join.hpp>
#include <metal/list/drop.hpp>
#include <metal/list/take.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq, typename n, typename other>
    using splice = metal::join<metal::take<seq, n>, other, metal::drop<seq, n>>;
}

#endif
