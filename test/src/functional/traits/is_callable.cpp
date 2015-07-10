// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_callable.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(not_<is_callable<test::a0>>{}, "");
static_assert(not_<is_callable<test::a1>>{}, "");
static_assert(not_<is_callable<test::a2>>{}, "");
static_assert(not_<is_callable<test::a3>>{}, "");
static_assert(not_<is_callable<test::a4>>{}, "");
static_assert(not_<is_callable<test::a5>>{}, "");
static_assert(not_<is_callable<test::a6>>{}, "");
static_assert(not_<is_callable<test::a7>>{}, "");
static_assert(not_<is_callable<test::a9>>{}, "");
static_assert(not_<is_callable<test::a9>>{}, "");

static_assert(not_<is_callable<test::a0, void>>{}, "");
static_assert(not_<is_callable<test::a1, void>>{}, "");
static_assert(not_<is_callable<test::a2, void>>{}, "");
static_assert(not_<is_callable<test::a3, void>>{}, "");
static_assert(not_<is_callable<test::a4, void>>{}, "");
static_assert(not_<is_callable<test::a5, void>>{}, "");
static_assert(not_<is_callable<test::a6, void>>{}, "");
static_assert(not_<is_callable<test::a7, void>>{}, "");
static_assert(not_<is_callable<test::a9, void>>{}, "");
static_assert(not_<is_callable<test::a9, void>>{}, "");

static_assert(not_<is_callable<test::a0, void, void*>>{}, "");
static_assert(not_<is_callable<test::a1, void, void*>>{}, "");
static_assert(not_<is_callable<test::a2, void, void*>>{}, "");
static_assert(not_<is_callable<test::a3, void, void*>>{}, "");
static_assert(not_<is_callable<test::a4, void, void*>>{}, "");
static_assert(not_<is_callable<test::a5, void, void*>>{}, "");
static_assert(not_<is_callable<test::a6, void, void*>>{}, "");
static_assert(not_<is_callable<test::a7, void, void*>>{}, "");
static_assert(not_<is_callable<test::a9, void, void*>>{}, "");
static_assert(not_<is_callable<test::a9, void, void*>>{}, "");

static_assert(not_<is_callable<test::unary<test::alias>>>{}, "");
static_assert(not_<is_callable<test::unary<test::empty>>>{}, "");
static_assert(not_<is_callable<test::unary<test::call>>>{}, "");
static_assert(not_<is_callable<test::unary<test::evaluable>>>{}, "");
static_assert(not_<is_callable<test::unary<test::evaluable_union>>>{}, "");

static_assert(not_<is_callable<test::unary<test::alias>, void>>{}, "");
static_assert(not_<is_callable<test::unary<test::empty>, void>>{}, "");
static_assert(not_<is_callable<test::unary<test::call>, void>>{}, "");
static_assert(is_callable<test::unary<test::evaluable>, void>{}, "");
static_assert(is_callable<test::unary<test::evaluable_union>, void>{}, "");

static_assert(not_<is_callable<test::unary<test::alias>, void, void*>>{}, "");
static_assert(not_<is_callable<test::unary<test::empty>, void, void*>>{}, "");
static_assert(not_<is_callable<test::unary<test::call>, void, void*>>{}, "");
static_assert(not_<is_callable<test::unary<test::evaluable>, void, void*>>{}, "");
static_assert(not_<is_callable<test::unary<test::evaluable_union>, void, void*>>{}, "");

static_assert(not_<is_callable<test::binary<test::alias>>>{}, "");
static_assert(not_<is_callable<test::binary<test::empty>>>{}, "");
static_assert(not_<is_callable<test::binary<test::call>>>{}, "");
static_assert(not_<is_callable<test::binary<test::evaluable>>>{}, "");
static_assert(not_<is_callable<test::binary<test::evaluable_union>>>{}, "");

static_assert(not_<is_callable<test::binary<test::alias>, void>>{}, "");
static_assert(not_<is_callable<test::binary<test::empty>, void>>{}, "");
static_assert(not_<is_callable<test::binary<test::call>, void>>{}, "");
static_assert(not_<is_callable<test::binary<test::evaluable>, void>>{}, "");
static_assert(not_<is_callable<test::binary<test::evaluable_union>, void>>{}, "");

static_assert(not_<is_callable<test::binary<test::alias>, void, void*>>{}, "");
static_assert(not_<is_callable<test::binary<test::empty>, void, void*>>{}, "");
static_assert(not_<is_callable<test::binary<test::call>, void, void*>>{}, "");
static_assert(is_callable<test::binary<test::evaluable>, void, void*>{}, "");
static_assert(is_callable<test::binary<test::evaluable_union>, void, void*>{}, "");

static_assert(not_<is_callable<test::n_ary<test::alias>>>{}, "");
static_assert(not_<is_callable<test::n_ary<test::empty>>>{}, "");
static_assert(not_<is_callable<test::n_ary<test::call>>>{}, "");
static_assert(is_callable<test::n_ary<test::evaluable>>{}, "");
static_assert(is_callable<test::n_ary<test::evaluable_union>>{}, "");

static_assert(not_<is_callable<test::n_ary<test::alias>, void>>{}, "");
static_assert(not_<is_callable<test::n_ary<test::empty>, void>>{}, "");
static_assert(not_<is_callable<test::n_ary<test::call>, void>>{}, "");
static_assert(is_callable<test::n_ary<test::evaluable>, void>{}, "");
static_assert(is_callable<test::n_ary<test::evaluable_union>, void>{}, "");

static_assert(not_<is_callable<test::n_ary<test::alias>, void, void*>>{}, "");
static_assert(not_<is_callable<test::n_ary<test::empty>, void, void*>>{}, "");
static_assert(not_<is_callable<test::n_ary<test::call>, void, void*>>{}, "");
static_assert(is_callable<test::n_ary<test::evaluable>, void, void*>{}, "");
static_assert(is_callable<test::n_ary<test::evaluable_union>, void, void*>{}, "");

