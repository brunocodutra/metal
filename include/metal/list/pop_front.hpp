// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_POP_FRONT_HPP
#define METAL_LIST_POP_FRONT_HPP

#include <metal/list/size.hpp>
#include <metal/list/slice.hpp>
#include <metal/number/if.hpp>
#include <metal/number/not.hpp>
#include <metal/number/sub.hpp>
#include <metal/number/cast.hpp>
#include <metal/number/less.hpp>
#include <metal/number/number.hpp>

#include <cstddef>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename n = metal::size_t<1>>
    using pop_front = slice<
        seq,
        n,
        if_<
            not_<less<size<seq>, cast<n, std::size_t>>>,
            sub<size<seq>, n>
        >
    >;
}

#endif
