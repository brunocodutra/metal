// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_same_expression.hpp>

#include "test/expressions.hpp"
#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((is_same_expression<test::alias, test::alias>));
METAL_ASSERT((is_same_expression<test::empty, test::empty>));
METAL_ASSERT((is_same_expression<test::call, test::call>));
METAL_ASSERT((is_same_expression<test::evaluable, test::evaluable>));
METAL_ASSERT((is_same_expression<test::evaluable_union, test::evaluable_union>));

METAL_ASSERT((not_<is_same_expression<test::alias, test::evaluable_union>>));
METAL_ASSERT((not_<is_same_expression<test::empty, test::alias>>));
METAL_ASSERT((not_<is_same_expression<test::call, test::empty>>));
METAL_ASSERT((not_<is_same_expression<test::evaluable, test::call>>));
METAL_ASSERT((not_<is_same_expression<test::evaluable_union, test::evaluable>>));
