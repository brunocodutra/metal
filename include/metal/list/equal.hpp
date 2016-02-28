// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_EQUAL_HPP
#define METAL_LIST_EQUAL_HPP

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct equal;
    }

    /// \ingroup list
    /// ...
    template<typename x, typename y>
    using equal = detail::equal<x, y>;

    /// \ingroup list
    /// Eager adaptor for \ref equal.
    template<typename x, typename y>
    using equal_t = typename metal::equal<x, y>::type;
}

#include <metal/list/list.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct equal
        {};

        template<
            template<typename...> class x, typename... xs,
            template<typename...> class y, typename... ys
        >
        struct equal<x<xs...>, y<ys...>> :
            std::is_same<list<xs...>, list<ys...>>
        {};
    }
}

#endif
