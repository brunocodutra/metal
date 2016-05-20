// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_MAX_HPP
#define METAL_NUMBER_ARITHMETIC_MAX_HPP

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct max;
    }

    /// \ingroup arithmetic
    /// ...
    template<typename... nums>
    using max = detail::max<nums...>;

    /// \ingroup arithmetic
    /// Eager adaptor for metal::max.
    template<typename... nums>
    using max_t = typename metal::max<nums...>::type;
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
        struct max
        {};

        template<typename tx, tx vx>
        struct max<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct max<number<tx, vx>, number<ty, vy>> :
            number<decltype(vx > vy ? vx : vy), (vx > vy ? vx : vy)>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct max<number<tx, vx>, number<ty, vy>, nums...> :
            reduce<list<number<tx, vx>, number<ty, vy>, nums...>, lambda<max>>
        {};
    }
}

#endif
