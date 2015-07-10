// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_same_function.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(not_<is_same_function<test::a0, test::a0>>{}, "");
static_assert(not_<is_same_function<test::a1, test::a1>>{}, "");
static_assert(not_<is_same_function<test::a2, test::a2>>{}, "");
static_assert(not_<is_same_function<test::a3, test::a3>>{}, "");
static_assert(not_<is_same_function<test::a4, test::a4>>{}, "");
static_assert(not_<is_same_function<test::a5, test::a5>>{}, "");
static_assert(not_<is_same_function<test::a6, test::a6>>{}, "");
static_assert(not_<is_same_function<test::a7, test::a7>>{}, "");
static_assert(not_<is_same_function<test::a9, test::a9>>{}, "");
static_assert(not_<is_same_function<test::a9, test::a9>>{}, "");

static_assert(is_same_function<test::f0, test::f0>{}, "");
static_assert(is_same_function<test::f1, test::f1>{}, "");
static_assert(is_same_function<test::f2, test::f2>{}, "");
static_assert(is_same_function<test::fn, test::fn>{}, "");

static_assert(not_<is_same_function<test::f0, test::fn>>{}, "");
static_assert(not_<is_same_function<test::f1, test::f0>>{}, "");
static_assert(not_<is_same_function<test::f2, test::f1>>{}, "");
static_assert(not_<is_same_function<test::fn, test::f2>>{}, "");
