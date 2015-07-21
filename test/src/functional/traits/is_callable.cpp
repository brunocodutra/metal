// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_callable.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!is_callable_t<test::a0>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a1>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a2>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a3>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a4>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a5>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a6>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a7>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a8>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a9>::value));

METAL_TEST_ASSERT((!is_callable_t<test::a0, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a1, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a2, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a3, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a4, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a5, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a6, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a7, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a8, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a9, void>::value));

METAL_TEST_ASSERT((!is_callable_t<test::a0, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a1, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a2, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a3, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a4, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a5, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a6, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a7, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a8, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::a9, void, void*>::value));

METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::alias>>::value));
METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::empty>>::value));
METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::call>>::value));
METAL_TEST_ASSERT((is_callable_t<test::nullary<test::evaluable>>::value));

METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::alias>, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::empty>, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::call>, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::evaluable>, void>::value));

METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::alias>, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::empty>, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::call>, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::nullary<test::evaluable>, void, void*>::value));

METAL_TEST_ASSERT((!is_callable_t<test::unary<test::alias>>::value));
METAL_TEST_ASSERT((!is_callable_t<test::unary<test::empty>>::value));
METAL_TEST_ASSERT((!is_callable_t<test::unary<test::call>>::value));
METAL_TEST_ASSERT((!is_callable_t<test::unary<test::evaluable>>::value));

METAL_TEST_ASSERT((!is_callable_t<test::unary<test::alias>, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::unary<test::empty>, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::unary<test::call>, void>::value));
METAL_TEST_ASSERT((is_callable_t<test::unary<test::evaluable>, void>::value));

METAL_TEST_ASSERT((!is_callable_t<test::unary<test::alias>, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::unary<test::empty>, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::unary<test::call>, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::unary<test::evaluable>, void, void*>::value));

METAL_TEST_ASSERT((!is_callable_t<test::binary<test::alias>>::value));
METAL_TEST_ASSERT((!is_callable_t<test::binary<test::empty>>::value));
METAL_TEST_ASSERT((!is_callable_t<test::binary<test::call>>::value));
METAL_TEST_ASSERT((!is_callable_t<test::binary<test::evaluable>>::value));

METAL_TEST_ASSERT((!is_callable_t<test::binary<test::alias>, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::binary<test::empty>, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::binary<test::call>, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::binary<test::evaluable>, void>::value));

METAL_TEST_ASSERT((!is_callable_t<test::binary<test::alias>, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::binary<test::empty>, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::binary<test::call>, void, void*>::value));
METAL_TEST_ASSERT((is_callable_t<test::binary<test::evaluable>, void, void*>::value));

METAL_TEST_ASSERT((!is_callable_t<test::n_ary<test::alias>>::value));
METAL_TEST_ASSERT((!is_callable_t<test::n_ary<test::empty>>::value));
METAL_TEST_ASSERT((!is_callable_t<test::n_ary<test::call>>::value));
METAL_TEST_ASSERT((is_callable_t<test::n_ary<test::evaluable>>::value));

METAL_TEST_ASSERT((!is_callable_t<test::n_ary<test::alias>, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::n_ary<test::empty>, void>::value));
METAL_TEST_ASSERT((!is_callable_t<test::n_ary<test::call>, void>::value));
METAL_TEST_ASSERT((is_callable_t<test::n_ary<test::evaluable>, void>::value));

METAL_TEST_ASSERT((!is_callable_t<test::n_ary<test::alias>, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::n_ary<test::empty>, void, void*>::value));
METAL_TEST_ASSERT((!is_callable_t<test::n_ary<test::call>, void, void*>::value));
METAL_TEST_ASSERT((is_callable_t<test::n_ary<test::evaluable>, void, void*>::value));
