// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_same_expression.hpp>

#include "test/expressions.hpp"
#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((is_same_expression<test::e0, test::e0>));
METAL_ASSERT((is_same_expression<test::e1, test::e1>));
METAL_ASSERT((is_same_expression<test::e2, test::e2>));
METAL_ASSERT((is_same_expression<test::en, test::en>));

METAL_ASSERT((not_<is_same_expression<test::e0, test::en>>));
METAL_ASSERT((not_<is_same_expression<test::e1, test::e0>>));
METAL_ASSERT((not_<is_same_expression<test::e2, test::e1>>));
METAL_ASSERT((not_<is_same_expression<test::en, test::e2>>));
