// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_applicable.hpp>
#include <metal/functional/arg.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!is_applicable_t<test::v0>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v1>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v2>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v3>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v4>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v5>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v6>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v7>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v8>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v9>::value));

METAL_TEST_ASSERT((!is_applicable_t<test::v0, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v1, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v2, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v3, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v4, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v5, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v6, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v7, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v8, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v9, void>::value));

METAL_TEST_ASSERT((!is_applicable_t<test::v0, void, void*>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v1, void, void*>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v2, void, void*>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v3, void, void*>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v4, void, void*>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v5, void, void*>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v6, void, void*>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v7, void, void*>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v8, void, void*>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::v9, void, void*>::value));

METAL_TEST_ASSERT((!is_applicable_t<test::empty<>>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::empty<>, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::empty<>, void, void*>::value));

METAL_TEST_ASSERT((is_applicable_t<test::e0<>>::value));
METAL_TEST_ASSERT((is_applicable_t<test::e0<>, void>::value));
METAL_TEST_ASSERT((is_applicable_t<test::e0<>, void, void*>::value));

METAL_TEST_ASSERT((!is_applicable_t<test::e1<_1>>::value));
METAL_TEST_ASSERT((is_applicable_t<test::e1<_1>, void>::value));
METAL_TEST_ASSERT((is_applicable_t<test::e1<_1>, void, void*>::value));

METAL_TEST_ASSERT((!is_applicable_t<test::e2<_1, _2>>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::e2<_1, _2>, void>::value));
METAL_TEST_ASSERT((is_applicable_t<test::e2<_1, _2>, void, void*>::value));

METAL_TEST_ASSERT((!is_applicable_t<test::en<_1, _2, _3>>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::en<_1, _2, _3>, void>::value));
METAL_TEST_ASSERT((!is_applicable_t<test::en<_1, _2, _3>, void, void*>::value));
