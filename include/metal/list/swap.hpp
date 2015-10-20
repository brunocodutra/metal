// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SWAP_HPP
#define METAL_LIST_SWAP_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename x, typename y>
    struct swap
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref swap.
    template<typename x, typename y>
    using swap_t = typename swap<x, y>::type;
}

#include <metal/lambda/defer.hpp>
#include <metal/lambda/lambda.hpp>

namespace metal
{
    template<
        template<typename...> class x, typename... xs,
        template<typename...> class y, typename... ys
    >
    struct swap<x<xs...>, y<ys...>> :
        defer<lambda<x>, ys...>
    {};
}

#endif
