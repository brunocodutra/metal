// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/identity.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(std::is_same<identity<test::a0>::type, test::a0>{}, "");
static_assert(std::is_same<identity<test::a1>::type, test::a1>{}, "");
static_assert(std::is_same<identity<test::a2>::type, test::a2>{}, "");
static_assert(std::is_same<identity<test::a3>::type, test::a3>{}, "");
static_assert(std::is_same<identity<test::a4>::type, test::a4>{}, "");
static_assert(std::is_same<identity<test::a5>::type, test::a5>{}, "");
static_assert(std::is_same<identity<test::a6>::type, test::a6>{}, "");
static_assert(std::is_same<identity<test::a7>::type, test::a7>{}, "");
static_assert(std::is_same<identity<test::a8>::type, test::a8>{}, "");
static_assert(std::is_same<identity<test::a9>::type, test::a9>{}, "");

static_assert(not_<std::is_same<identity<test::a0>::type, test::a9>>{}, "");
static_assert(not_<std::is_same<identity<test::a1>::type, test::a0>>{}, "");
static_assert(not_<std::is_same<identity<test::a2>::type, test::a1>>{}, "");
static_assert(not_<std::is_same<identity<test::a3>::type, test::a2>>{}, "");
static_assert(not_<std::is_same<identity<test::a4>::type, test::a3>>{}, "");
static_assert(not_<std::is_same<identity<test::a5>::type, test::a4>>{}, "");
static_assert(not_<std::is_same<identity<test::a6>::type, test::a5>>{}, "");
static_assert(not_<std::is_same<identity<test::a7>::type, test::a6>>{}, "");
static_assert(not_<std::is_same<identity<test::a8>::type, test::a7>>{}, "");
static_assert(not_<std::is_same<identity<test::a9>::type, test::a8>>{}, "");
