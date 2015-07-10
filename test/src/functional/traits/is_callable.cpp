// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_callable.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

METAL_ASSERT((not_<is_callable<test::a0>>));
METAL_ASSERT((not_<is_callable<test::a1>>));
METAL_ASSERT((not_<is_callable<test::a2>>));
METAL_ASSERT((not_<is_callable<test::a3>>));
METAL_ASSERT((not_<is_callable<test::a4>>));
METAL_ASSERT((not_<is_callable<test::a5>>));
METAL_ASSERT((not_<is_callable<test::a6>>));
METAL_ASSERT((not_<is_callable<test::a7>>));
METAL_ASSERT((not_<is_callable<test::a9>>));
METAL_ASSERT((not_<is_callable<test::a9>>));

METAL_ASSERT((not_<is_callable<test::a0, void>>));
METAL_ASSERT((not_<is_callable<test::a1, void>>));
METAL_ASSERT((not_<is_callable<test::a2, void>>));
METAL_ASSERT((not_<is_callable<test::a3, void>>));
METAL_ASSERT((not_<is_callable<test::a4, void>>));
METAL_ASSERT((not_<is_callable<test::a5, void>>));
METAL_ASSERT((not_<is_callable<test::a6, void>>));
METAL_ASSERT((not_<is_callable<test::a7, void>>));
METAL_ASSERT((not_<is_callable<test::a9, void>>));
METAL_ASSERT((not_<is_callable<test::a9, void>>));

METAL_ASSERT((not_<is_callable<test::a0, void, void*>>));
METAL_ASSERT((not_<is_callable<test::a1, void, void*>>));
METAL_ASSERT((not_<is_callable<test::a2, void, void*>>));
METAL_ASSERT((not_<is_callable<test::a3, void, void*>>));
METAL_ASSERT((not_<is_callable<test::a4, void, void*>>));
METAL_ASSERT((not_<is_callable<test::a5, void, void*>>));
METAL_ASSERT((not_<is_callable<test::a6, void, void*>>));
METAL_ASSERT((not_<is_callable<test::a7, void, void*>>));
METAL_ASSERT((not_<is_callable<test::a9, void, void*>>));
METAL_ASSERT((not_<is_callable<test::a9, void, void*>>));

METAL_ASSERT((not_<is_callable<test::unary<test::alias>>>));
METAL_ASSERT((not_<is_callable<test::unary<test::empty>>>));
METAL_ASSERT((not_<is_callable<test::unary<test::call>>>));
METAL_ASSERT((not_<is_callable<test::unary<test::evaluable>>>));
METAL_ASSERT((not_<is_callable<test::unary<test::evaluable_union>>>));

METAL_ASSERT((not_<is_callable<test::unary<test::alias>, void>>));
METAL_ASSERT((not_<is_callable<test::unary<test::empty>, void>>));
METAL_ASSERT((not_<is_callable<test::unary<test::call>, void>>));
METAL_ASSERT((is_callable<test::unary<test::evaluable>, void>));
METAL_ASSERT((is_callable<test::unary<test::evaluable_union>, void>));

METAL_ASSERT((not_<is_callable<test::unary<test::alias>, void, void*>>));
METAL_ASSERT((not_<is_callable<test::unary<test::empty>, void, void*>>));
METAL_ASSERT((not_<is_callable<test::unary<test::call>, void, void*>>));
METAL_ASSERT((not_<is_callable<test::unary<test::evaluable>, void, void*>>));
METAL_ASSERT((not_<is_callable<test::unary<test::evaluable_union>, void, void*>>));

METAL_ASSERT((not_<is_callable<test::binary<test::alias>>>));
METAL_ASSERT((not_<is_callable<test::binary<test::empty>>>));
METAL_ASSERT((not_<is_callable<test::binary<test::call>>>));
METAL_ASSERT((not_<is_callable<test::binary<test::evaluable>>>));
METAL_ASSERT((not_<is_callable<test::binary<test::evaluable_union>>>));

METAL_ASSERT((not_<is_callable<test::binary<test::alias>, void>>));
METAL_ASSERT((not_<is_callable<test::binary<test::empty>, void>>));
METAL_ASSERT((not_<is_callable<test::binary<test::call>, void>>));
METAL_ASSERT((not_<is_callable<test::binary<test::evaluable>, void>>));
METAL_ASSERT((not_<is_callable<test::binary<test::evaluable_union>, void>>));

METAL_ASSERT((not_<is_callable<test::binary<test::alias>, void, void*>>));
METAL_ASSERT((not_<is_callable<test::binary<test::empty>, void, void*>>));
METAL_ASSERT((not_<is_callable<test::binary<test::call>, void, void*>>));
METAL_ASSERT((is_callable<test::binary<test::evaluable>, void, void*>));
METAL_ASSERT((is_callable<test::binary<test::evaluable_union>, void, void*>));

METAL_ASSERT((not_<is_callable<test::n_ary<test::alias>>>));
METAL_ASSERT((not_<is_callable<test::n_ary<test::empty>>>));
METAL_ASSERT((not_<is_callable<test::n_ary<test::call>>>));
METAL_ASSERT((is_callable<test::n_ary<test::evaluable>>));
METAL_ASSERT((is_callable<test::n_ary<test::evaluable_union>>));

METAL_ASSERT((not_<is_callable<test::n_ary<test::alias>, void>>));
METAL_ASSERT((not_<is_callable<test::n_ary<test::empty>, void>>));
METAL_ASSERT((not_<is_callable<test::n_ary<test::call>, void>>));
METAL_ASSERT((is_callable<test::n_ary<test::evaluable>, void>));
METAL_ASSERT((is_callable<test::n_ary<test::evaluable_union>, void>));

METAL_ASSERT((not_<is_callable<test::n_ary<test::alias>, void, void*>>));
METAL_ASSERT((not_<is_callable<test::n_ary<test::empty>, void, void*>>));
METAL_ASSERT((not_<is_callable<test::n_ary<test::call>, void, void*>>));
METAL_ASSERT((is_callable<test::n_ary<test::evaluable>, void, void*>));
METAL_ASSERT((is_callable<test::n_ary<test::evaluable_union>, void, void*>));

