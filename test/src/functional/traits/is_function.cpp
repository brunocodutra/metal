// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_function.hpp>

#include "test.hpp"

using namespace metal;

static_assert(not_<is_function_t<test::a0>>::value, "");
static_assert(not_<is_function_t<test::a1>>::value, "");
static_assert(not_<is_function_t<test::a2>>::value, "");
static_assert(not_<is_function_t<test::a3>>::value, "");
static_assert(not_<is_function_t<test::a4>>::value, "");
static_assert(not_<is_function_t<test::a5>>::value, "");
static_assert(not_<is_function_t<test::a6>>::value, "");
static_assert(not_<is_function_t<test::a7>>::value, "");
static_assert(not_<is_function_t<test::a9>>::value, "");
static_assert(not_<is_function_t<test::a9>>::value, "");

static_assert(not_<is_function_t<test::alias<>>>::value, "");
static_assert(not_<is_function_t<test::empty<>>>::value, "");
static_assert(not_<is_function_t<test::call<>>>::value, "");
static_assert(not_<is_function_t<test::evaluable<>>>::value, "");

static_assert(is_function_t<test::unary<test::alias>>::value, "");
static_assert(is_function_t<test::unary<test::empty>>::value, "");
static_assert(is_function_t<test::unary<test::call>>::value, "");
static_assert(is_function_t<test::unary<test::evaluable>>::value, "");

static_assert(is_function_t<test::binary<test::alias>>::value, "");
static_assert(is_function_t<test::binary<test::empty>>::value, "");
static_assert(is_function_t<test::binary<test::call>>::value, "");
static_assert(is_function_t<test::binary<test::evaluable>>::value, "");

static_assert(is_function_t<test::n_ary<test::alias>>::value, "");
static_assert(is_function_t<test::n_ary<test::empty>>::value, "");
static_assert(is_function_t<test::n_ary<test::call>>::value, "");
static_assert(is_function_t<test::n_ary<test::evaluable>>::value, "");
