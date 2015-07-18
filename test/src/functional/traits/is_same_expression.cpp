// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_same_expression.hpp>

#include "test.hpp"

using namespace metal;

static_assert(is_same_expression_t<test::e0, test::e0>::value, "");
static_assert(is_same_expression_t<test::e1, test::e1>::value, "");
static_assert(is_same_expression_t<test::e2, test::e2>::value, "");
static_assert(is_same_expression_t<test::en, test::en>::value, "");

static_assert(!is_same_expression_t<test::e0, test::en>::value, "");
static_assert(!is_same_expression_t<test::e1, test::e0>::value, "");
static_assert(!is_same_expression_t<test::e2, test::e1>::value, "");
static_assert(!is_same_expression_t<test::en, test::e2>::value, "");
