// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_FUNCTIONS_HPP
#define METAL_TEST_FUNCTIONS_HPP

#include "test/expressions.hpp"

namespace test
{
    template<template<typename...> class expr>
    struct nullary
    {
        using type = nullary;

        template<typename = void>
        struct call :
                expr<>
        {};
    };

    template<>
    struct nullary<incomplete>
    {
        using type = nullary;

        template<typename>
        struct call;
    };

    template<template<typename...> class expr>
    struct unary
    {
        using type = unary;

        template<typename args>
        struct call :
                expr<args>
        {};
    };

    template<>
    struct unary<incomplete>
    {
        using type = unary;

        template<typename>
        struct call;
    };

    template<template<typename...> class expr>
    struct binary
    {
        using type = binary;

        template<typename x, typename y>
        struct call :
                expr<x, y>
        {};
    };

    template<>
    struct binary<incomplete>
    {
        using type = binary;

        template<typename x, typename y>
        struct call;
    };

    template<template<typename...> class expr>
    struct n_ary
    {
        using type = n_ary;

        template<typename... args>
        struct call :
                expr<args...>
        {};
    };

    template<>
    struct n_ary<incomplete>
    {
        using type = n_ary;

        template<typename...>
        struct call;
    };
}

#endif
