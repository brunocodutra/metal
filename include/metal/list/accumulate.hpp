// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ACCUMULATE_HPP
#define METAL_LIST_ACCUMULATE_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename...>
    struct accumulate;

    /// \ingroup list
    /// Eager adaptor for \ref accumulate.
    template<typename... _>
    using accumulate_t = typename metal::accumulate<_...>::type;
}

#include <metal/list/size.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/inc.hpp>
#include <metal/optional/conditional.hpp>

#include <cstddef>

namespace metal
{
    template<
        typename list,
        typename state,
        typename lbd,
        typename t, t l,
        typename u, u r
    >
    struct accumulate<list, state, lbd, number<t, l>, number<u, r>> :
        conditional<
            boolean<(l < r)>,
            invoke<
                accumulate<
                    _1,
                    invoke<_3, _2, at<_1, number<t, l>>>,
                    _3,
                    inc_t<number<t, l>>,
                    number<u, r>
                >,
                list, state, lbd
            >,
            invoke<
                lift_t<lbd>,
                at<list, number<u, r>>,
                accumulate<list, state, lbd, number<t, l>, inc_t<number<u, r>>>
            >
        >
    {};

    template<
        typename list,
        typename state,
        typename lbd,
        typename t, t l,
        typename u
    >
    struct accumulate<list, state, lbd, number<t, l>, number<u, u(l + 1)>> :
        invoke<lift_t<lbd>, just<state>, at<list, number<t, l>>>
    {};

    template<
        typename list,
        typename state,
        typename lbd,
        typename t, t l,
        typename u
    >
    struct accumulate<list, state, lbd, number<t, l>, number<u, u(l - 1)>> :
        invoke<lift_t<lbd>, at<list, number<u, l - 1>>, just<state>>
    {};

    template<
        typename list,
        typename state,
        typename lbd,
        typename t, t l,
        typename u
    >
    struct accumulate<list, state, lbd, number<t, l>, number<u, u(l)>>
    {
        using type = state;
    };

    template<typename list, typename state, typename lbd, typename t, t l>
    struct accumulate<list, state, lbd, number<t, l>> :
        invoke<
            accumulate<_1, _2, _3, number<t, l>, size<_1>>,
            list, state, lbd
          >
    {};

    template<typename list, typename state, typename lbd>
    struct accumulate<list, state, lbd> :
        accumulate<list, state, lbd, number<std::size_t, 0>>
    {};
}

#endif
