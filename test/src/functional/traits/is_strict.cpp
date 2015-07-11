// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_strict.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(not_<is_strict<test::a0>>::value, "");
static_assert(not_<is_strict<test::a1>>::value, "");
static_assert(not_<is_strict<test::a2>>::value, "");
static_assert(not_<is_strict<test::a3>>::value, "");
static_assert(not_<is_strict<test::a4>>::value, "");
static_assert(not_<is_strict<test::a5>>::value, "");
static_assert(not_<is_strict<test::a6>>::value, "");
static_assert(not_<is_strict<test::a7>>::value, "");
static_assert(not_<is_strict<test::a9>>::value, "");
static_assert(not_<is_strict<test::a9>>::value, "");

static_assert(is_strict<test::_00_>::value, "");
static_assert(is_strict<test::_01_>::value, "");
static_assert(is_strict<test::_02_>::value, "");
static_assert(is_strict<test::_03_>::value, "");
static_assert(is_strict<test::_04_>::value, "");
static_assert(is_strict<test::_05_>::value, "");
static_assert(is_strict<test::_06_>::value, "");
static_assert(is_strict<test::_07_>::value, "");
static_assert(is_strict<test::_09_>::value, "");
static_assert(is_strict<test::_09_>::value, "");
static_assert(is_strict<test::_10_>::value, "");

static_assert(not_<is_strict<test::alias<>>>::value, "");
static_assert(not_<is_strict<test::empty<>>>::value, "");
static_assert(not_<is_strict<test::call<>>>::value, "");
static_assert(not_<is_strict<test::union_<>>>::value, "");
static_assert(not_<is_strict<test::evaluable<>>>::value, "");
static_assert(is_strict<test::strict<>>::value, "");
