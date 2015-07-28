// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((conditional_t<test::n0, std::false_type, std::true_type>::value));
METAL_TEST_ASSERT((conditional_t<test::n1, std::true_type, std::false_type>::value));

using x = just<test::v0>;
using y = just<test::v1>;
using z = just<test::v2>;
using w = just<test::v3>;

METAL_TEST_ASSERT((!is_just<conditional<void, x>>::value));
METAL_TEST_ASSERT((!is_just<conditional<std::false_type, x>>::value));
METAL_TEST_ASSERT((!is_just<conditional<std::true_type, nothing>>::value));
METAL_TEST_ASSERT((is_just<conditional<std::true_type, x>>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x>, x::type>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x, y>, x::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, y>, y::type>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x, std::true_type, y>, x::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::true_type, y>, y::type>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x, std::true_type, y, z>, x::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::true_type, y, z>, y::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::false_type, y, z>, z::type>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x, std::true_type, y, std::true_type, z>, x::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::true_type, y, std::true_type, z>, y::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::false_type, y, std::true_type, z>, z::type>::value));

METAL_TEST_ASSERT((std::is_same<conditional_t<std::true_type, x, std::true_type, y, std::true_type, z, w>, x::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::true_type, y, std::true_type, z, w>, y::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::false_type, y, std::true_type, z, w>, z::type>::value));
METAL_TEST_ASSERT((std::is_same<conditional_t<std::false_type, x, std::false_type, y, std::false_type, z, w>, w::type>::value));





