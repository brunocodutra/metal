// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_EQUAL_HPP
#define METAL_LIST_EQUAL_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename x, typename y>
    struct equal
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref equal.
    template<typename x, typename y>
    using equal_t = typename equal<x, y>::type;
}

#include <metal/list/list.hpp>

#include <type_traits>

namespace metal
{
    template<
        template<typename...> class x, typename... xs,
        template<typename...> class y, typename... ys
    >
    struct equal<x<xs...>, y<ys...>> :
        std::is_same<list<xs...>, list<ys...>>
    {};
}

#endif
