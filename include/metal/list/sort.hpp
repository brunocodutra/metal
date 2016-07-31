// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SORT_HPP
#define METAL_LIST_SORT_HPP

#include <metal/list/list.hpp>
#include <metal/list/merge.hpp>
#include <metal/list/transpose.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename lbd>
    using sort = metal::apply<
        metal::partial<metal::lambda<metal::merge>, lbd, metal::list<>>,
        metal::transpose<metal::list<seq>>
    >;
}

#endif
