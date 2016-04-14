// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_FOLD_HPP
#define METAL_LIST_FOLD_HPP

#include <metal/detail/nil.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename = nil, typename = nil>
        struct fold;
    }

    /// \ingroup list
    /// ...
    template<
        typename list,
        typename state,
        typename lbd,
        typename beg = detail::nil,
        typename end = detail::nil
    >
    using fold = detail::fold<list, state, lbd, beg, end>;

    /// \ingroup list
    /// Eager adaptor for metal::fold.
    template<
        typename list,
        typename state,
        typename lbd,
        typename beg = detail::nil,
        typename end = detail::nil
    >
    using fold_t = typename metal::fold<list, state, lbd, beg, end>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/size.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename list,
            typename state,
            typename lbd,
            typename t, t l, t r
        >
        struct fold<list, state, lbd, number<t, l>, number<t, r>> :
            invoke<
                fold<
                    _1,
                    fold<_1, _2, _3, number<t, l>, number<t, (l + r)/2>>,
                    _3,
                    number<t, (l + r)/2>,
                    number<t, r>
                >,
                list, state, lbd
            >
        {};

        template<
            typename list,
            typename state,
            typename lbd,
            typename t, t l
        >
        struct fold<
            list, state, lbd,
            number<t, l>, number<t, static_cast<t>(l + 1)>
        > :
            invoke<lift_t<lbd>, just<state>, at<list, number<t, l>>>
        {};

        template<
            typename list,
            typename state,
            typename lbd,
            typename t, t l
        >
        struct fold<
            list, state, lbd,
            number<t, l>, number<t, static_cast<t>(l - 1)>
        > :
            invoke<lift_t<lbd>, just<state>, at<list, number<t, l - 1>>>
        {};

        template<
            typename list,
            typename state,
            typename lbd,
            typename t, t l
        >
        struct fold<list, state, lbd, number<t, l>, number<t, l>>
        {
            using type = state;
        };

        template<
            typename list,
            typename state,
            typename lbd,
            typename t, t l,
            typename u, u r
        >
        struct fold<list, state, lbd, number<t, l>, number<u, r>> :
            fold<
                list,
                state,
                lbd,
                number<decltype(l + r), l>,
                number<decltype(l + r), r>
            >
        {};

        template<typename list, typename state, typename lbd, typename t, t l>
        struct fold<list, state, lbd, number<t, l>> :
            invoke<
                fold<_1, _2, _3, number<t, l>, size<_1>>,
                list, state, lbd
            >
        {};

        template<typename list, typename state, typename lbd>
        struct fold<list, state, lbd> :
            fold<list, state, lbd, integer<0>>
        {};
    }
}

#endif
