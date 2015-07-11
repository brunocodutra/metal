// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_strictly_evaluable.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(not_<is_strictly_evaluable<test::alias>>::value, "");
static_assert(not_<is_strictly_evaluable<test::empty>>::value, "");
static_assert(not_<is_strictly_evaluable<test::call>>::value, "");
static_assert(not_<is_strictly_evaluable<test::union_>>::value, "");
static_assert(not_<is_strictly_evaluable<test::evaluable>>::value, "");
static_assert(is_strictly_evaluable<test::strict>::value, "");

static_assert(not_<is_strictly_evaluable<test::alias, test::a0>>::value, "");
static_assert(not_<is_strictly_evaluable<test::empty, test::a0>>::value, "");
static_assert(not_<is_strictly_evaluable<test::call, test::a0>>::value, "");
static_assert(not_<is_strictly_evaluable<test::union_, test::a0>>::value, "");
static_assert(not_<is_strictly_evaluable<test::evaluable, test::a0>>::value, "");
static_assert(is_strictly_evaluable<test::strict, test::a0>::value, "");

static_assert(not_<is_strictly_evaluable<test::alias, test::a0, test::a1>>::value, "");
static_assert(not_<is_strictly_evaluable<test::empty, test::a0, test::a1>>::value, "");
static_assert(not_<is_strictly_evaluable<test::call, test::a0, test::a1>>::value, "");
static_assert(not_<is_strictly_evaluable<test::union_, test::a0, test::a1>>::value, "");
static_assert(not_<is_strictly_evaluable<test::evaluable, test::a0, test::a1>>::value, "");
static_assert(is_strictly_evaluable<test::strict, test::a0, test::a1>::value, "");
