// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_same_function.hpp>

#include "test.hpp"

using namespace metal;

static_assert(!is_same_function_t<test::a0, test::a0>::value, "");
static_assert(!is_same_function_t<test::a1, test::a1>::value, "");
static_assert(!is_same_function_t<test::a2, test::a2>::value, "");
static_assert(!is_same_function_t<test::a3, test::a3>::value, "");
static_assert(!is_same_function_t<test::a4, test::a4>::value, "");
static_assert(!is_same_function_t<test::a5, test::a5>::value, "");
static_assert(!is_same_function_t<test::a6, test::a6>::value, "");
static_assert(!is_same_function_t<test::a7, test::a7>::value, "");
static_assert(!is_same_function_t<test::a9, test::a9>::value, "");
static_assert(!is_same_function_t<test::a9, test::a9>::value, "");

static_assert(is_same_function_t<test::f0, test::f0>::value, "");
static_assert(is_same_function_t<test::f1, test::f1>::value, "");
static_assert(is_same_function_t<test::f2, test::f2>::value, "");
static_assert(is_same_function_t<test::fn, test::fn>::value, "");

static_assert(!is_same_function_t<test::f0, test::fn>::value, "");
static_assert(!is_same_function_t<test::f1, test::f0>::value, "");
static_assert(!is_same_function_t<test::f2, test::f1>::value, "");
static_assert(!is_same_function_t<test::fn, test::f2>::value, "");
