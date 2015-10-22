// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SLICE_HPP
#define METAL_LIST_SLICE_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<
        typename list,
        typename start,
        typename size,
        typename stride = integer<1>
    >
    struct slice
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref slice.
    template<
        typename list,
        typename start,
        typename size,
        typename stride = integer<1>
    >
    using slice_t = typename slice<list, start, size, stride>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/size.hpp>
#include <metal/list/swap.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/number/arithmetic/mod.hpp>

namespace metal
{
    template<typename list, typename t, t a, typename u, u b, typename v, v c>
    struct slice<list, number<t, a>, number<u, b>, number<v, c>> :
        swap<
            list,
            transform_t<
                enumerate_t<number<t, a>, number<u, b>, number<v, c>>,
                at<quote_t<list>, mod<_1, size<quote_t<list>>>>
            >
        >
    {};
}

#endif
