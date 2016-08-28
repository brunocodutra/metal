// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_DETAIL_PICK_HPP
#define METAL_DETAIL_PICK_HPP

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>
#include <metal/number/if.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq, typename nums>
        struct _pick
        {};

        template<>
        struct _pick<list<>, list<>>
        {
            using type = list<>;
        };

        template<typename... vals, int_... vs>
        struct _pick<list<vals...>, list<number<vs>...>> :
            _join<if_<number<vs>, list<vals>, list<>>...>
        {};

        template<typename seq, typename nums>
        using pick = typename _pick<seq, nums>::type;
    }
}

#endif

