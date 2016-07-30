// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SPLICE_HPP
#define METAL_LIST_SPLICE_HPP

#include <metal/list/join.hpp>
#include <metal/list/pop_back.hpp>
#include <metal/list/pop_front.hpp>
#include <metal/number/sub.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename n, typename other>
    using splice = join<
        pop_back<seq, sub<size<seq>, n>>, other, pop_front<seq, n>
    >;
}

#endif
