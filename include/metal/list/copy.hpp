// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_COPY_HPP
#define METAL_LIST_COPY_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename...>
    struct copy
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref copy.
    template<typename... _>
    using copy_t = typename copy<_...>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/defer.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/list/list.hpp>
#include <metal/list/slice.hpp>
#include <metal/list/size.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/sub.hpp>
#include <metal/number/arithmetic/dec.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    template<
        typename to,
        template<typename...> class from, typename... vals,
        typename begin, begin b, typename end, end e
    >
    struct copy<to, from<vals...>, number<begin, b>, number<end, e>> :
        conditional<
            boolean<0 <= b && b <= e && e <= sizeof...(vals)>,
            invoke<
                copy<
                    quote_t<to>,
                    slice<
                        quote_t<list<vals...>>,
                        number<begin, b>,
                        sub_t<number<end, e>, number<begin, b>>
                    >
                >
            >,
            boolean<0 <= e && e <= b && b <= sizeof...(vals)>,
            invoke<
                copy<
                    quote_t<to>,
                    slice<
                        quote_t<list<vals...>>,
                        dec_t<number<begin, b>>,
                        sub_t<number<begin, b>, number<end, e>>,
                        integer<-1>
                    >
                >
            >
        >
    {};

    template<
        typename to,
        template<typename...> class from, typename... vals,
        typename t, t n
    >
    struct copy<to, from<vals...>, number<t, n>, number<t, n>> :
        copy<to, list<>>
    {};

    template<
        typename to,
        template<typename...> class from, typename... vals,
        typename begin, begin b
    >
    struct copy<to, from<vals...>, number<begin, b>> :
        copy<to, from<vals...>, number<begin, b>, size_t<from<vals...>>>
    {};

    template<
        template<typename...> class to, typename... ts,
        template<typename...> class from, typename... fs
    >
    struct copy<to<ts...>, from<fs...>> :
        invoke<defer_t<lambda<to>>, fs...>
    {};

    template<template<typename...> class list, typename... ts, typename... fs>
    struct copy<list<ts...>, list<fs...>>
    {
        using type = list<fs...>;
    };
}

#endif
