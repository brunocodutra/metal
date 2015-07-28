// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/logical.hpp>

#include "test.hpp"

using namespace metal;

struct undefined;

METAL_TEST_ASSERT((!query_t<undefined>::value));
METAL_TEST_ASSERT((!query_t<test::n0>::value));
METAL_TEST_ASSERT((query_t<test::n1>::value));
METAL_TEST_ASSERT((query_t<test::n2>::value));
METAL_TEST_ASSERT((query_t<test::n3>::value));
METAL_TEST_ASSERT((query_t<test::n4>::value));
METAL_TEST_ASSERT((query_t<test::n5>::value));
METAL_TEST_ASSERT((query_t<test::n6>::value));
METAL_TEST_ASSERT((query_t<test::n7>::value));
METAL_TEST_ASSERT((query_t<test::n8>::value));
METAL_TEST_ASSERT((query_t<test::n9>::value));

METAL_TEST_ASSERT((or_t<test::n1>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n2>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n3>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n4>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n0, test::n5>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n6>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n7>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n8>::value));
METAL_TEST_ASSERT((or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n8, test::n9>::value));

METAL_TEST_ASSERT((!or_t<test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0>::value));
METAL_TEST_ASSERT((!or_t<test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0, test::n0>::value));

METAL_TEST_ASSERT((and_t<test::n1>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4, test::n5>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7, test::n8>::value));
METAL_TEST_ASSERT((and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7, test::n8, test::n9>::value));

METAL_TEST_ASSERT((!and_t<test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n4, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7, test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n1, test::n2, test::n3, test::n4, test::n5, test::n6, test::n7, test::n8, test::n0>::value));

METAL_TEST_ASSERT((or_t<test::n1>::value));
METAL_TEST_ASSERT((or_t<test::n2, undefined>::value));
METAL_TEST_ASSERT((or_t<test::n3, undefined, undefined>::value));
METAL_TEST_ASSERT((or_t<test::n4, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((or_t<test::n5, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((or_t<test::n6, undefined, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((or_t<test::n7, undefined, undefined, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((or_t<test::n8, undefined, undefined, undefined, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((or_t<test::n9, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined>::value));

METAL_TEST_ASSERT((!and_t<test::n0>::value));
METAL_TEST_ASSERT((!and_t<test::n0, undefined>::value));
METAL_TEST_ASSERT((!and_t<test::n0, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_t<test::n0, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_t<test::n0, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_t<test::n0, undefined, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_t<test::n0, undefined, undefined, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_t<test::n0, undefined, undefined, undefined, undefined, undefined, undefined, undefined>::value));
METAL_TEST_ASSERT((!and_t<test::n0, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined>::value));

