// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_callable.hpp>

#include "test/atoms.hpp"
#include "test/expressions.hpp"
#include "test/functions.hpp"
#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((not_<is_callable<test::a>>));
METAL_ASSERT((not_<is_callable<test::b>>));
METAL_ASSERT((not_<is_callable<test::c>>));
METAL_ASSERT((not_<is_callable<test::d>>));
METAL_ASSERT((not_<is_callable<test::e>>));
METAL_ASSERT((not_<is_callable<test::f>>));
METAL_ASSERT((not_<is_callable<test::g>>));
METAL_ASSERT((not_<is_callable<test::h>>));
METAL_ASSERT((not_<is_callable<test::i>>));
METAL_ASSERT((not_<is_callable<test::j>>));

METAL_ASSERT((not_<is_callable<test::a, void>>));
METAL_ASSERT((not_<is_callable<test::b, void>>));
METAL_ASSERT((not_<is_callable<test::c, void>>));
METAL_ASSERT((not_<is_callable<test::d, void>>));
METAL_ASSERT((not_<is_callable<test::e, void>>));
METAL_ASSERT((not_<is_callable<test::f, void>>));
METAL_ASSERT((not_<is_callable<test::g, void>>));
METAL_ASSERT((not_<is_callable<test::h, void>>));
METAL_ASSERT((not_<is_callable<test::i, void>>));
METAL_ASSERT((not_<is_callable<test::j, void>>));

METAL_ASSERT((not_<is_callable<test::a, void, void*>>));
METAL_ASSERT((not_<is_callable<test::b, void, void*>>));
METAL_ASSERT((not_<is_callable<test::c, void, void*>>));
METAL_ASSERT((not_<is_callable<test::d, void, void*>>));
METAL_ASSERT((not_<is_callable<test::e, void, void*>>));
METAL_ASSERT((not_<is_callable<test::f, void, void*>>));
METAL_ASSERT((not_<is_callable<test::g, void, void*>>));
METAL_ASSERT((not_<is_callable<test::h, void, void*>>));
METAL_ASSERT((not_<is_callable<test::i, void, void*>>));
METAL_ASSERT((not_<is_callable<test::j, void, void*>>));

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

