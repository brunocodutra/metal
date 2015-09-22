// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_LAMBDA_HPP
#define METAL_TEST_LAMBDA_HPP

#include "test/expressions.hpp"
#include "test/preprocessor.hpp"

#define ARG(N) metal::arg<INC(N)>
#define ARGS(N) ENUM(N, LIFT(ARG))

#define LBD(N) EXPR(N)<ARGS(N)>
#define LBDS(N) ENUM(N, LIFT(LBD))

namespace test
{
    template<template<typename...> class> class lambda;
    template<template<typename...> class _> using lambda0 = lambda<_>;
    template<template<EVAL(ENUM,  1, typename BAR)> class> union  lambda1;
    template<template<EVAL(ENUM,  2, typename BAR)> class> union  lambda2;
    template<template<EVAL(ENUM,  3, typename BAR)> class> union  lambda3;
    template<template<EVAL(ENUM,  4, typename BAR)> class> union  lambda4;
    template<template<EVAL(ENUM,  5, typename BAR)> class> union  lambda5;
    template<template<EVAL(ENUM,  6, typename BAR)> class> struct lambda6;
    template<template<EVAL(ENUM,  7, typename BAR)> class> struct lambda7;
    template<template<EVAL(ENUM,  8, typename BAR)> class> struct lambda8;
    template<template<EVAL(ENUM,  9, typename BAR)> class> struct lambda9;
    template<template<EVAL(ENUM, 10, typename BAR)> class> struct lambda10;
}

#define FUN(...) CAT(test::lambda, __VA_ARGS__)<EXPR(__VA_ARGS__)>
#define FUNS(N) ENUM(N, LIFT(FUN))

#endif
