// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _join;
    }

    /// \ingroup list
    /// ...
    template<typename head, typename... tail>
    using join = typename detail::_join<head, tail...>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/reduce.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _join
        {};

        template<
            typename... ws, typename... xs, typename... ys, typename... zs,
            typename... _
        >
        struct _join<list<ws...>, list<xs...>, list<ys...>, list<zs...>, _...> :
            _reduce<
                list<list<ws..., xs..., ys..., zs...>, _...>,
                lambda<join>,
                size_t<0>, size_t<sizeof...(_) + 1>
            >
        {};

        template<typename... ws, typename... xs, typename... ys, typename... zs>
        struct _join<list<ws...>, list<xs...>, list<ys...>, list<zs...>>
        {
            using type = list<ws..., xs..., ys..., zs...>;
        };

        template<typename... ws, typename... xs, typename... ys>
        struct _join<list<ws...>, list<xs...>, list<ys...>>
        {
            using type = list<ws..., xs..., ys...>;
        };

        template<typename... ws, typename... xs>
        struct _join<list<ws...>, list<xs...>>
        {
            using type = list<ws..., xs...>;
        };

        template<typename... ws>
        struct _join<list<ws...>>
        {
            using type = list<ws...>;
        };
    }
}

#endif
