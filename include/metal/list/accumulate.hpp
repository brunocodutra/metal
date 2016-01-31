// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ACCUMULATE_HPP
#define METAL_LIST_ACCUMULATE_HPP

#include <metal/detail/nil.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename = nil, typename = nil>
        struct accumulate;
    }

    /// \ingroup list
    /// ...
    template<
        typename list,
        typename state,
        typename lbd,
        typename begin = detail::nil,
        typename end = detail::nil
    >
    using accumulate = detail::accumulate<list, state, lbd, begin, end>;

    /// \ingroup list
    /// Eager adaptor for \ref accumulate.
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

#include <metal/list/at.hpp>
#include <metal/list/size.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/inc.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename, typename, typename, typename, typename,
            typename = boolean<true>
        >
        struct accumulate_impl
        {};

        template<
            typename list,
            typename state,
            typename lbd,
            typename t, t l,
            typename u, u r
        >
        struct accumulate_impl<
            list, state, lbd, number<t, l>, number<u, r>,
            boolean<(l < r)>
        > :
            invoke<
                accumulate<
                    _1,
                    invoke<_3, _2, at<_1, number<t, l>>>,
                    _3,
                    inc_t<number<t, l>>,
                    number<u, r>
                >,
                list, state, lbd
            >
        {};

        template<
            typename list,
            typename state,
            typename lbd,
            typename t, t l,
            typename u, u r
        >
        struct accumulate_impl<
            list, state, lbd, number<t, l>, number<u, r>,
            boolean<(l > r)>
        > :
            invoke<
                lift_t<lbd>,
                at<list, number<u, r>>,
                accumulate<list, state, lbd, number<t, l>, inc_t<number<u, r>>>
            >
        {};

        template<
            typename list,
            typename state,
            typename lbd,
            typename t, t l,
            typename u, u r
        >
        struct accumulate<list, state, lbd, number<t, l>, number<u, r>> :
            accumulate_impl<list, state, lbd, number<t, l>, number<u, r>>
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
            accumulate<list, state, lbd, integer<0>>
        {};
    }
}

#endif
