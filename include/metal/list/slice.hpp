// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SLICE_HPP
#define METAL_LIST_SLICE_HPP

# include <type_traits>

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<
        typename list,
        typename start,
        typename size,
        typename stride = std::integral_constant<int, 1>
    >
    struct slice
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref slice.
    template<
        typename list,
        typename start,
        typename size,
        typename stride = std::integral_constant<int, 1>
    >
    using slice_t = typename slice<list, start, size, stride>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/size.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/number/arithmetic/mod.hpp>

namespace metal
{
    template<
        template<typename...> class list, typename... vals,
        typename t, t start, typename u, u size, typename v, v stride
    >
    struct slice<
        list<vals...>,
        number<t, start>, number<u, size>, number<v, stride>
    > :
        transform<
            enumerate_t<number<t, start>, number<u, size>, number<v, stride>>,
            at<quote_t<list<vals...>>, mod<_1, size_t<list<vals...>>>>
        >
    {};
}

#endif
