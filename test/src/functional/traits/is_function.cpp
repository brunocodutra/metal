// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_function.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(not_<is_function<test::a0>>{}, "");
static_assert(not_<is_function<test::a1>>{}, "");
static_assert(not_<is_function<test::a2>>{}, "");
static_assert(not_<is_function<test::a3>>{}, "");
static_assert(not_<is_function<test::a4>>{}, "");
static_assert(not_<is_function<test::a5>>{}, "");
static_assert(not_<is_function<test::a6>>{}, "");
static_assert(not_<is_function<test::a7>>{}, "");
static_assert(not_<is_function<test::a9>>{}, "");
static_assert(not_<is_function<test::a9>>{}, "");

static_assert(not_<is_function<test::alias<>>>{}, "");
static_assert(not_<is_function<test::empty<>>>{}, "");
static_assert(not_<is_function<test::call<>>>{}, "");
static_assert(not_<is_function<test::union_<>>>{}, "");
static_assert(not_<is_function<test::evaluable<>>>{}, "");

static_assert(is_function<test::unary<test::alias>>{}, "");
static_assert(is_function<test::unary<test::empty>>{}, "");
static_assert(is_function<test::unary<test::call>>{}, "");
static_assert(is_function<test::unary<test::union_>>{}, "");
static_assert(is_function<test::unary<test::evaluable>>{}, "");

static_assert(is_function<test::binary<test::alias>>{}, "");
static_assert(is_function<test::binary<test::empty>>{}, "");
static_assert(is_function<test::binary<test::call>>{}, "");
static_assert(is_function<test::binary<test::union_>>{}, "");
static_assert(is_function<test::binary<test::evaluable>>{}, "");

static_assert(is_function<test::n_ary<test::alias>>{}, "");
static_assert(is_function<test::n_ary<test::empty>>{}, "");
static_assert(is_function<test::n_ary<test::call>>{}, "");
static_assert(is_function<test::n_ary<test::union_>>{}, "");
static_assert(is_function<test::n_ary<test::evaluable>>{}, "");
