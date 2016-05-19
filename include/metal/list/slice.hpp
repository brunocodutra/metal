// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SLICE_HPP
#define METAL_LIST_SLICE_HPP

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename = integer<1>>
        struct slice;
    }

    /// \ingroup list
    /// ...
    template<
        typename list,
        typename start,
        typename size,
        typename stride = integer<1>
    >
    using slice = detail::slice<list, start, size, stride>;

    /// \ingroup list
    /// Eager adaptor for metal::slice.
    template<
        typename list,
        typename start,
        typename size,
        typename stride = integer<1>
    >
    using slice_t = typename metal::slice<list, start, size, stride>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/size.hpp>
#include <metal/list/copy.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/enumerate.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename start, typename size, typename stride>
        struct slice
        {};

        template<typename list, typename t, t a, typename u, u b, typename v, v c>
        struct slice<list, number<t, a>, number<u, b>, number<v, c>> :
            invoke<
                copy<_1, transform<_2, _3>>,
                list,
                at<quote_t<list>, _1>,
                enumerate_t<number<t, a>, number<u, b>, number<v, c>>
            >
        {};
    }
}

#endif
