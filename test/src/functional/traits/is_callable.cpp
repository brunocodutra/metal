// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_callable.hpp>

#include "test.hpp"

using namespace metal;

static_assert(not_<is_callable_t<test::a0>>::value, "");
static_assert(not_<is_callable_t<test::a1>>::value, "");
static_assert(not_<is_callable_t<test::a2>>::value, "");
static_assert(not_<is_callable_t<test::a3>>::value, "");
static_assert(not_<is_callable_t<test::a4>>::value, "");
static_assert(not_<is_callable_t<test::a5>>::value, "");
static_assert(not_<is_callable_t<test::a6>>::value, "");
static_assert(not_<is_callable_t<test::a7>>::value, "");
static_assert(not_<is_callable_t<test::a9>>::value, "");
static_assert(not_<is_callable_t<test::a9>>::value, "");

static_assert(not_<is_callable_t<test::a0, void>>::value, "");
static_assert(not_<is_callable_t<test::a1, void>>::value, "");
static_assert(not_<is_callable_t<test::a2, void>>::value, "");
static_assert(not_<is_callable_t<test::a3, void>>::value, "");
static_assert(not_<is_callable_t<test::a4, void>>::value, "");
static_assert(not_<is_callable_t<test::a5, void>>::value, "");
static_assert(not_<is_callable_t<test::a6, void>>::value, "");
static_assert(not_<is_callable_t<test::a7, void>>::value, "");
static_assert(not_<is_callable_t<test::a9, void>>::value, "");
static_assert(not_<is_callable_t<test::a9, void>>::value, "");

static_assert(not_<is_callable_t<test::a0, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::a1, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::a2, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::a3, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::a4, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::a5, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::a6, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::a7, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::a9, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::a9, void, void*>>::value, "");

static_assert(not_<is_callable_t<test::unary<test::alias>>>::value, "");
static_assert(not_<is_callable_t<test::unary<test::empty>>>::value, "");
static_assert(not_<is_callable_t<test::unary<test::call>>>::value, "");
static_assert(not_<is_callable_t<test::unary<test::evaluable>>>::value, "");

static_assert(not_<is_callable_t<test::unary<test::alias>, void>>::value, "");
static_assert(not_<is_callable_t<test::unary<test::empty>, void>>::value, "");
static_assert(not_<is_callable_t<test::unary<test::call>, void>>::value, "");
static_assert(is_callable_t<test::unary<test::evaluable>, void>::value, "");

static_assert(not_<is_callable_t<test::unary<test::alias>, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::unary<test::empty>, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::unary<test::call>, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::unary<test::evaluable>, void, void*>>::value, "");

static_assert(not_<is_callable_t<test::binary<test::alias>>>::value, "");
static_assert(not_<is_callable_t<test::binary<test::empty>>>::value, "");
static_assert(not_<is_callable_t<test::binary<test::call>>>::value, "");
static_assert(not_<is_callable_t<test::binary<test::evaluable>>>::value, "");

static_assert(not_<is_callable_t<test::binary<test::alias>, void>>::value, "");
static_assert(not_<is_callable_t<test::binary<test::empty>, void>>::value, "");
static_assert(not_<is_callable_t<test::binary<test::call>, void>>::value, "");
static_assert(not_<is_callable_t<test::binary<test::evaluable>, void>>::value, "");

static_assert(not_<is_callable_t<test::binary<test::alias>, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::binary<test::empty>, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::binary<test::call>, void, void*>>::value, "");
static_assert(is_callable_t<test::binary<test::evaluable>, void, void*>::value, "");

static_assert(not_<is_callable_t<test::n_ary<test::alias>>>::value, "");
static_assert(not_<is_callable_t<test::n_ary<test::empty>>>::value, "");
static_assert(not_<is_callable_t<test::n_ary<test::call>>>::value, "");
static_assert(is_callable_t<test::n_ary<test::evaluable>>::value, "");

static_assert(not_<is_callable_t<test::n_ary<test::alias>, void>>::value, "");
static_assert(not_<is_callable_t<test::n_ary<test::empty>, void>>::value, "");
static_assert(not_<is_callable_t<test::n_ary<test::call>, void>>::value, "");
static_assert(is_callable_t<test::n_ary<test::evaluable>, void>::value, "");

static_assert(not_<is_callable_t<test::n_ary<test::alias>, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::n_ary<test::empty>, void, void*>>::value, "");
static_assert(not_<is_callable_t<test::n_ary<test::call>, void, void*>>::value, "");
static_assert(is_callable_t<test::n_ary<test::evaluable>, void, void*>::value, "");
