// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ACCUMULATE_HPP
#define METAL_LIST_ACCUMULATE_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename...>
    struct accumulate;

    /// \ingroup list
    /// \brief Eager adaptor for \ref accumulate.
    template<typename... _>
    using accumulate_t = typename accumulate<_...>::type;
}

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
                    quote_t<list>,
                    bind_t<
                        lbd,
                        quote_t<state>,
                        at<quote_t<list>, number<t, l>>
                    >,
                    quote_t<lbd>,
                    inc_t<number<t, l>>,
                    number<u, r>
                >
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
    struct accumulate<list, state, lbd, number<t, l>, number<u, l + 1>> :
        invoke<lift_t<lbd>, just<state>, at<list, number<t, l>>>
    {};

    template<
        typename list,
        typename state,
        typename lbd,
        typename t, t l,
        typename u
    >
    struct accumulate<list, state, lbd, number<t, l>, number<u, l - 1>> :
        invoke<lift_t<lbd>, at<list, number<u, l - 1>>, just<state>>
    {};

    template<
        typename list,
        typename state,
        typename lbd,
        typename t, t l,
        typename u
    >
    struct accumulate<list, state, lbd, number<t, l>, number<u, l>>
    {
        using type = state;
    };

    template<typename list, typename state, typename lbd, typename t, t l>
    struct accumulate<list, state, lbd, number<t, l>> :
        invoke<
            accumulate<
                quote_t<list>,
                quote_t<state>,
                quote_t<lbd>,
                number<t, l>,
                size<quote_t<list>>
            >
          >
    {};

    template<typename list, typename state, typename lbd>
    struct accumulate<list, state, lbd> :
        accumulate<list, state, lbd, number<std::size_t, 0>>
    {};
}

#endif
