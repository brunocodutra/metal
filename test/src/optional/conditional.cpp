// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((conditional_t<test::n0, boolean<false>, boolean<true>>::value));
METAL_TEST_ASSERT((conditional_t<test::n1, boolean<true>, boolean<false>>::value));

using x = just<test::v0>;
using y = just<test::v1>;
using z = just<test::v2>;
using w = just<test::v3>;

METAL_TEST_ASSERT((!is_just<conditional<boolean<false>, x>>::value));
METAL_TEST_ASSERT((!is_just<conditional<boolean<true>, nothing>>::value));
METAL_TEST_ASSERT((is_just<conditional<boolean<true>, x>>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<true>, x>, x::type>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<true>, x, y>, x::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<false>, x, y>, y::type>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<true>, x, boolean<true>, y>, x::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<false>, x, boolean<true>, y>, y::type>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<true>, x, boolean<true>, y, z>, x::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<false>, x, boolean<true>, y, z>, y::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<false>, x, boolean<false>, y, z>, z::type>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<true>, x, boolean<true>, y, boolean<true>, z>, x::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<false>, x, boolean<true>, y, boolean<true>, z>, y::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<false>, x, boolean<false>, y, boolean<true>, z>, z::type>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<true>, x, boolean<true>, y, boolean<true>, z, w>, x::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<false>, x, boolean<true>, y, boolean<true>, z, w>, y::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<false>, x, boolean<false>, y, boolean<true>, z, w>, z::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<boolean<false>, x, boolean<false>, y, boolean<false>, z, w>, w::type>::value));





