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
        template<typename list, typename start, typename size, typename stride>
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
    /// Eager adaptor for \ref slice.
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
#include <metal/number/enumerate.hpp>
#include <metal/number/arithmetic/mod.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename start, typename size, typename stride>
        struct slice
        {};

        template<
            template<typename...> class expr, typename... vals,
            typename t, t a, typename u, u b, typename v, v c
        >
        struct slice<expr<vals...>, number<t, a>, number<u, b>, number<v, c>> :
            copy<
                expr<vals...>,
                transform_t<
                    at<quote_t<expr<vals...>>, mod<_1, size_t<expr<vals...>>>>,
                    enumerate_t<number<t, a>, number<u, b>, number<v, c>>
                >
            >
        {};
    }
}

#endif
