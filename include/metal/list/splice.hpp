// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SPLICE_HPP
#define METAL_LIST_SPLICE_HPP

#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/list/pop_back.hpp>
#include <metal/list/pop_front.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/number/number.hpp>
#include <metal/number/sub.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename n, typename other>
    using splice = copy<
        seq,
        join<
            pop_back<apply<lambda<list>, seq>, sub<size<seq>, n>>,
            apply<lambda<list>, other>,
            pop_front<apply<lambda<list>, seq>, n>
        >
    >;
}

#endif
