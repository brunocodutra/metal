// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_nil.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(is_nil<test::a0>{}, "");
static_assert(is_nil<test::a1>{}, "");
static_assert(is_nil<test::a2>{}, "");
static_assert(is_nil<test::a3>{}, "");
static_assert(is_nil<test::a4>{}, "");
static_assert(is_nil<test::a5>{}, "");
static_assert(is_nil<test::a6>{}, "");
static_assert(is_nil<test::a7>{}, "");
static_assert(is_nil<test::a9>{}, "");
static_assert(is_nil<test::a9>{}, "");

static_assert(is_nil<test::alias<>>{}, "");
static_assert(is_nil<test::empty<>>{}, "");
static_assert(is_nil<test::call<>>{}, "");
static_assert(not_<is_nil<test::evaluable<>>>{}, "");
static_assert(not_<is_nil<test::evaluable_union<>>>{}, "");
