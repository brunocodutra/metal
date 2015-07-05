// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_function.hpp>

#include "test/types.hpp"
#include "test/functions.hpp"
#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((not_<is_function<test::a>>));
METAL_ASSERT((not_<is_function<test::b>>));
METAL_ASSERT((not_<is_function<test::c>>));
METAL_ASSERT((not_<is_function<test::d>>));
METAL_ASSERT((not_<is_function<test::e>>));
METAL_ASSERT((not_<is_function<test::f>>));
METAL_ASSERT((not_<is_function<test::g>>));
METAL_ASSERT((not_<is_function<test::h>>));
METAL_ASSERT((not_<is_function<test::i>>));
METAL_ASSERT((not_<is_function<test::j>>));

METAL_ASSERT((not_<is_function<test::call<>>>));

METAL_ASSERT((is_function<test::unary<test::incomplete>>));
METAL_ASSERT((is_function<test::unary<test::empty>>));
METAL_ASSERT((is_function<test::unary<test::evaluable>>));
METAL_ASSERT((is_function<test::unary<test::call>>));

METAL_ASSERT((is_function<test::binary<test::incomplete>>));
METAL_ASSERT((is_function<test::binary<test::empty>>));
METAL_ASSERT((is_function<test::binary<test::evaluable>>));
METAL_ASSERT((is_function<test::binary<test::call>>));

METAL_ASSERT((is_function<test::n_ary<test::incomplete>>));
METAL_ASSERT((is_function<test::n_ary<test::empty>>));
METAL_ASSERT((is_function<test::n_ary<test::evaluable>>));
METAL_ASSERT((is_function<test::n_ary<test::call>>));
