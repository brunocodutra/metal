// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_nil.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(is_nil<test::a0>::value, "");
static_assert(is_nil<test::a1>::value, "");
static_assert(is_nil<test::a2>::value, "");
static_assert(is_nil<test::a3>::value, "");
static_assert(is_nil<test::a4>::value, "");
static_assert(is_nil<test::a5>::value, "");
static_assert(is_nil<test::a6>::value, "");
static_assert(is_nil<test::a7>::value, "");
static_assert(is_nil<test::a9>::value, "");
static_assert(is_nil<test::a9>::value, "");

static_assert(not_<is_nil<test::_00_>>::value, "");
static_assert(not_<is_nil<test::_01_>>::value, "");
static_assert(not_<is_nil<test::_02_>>::value, "");
static_assert(not_<is_nil<test::_03_>>::value, "");
static_assert(not_<is_nil<test::_04_>>::value, "");
static_assert(not_<is_nil<test::_05_>>::value, "");
static_assert(not_<is_nil<test::_06_>>::value, "");
static_assert(not_<is_nil<test::_07_>>::value, "");
static_assert(not_<is_nil<test::_09_>>::value, "");
static_assert(not_<is_nil<test::_09_>>::value, "");
static_assert(not_<is_nil<test::_10_>>::value, "");

static_assert(is_nil<test::alias<>>::value, "");
static_assert(is_nil<test::empty<>>::value, "");
static_assert(is_nil<test::call<>>::value, "");
static_assert(not_<is_nil<test::union_<>>>::value, "");
static_assert(not_<is_nil<test::evaluable<>>>::value, "");
static_assert(not_<is_nil<test::strict<>>>::value, "");
