// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/quote.hpp>
#include <metal/functional/traits/is_function.hpp>
#include <metal/functional/traits/is_callable.hpp>

#include "test.hpp"

using namespace metal;

using q1 = quote<test::alias>;
using q2 = quote<test::empty>;
using q3 = quote<test::call>;
using q4 = quote<test::evaluable>;

static_assert(is_function<q1>::value, "");
static_assert(is_function<q2>::value, "");
static_assert(is_function<q3>::value, "");
static_assert(is_function<q4>::value, "");

static_assert(not_<is_callable<q1>>::value, "");
static_assert(not_<is_callable<q2>>::value, "");
static_assert(not_<is_callable<q3>>::value, "");
static_assert(is_callable<q4>::value, "");

static_assert(std::is_same<call_t<q4>, q4::call<>::type>::value, "");
