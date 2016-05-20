// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_MIN_HPP
#define METAL_NUMBER_ARITHMETIC_MIN_HPP

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct min;
    }

    /// \ingroup arithmetic
    /// ...
    template<typename... nums>
    using min = detail::min<nums...>;

    /// \ingroup arithmetic
    /// Eager adaptor for metal::min.
    template<typename... nums>
    using min_t = typename metal::min<nums...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/reduce.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct min
        {};

        template<typename tx, tx vx>
        struct min<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct min<number<tx, vx>, number<ty, vy>> :
            number<decltype(vx < vy ? vx : vy), (vx < vy ? vx : vy)>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct min<number<tx, vx>, number<ty, vy>, nums...> :
            reduce<list<number<tx, vx>, number<ty, vy>, nums...>, lambda<min>>
        {};
    }
}

#endif
