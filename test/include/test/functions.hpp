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
        using call = expr<>;
    };

    template<template<typename...> class expr>
    struct unary
    {
        using type = unary;

        template<typename args>
        using call = expr<args>;
    };

    template<template<typename...> class expr>
    struct binary
    {
        using type = binary;

        template<typename x, typename y>
        using call = expr<x, y>;
    };

    template<template<typename...> class expr>
    struct n_ary
    {
        using type = n_ary;

        template<typename... args>
        using call = expr<args...>;
    };

    using f0 = nullary<evaluable>;
    using f1 = unary<evaluable>;
    using f2 = binary<evaluable>;
    using fn = n_ary<evaluable>;
}

#endif
