// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_function.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(not_<is_function<test::a0>>::value, "");
static_assert(not_<is_function<test::a1>>::value, "");
static_assert(not_<is_function<test::a2>>::value, "");
static_assert(not_<is_function<test::a3>>::value, "");
static_assert(not_<is_function<test::a4>>::value, "");
static_assert(not_<is_function<test::a5>>::value, "");
static_assert(not_<is_function<test::a6>>::value, "");
static_assert(not_<is_function<test::a7>>::value, "");
static_assert(not_<is_function<test::a9>>::value, "");
static_assert(not_<is_function<test::a9>>::value, "");

static_assert(not_<is_function<test::alias<>>>::value, "");
static_assert(not_<is_function<test::empty<>>>::value, "");
static_assert(not_<is_function<test::call<>>>::value, "");
static_assert(not_<is_function<test::union_<>>>::value, "");
static_assert(not_<is_function<test::evaluable<>>>::value, "");
static_assert(not_<is_function<test::strict<>>>::value, "");

static_assert(is_function<test::unary<test::alias>>::value, "");
static_assert(is_function<test::unary<test::empty>>::value, "");
static_assert(is_function<test::unary<test::call>>::value, "");
static_assert(is_function<test::unary<test::union_>>::value, "");
static_assert(is_function<test::unary<test::evaluable>>::value, "");
static_assert(is_function<test::unary<test::strict>>::value, "");

static_assert(is_function<test::binary<test::alias>>::value, "");
static_assert(is_function<test::binary<test::empty>>::value, "");
static_assert(is_function<test::binary<test::call>>::value, "");
static_assert(is_function<test::binary<test::union_>>::value, "");
static_assert(is_function<test::binary<test::evaluable>>::value, "");
static_assert(is_function<test::binary<test::strict>>::value, "");

static_assert(is_function<test::n_ary<test::alias>>::value, "");
static_assert(is_function<test::n_ary<test::empty>>::value, "");
static_assert(is_function<test::n_ary<test::call>>::value, "");
static_assert(is_function<test::n_ary<test::union_>>::value, "");
static_assert(is_function<test::n_ary<test::evaluable>>::value, "");
static_assert(is_function<test::n_ary<test::strict>>::value, "");
