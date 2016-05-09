// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MAX_HPP
#define METAL_NUMBER_MAX_HPP

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _max;
    }

    /// \ingroup number
    /// ...
    template<typename head, typename... tail>
    using max = typename detail::_max<head, tail...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/fold.hpp>

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _max
        {};

        template<typename tx, tx vx>
        struct _max<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct _max<number<tx, vx>, number<ty, vy>> :
            number<decltype(vx > vy ? vx : vy), (vx > vy ? vx : vy)>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct _max<number<tx, vx>, number<ty, vy>, nums...> :
            _fold<
                list<number<ty, vy>, nums...>,
                number<tx, vx>, lambda<max>,
                size_t<0>, size_t<sizeof...(nums) + 1>
            >
        {};
    }
}

#endif
