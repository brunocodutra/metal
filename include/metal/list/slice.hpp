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
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/number/arithmetic/mod.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename list, typename start, typename size, typename stride,
            typename = boolean<true>
        >
        struct slice_impl
        {};

        template<
            typename list,
            typename t, t a, typename u, u b, typename v, v c
        >
        struct slice_impl<list, number<t, a>, number<u, b>, number<v, c>,
            boolean<(size_t<list>::value > 0)>
        > :
            copy<
                list,
                transform_t<
                    at<quote_t<list>, mod<_1, size_t<list>>>,
                    enumerate_t<number<t, a>, number<u, b>, number<v, c>>
                >
            >
        {};

        template<
            typename list,
            typename t, t a, typename u, u b, typename v, v c
        >
        struct slice_impl<list, number<t, a>, number<u, b>, number<v, c>,
            boolean<!size_t<list>::value>
        >
        {
            using type = list;
        };

        template<typename list, typename start, typename size, typename stride>
        struct slice :
            slice_impl<list, start, size, stride>
        {};
    }
}

#endif
