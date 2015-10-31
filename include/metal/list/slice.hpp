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
    struct slice;

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
#include <metal/list/copy.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/number/arithmetic/mod.hpp>

namespace metal
{
    template<typename list, typename st, typename sz, typename sd>
    struct slice :
        invoke<
            copy<
                quote_t<list>,
                transform<
                    enumerate<quote_t<st>, quote_t<sz>, quote_t<sd>>,
                    quote_t<at<quote_t<list>, mod<_1, size<quote_t<list>>>>>
                >
            >
        >
    {};
}

#endif
