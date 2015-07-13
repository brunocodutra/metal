// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/arg.hpp>
#include <metal/functional/traits/is_function.hpp>
#include <metal/functional/traits/is_callable.hpp>
#include <metal/algebra/logical/not.hpp>

#include "test.hpp"

using namespace metal;
using namespace metal::placeholders;

static_assert(not_<is_function<_0>>::value, "");
static_assert(is_function<_1>::value, "");
static_assert(is_function<_2>::value, "");
static_assert(is_function<_3>::value, "");
static_assert(is_function<_4>::value, "");

static_assert(not_<is_callable<_0, test::a0, test::a1, test::a2, test::a3>>::value, "");
static_assert(is_callable<_1, test::a0, test::a1, test::a2, test::a3>::value, "");
static_assert(is_callable<_2, test::a0, test::a1, test::a2, test::a3>::value, "");
static_assert(is_callable<_3, test::a0, test::a1, test::a2, test::a3>::value, "");
static_assert(is_callable<_4, test::a0, test::a1, test::a2, test::a3>::value, "");

static_assert(not_<is_callable<_0>>::value, "");
static_assert(not_<is_callable<_1>>::value, "");
static_assert(not_<is_callable<_2, test::a1>>::value, "");
static_assert(not_<is_callable<_3, test::a1, test::a2>>::value, "");
static_assert(not_<is_callable<_4, test::a1, test::a2, test::a3>>::value, "");

static_assert(std::is_same<call_t<_1, test::a0, test::a1, test::a2, test::a3>, test::a0>::value, "");
static_assert(std::is_same<call_t<_2, test::a0, test::a1, test::a2, test::a3>, test::a1>::value, "");
static_assert(std::is_same<call_t<_3, test::a0, test::a1, test::a2, test::a3>, test::a2>::value, "");
static_assert(std::is_same<call_t<_4, test::a0, test::a1, test::a2, test::a3>, test::a3>::value, "");
