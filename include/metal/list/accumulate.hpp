// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ACCUMULATE_HPP
#define METAL_LIST_ACCUMULATE_HPP

#include <metal/list/fold.hpp>

#include <metal/detail/nil.hpp>

namespace metal
{
    /// \ingroup list
    /// An alias for \ref fold.
    template<
        typename list,
        typename state,
        typename lbd,
        typename begin = detail::nil,
        typename end = detail::nil
    >
    using accumulate = detail::fold<list, state, lbd, begin, end>;

    /// \ingroup list
    /// Eager adaptor for metal::accumulate.
    template<
        typename list,
        typename state,
        typename lbd,
        typename begin = detail::nil,
        typename end = detail::nil
    >
    using accumulate_t =
        typename metal::accumulate<list, state, lbd, begin, end>::type;
}

#endif
