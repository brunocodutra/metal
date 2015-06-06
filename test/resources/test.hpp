// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/core/logical.hpp>

#include <type_traits>

namespace test
{
    template<typename...>
    using fundamental = void;

    template<typename...>
    using function = void();

    template<typename...>
    struct incomplete;

    template<typename...>
    struct empty {};

    template<typename...>
    struct evaluable {struct type;};

    template<typename...>
    struct tagged{struct tag;};

    template<typename...>
    struct call {};

    template<typename...>
    struct tag {};

    template<template<typename...> class base, typename... _>
    struct eponym : base<_...> {};

    template<typename... args>
    struct wrap
    {
        using type = wrap<args...>;
    };

    struct wrapper
    {
        template<typename... args>
        struct call :
                wrap<args...>
        {};
    };

    template<template<typename...> class expr>
    struct unary
    {
        template<typename args>
        struct call :
                expr<args>
        {};
    };

    template<>
    struct unary<incomplete>
    {
        template<typename>
        struct call;
    };

    template<template<typename...> class expr>
    struct binary
    {
        template<typename x, typename y>
        struct call :
                expr<x, y>
        {};
    };

    template<>
    struct binary<incomplete>
    {
        template<typename x, typename y>
        struct call;
    };

    template<template<typename...> class expr>
    struct n_ary
    {
        template<typename... args>
        struct call :
                expr<args...>
        {};
    };

    template<>
    struct n_ary<incomplete>
    {
        template<typename...>
        struct call;
    };
}
