// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_TRANSPOSE_HPP
#define METAL_LIST_TRANSPOSE_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct transpose;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using transpose = detail::transpose<list>;

    /// \ingroup list
    /// Eager adaptor for \ref transpose.
    template<typename list>
    using transpose_t = typename metal::transpose<list>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/same.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/eval.hpp>

namespace metal
{
    namespace detail
    {
        template<typename>
        struct unbind
        {};

        template<typename list>
        using unbind_t = typename unbind<list>::type;

        template<template<typename...> class list, typename... vals>
        struct unbind<list<vals...>>
        {
            using type = lambda<list>;
        };

        template<typename, typename...>
        struct zip
        {};

        template<
            template<typename...> class zipper,
            typename head, typename... tail
        >
        struct zip<lambda<zipper>, head, tail...> :
            conditional<
                same_t<list<unbind_t<head>, unbind_t<tail>...>>,
                transform<
                    indices_t<head>,
                    defer_t<
                        zipper<at<quote_t<head>, _1>, at<quote_t<tail>, _1>...>
                    >
                >
            >
        {};

        template<
            template<typename...> class zipper,
            template<typename...> class list,
            typename... xs, typename... ys
        >
        struct zip<lambda<zipper>, list<xs...>, list<ys...>>
        {
            using type = list<zipper<xs, ys>...>;
        };

        template<
            template<typename...> class zipper,
            template<typename...> class list,
            typename... xs
        >
        struct zip<lambda<zipper>, list<xs...>>
        {
            using type = list<zipper<xs>...>;
        };

        template<typename list>
        struct transpose
        {};

        template<template<typename...> class outer, typename head, typename... tail>
        struct transpose<outer<head, tail...>> :
            conditional<
                eval<
                    invoke<lift_t<same<lambda<list>>>, size<head>, size<tail>...>,
                    nothing
                >,
                zip<lambda<outer>, head, tail...>
            >
        {};
    }
}

#endif
