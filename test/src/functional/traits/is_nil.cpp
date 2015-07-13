// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_nil.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(is_nil_t<test::a0>::value, "");
static_assert(is_nil_t<test::a1>::value, "");
static_assert(is_nil_t<test::a2>::value, "");
static_assert(is_nil_t<test::a3>::value, "");
static_assert(is_nil_t<test::a4>::value, "");
static_assert(is_nil_t<test::a5>::value, "");
static_assert(is_nil_t<test::a6>::value, "");
static_assert(is_nil_t<test::a7>::value, "");
static_assert(is_nil_t<test::a9>::value, "");
static_assert(is_nil_t<test::a9>::value, "");

static_assert(not_<is_nil_t<test::_00_>>::value, "");
static_assert(not_<is_nil_t<test::_01_>>::value, "");
static_assert(not_<is_nil_t<test::_02_>>::value, "");
static_assert(not_<is_nil_t<test::_03_>>::value, "");
static_assert(not_<is_nil_t<test::_04_>>::value, "");
static_assert(not_<is_nil_t<test::_05_>>::value, "");
static_assert(not_<is_nil_t<test::_06_>>::value, "");
static_assert(not_<is_nil_t<test::_07_>>::value, "");
static_assert(not_<is_nil_t<test::_09_>>::value, "");
static_assert(not_<is_nil_t<test::_09_>>::value, "");
static_assert(not_<is_nil_t<test::_10_>>::value, "");

static_assert(is_nil_t<test::alias<>>::value, "");
static_assert(is_nil_t<test::empty<>>::value, "");
static_assert(is_nil_t<test::call<>>::value, "");
static_assert(is_nil_t<test::union_<>>::value, "");
static_assert(not_<is_nil_t<test::evaluable<>>>::value, "");
static_assert(not_<is_nil_t<test::strict<>>>::value, "");
