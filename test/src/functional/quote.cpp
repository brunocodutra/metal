// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/quote.hpp>
#include <metal/functional/traits/is_function.hpp>
#include <metal/functional/traits/is_callable.hpp>

#include "test.hpp"

using namespace metal;

using f1 = quote<test::alias>;
using f2 = quote<test::empty>;
using f3 = quote<test::call>;

METAL_TEST_ASSERT((is_function<f1>::value));
METAL_TEST_ASSERT((is_function<f2>::value));
METAL_TEST_ASSERT((is_function<f3>::value));

METAL_TEST_ASSERT((!is_callable<f1>::value));
METAL_TEST_ASSERT((!is_callable<f2>::value));
METAL_TEST_ASSERT((!is_callable<f3>::value));
