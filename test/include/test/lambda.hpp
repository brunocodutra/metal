// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_LAMBDA_HPP
#define METAL_TEST_LAMBDA_HPP

#include "test/expressions.hpp"
#include "test/preprocessor.hpp"

#include <cstddef>

namespace metal
{
    template<std::size_t>
    struct arg;
}

#define ARG(N) metal::arg<INC(N)>
#define ARGS(N) ENUM(N, FORWARD(ARG))

namespace test
{
    template<template<typename...> class>
    struct lambda;

    using lbd0  = expr0<ARGS(0)>;
    using lbd1  = expr1<ARGS(1)>;
    using lbd2  = expr2<ARGS(2)>;
    using lbd3  = expr3<ARGS(3)>;
    using lbd4  = expr4<ARGS(4)>;
    using lbd5  = expr5<ARGS(5)>;
    using lbd6  = expr6<ARGS(6)>;
    using lbd7  = expr7<ARGS(7)>;
    using lbd8  = expr8<ARGS(8)>;
    using lbd9  = expr9<ARGS(9)>;
    using lbd10 = expr10<ARGS(10)>;
}

#define FUN(...) test::lambda<EXPR(__VA_ARGS__)>

#define LBD(N) CAT(test::lbd, N)
#define LBDS(N) ENUM(N, test::lbd)

#endif
