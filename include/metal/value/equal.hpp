// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_VALUE_EQUAL_HPP
#define METAL_VALUE_EQUAL_HPP

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _canonic;

        template<typename val>
        using canonic = typename _canonic<val>::type;
    }

    /// \ingroup list
    /// ...
    template<typename x, typename y>
    using equal =
        typename std::is_same<detail::canonic<x>, detail::canonic<y>>::type;
}

#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>
#include <metal/pair/pair.hpp>

#include <cstdint>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _canonic
        {
            using type = val;
        };

        template<typename t, t v>
        struct _canonic<number<t, v>>
        {
            using type = pair<
                bool_<(v < 0)>,
                number<std::uintmax_t, (v < 0) ? 0 - v : v>
            >;
        };

        template<template<typename...> class seq, typename... vals>
        struct _canonic<seq<vals...>>
        {
            using type = list<typename _canonic<vals>::type...>;
        };

        template<
            template<template<typename...> class> class lbd,
            template<typename...> class expr
        >
        struct _canonic<lbd<expr>>
        {
            using type = lambda<expr>;
        };
    }
}

#endif
