// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_LAMBDA_HPP
#define METAL_TEST_LAMBDA_HPP

#include "test/expressions.hpp"
#include "test/preprocessor.hpp"

namespace test
{
    template<template<typename...> class>
    struct lambda;

    template<template<typename...> class expr>
    using lambda_ = lambda<expr>;

    template<template<typename...> class> union lambda0;
    template<template<typename...> class> union lambda1;
    template<template<typename...> class> union lambda2;
    template<template<typename...> class> union lambda3;
    template<template<typename...> class> union lambda4;
    template<template<typename...> class> union lambda5;
    template<template<typename...> class> union lambda6;
    template<template<typename...> class> union lambda7;
    template<template<typename...> class> union lambda8;
}

#define LBD(...) CAT(test::lambda, __VA_ARGS__)<EXPR(__VA_ARGS__)>
#define LBDS(N) ENUM(N, LBD)

#endif
