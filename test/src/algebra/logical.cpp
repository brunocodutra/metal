// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/algebra/logical.hpp>

#include "test.hpp"

using namespace metal;

struct undefined;

METAL_TEST_ASSERT((or_<std::false_type, std::true_type>::value));
METAL_TEST_ASSERT((or_<std::false_type, std::false_type, std::true_type>::value));
METAL_TEST_ASSERT((or_<std::false_type, std::false_type, std::false_type, std::true_type>::value));
METAL_TEST_ASSERT((or_<std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>::value));
METAL_TEST_ASSERT((or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>::value));
METAL_TEST_ASSERT((or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>::value));
METAL_TEST_ASSERT((or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>::value));

METAL_TEST_ASSERT((!or_<std::false_type, std::false_type>::value));
METAL_TEST_ASSERT((!or_<std::false_type, std::false_type, std::false_type>::value));
METAL_TEST_ASSERT((!or_<std::false_type, std::false_type, std::false_type, std::false_type>::value));
METAL_TEST_ASSERT((!or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>::value));
METAL_TEST_ASSERT((!or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>::value));
METAL_TEST_ASSERT((!or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>::value));
METAL_TEST_ASSERT((!or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>::value));

METAL_TEST_ASSERT((and_<std::true_type, std::true_type>::value));
METAL_TEST_ASSERT((and_<std::true_type, std::true_type, std::true_type>::value));
METAL_TEST_ASSERT((and_<std::true_type, std::true_type, std::true_type, std::true_type>::value));
METAL_TEST_ASSERT((and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>::value));
METAL_TEST_ASSERT((and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>::value));
METAL_TEST_ASSERT((and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>::value));
METAL_TEST_ASSERT((and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>::value));

METAL_TEST_ASSERT((!and_<std::true_type, std::false_type>::value));
METAL_TEST_ASSERT((!and_<std::true_type, std::true_type, std::false_type>::value));
METAL_TEST_ASSERT((!and_<std::true_type, std::true_type, std::true_type, std::false_type>::value));
METAL_TEST_ASSERT((!and_<std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>::value));
METAL_TEST_ASSERT((!and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>::value));
METAL_TEST_ASSERT((!and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>::value));
METAL_TEST_ASSERT((!and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>::value));

METAL_TEST_ASSERT((or_<std::true_type, undefined>::value));
METAL_TEST_ASSERT((or_<std::true_type, undefined, undefined>::value));
METAL_TEST_ASSERT((or_<std::true_type, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((or_<std::true_type, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((or_<std::true_type, undefined, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((or_<std::true_type, undefined, undefined, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((or_<std::true_type, undefined, undefined, undefined, undefined, undefined, undefined, undefined>::value));

METAL_TEST_ASSERT((!and_<std::false_type, undefined>::value));
METAL_TEST_ASSERT((!and_<std::false_type, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_<std::false_type, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_<std::false_type, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_<std::false_type, undefined, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_<std::false_type, undefined, undefined, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_<std::false_type, undefined, undefined, undefined, undefined, undefined, undefined, undefined>::value));
