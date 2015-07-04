/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/algorithm/list.hpp>
#include <metal/functional/traits/is_evaluable.hpp>

#include "test/integrals.hpp"
#include "test/containers.hpp"
#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((not_<is_evaluable<test::none<list>::at, test::zero>>));
METAL_ASSERT((not_<is_evaluable<test::single<list>::at, test::one>>));
METAL_ASSERT((not_<is_evaluable<test::many<list>::at, test::ten>>));

METAL_ASSERT((std::is_same<test::single<list>::at<test::zero>::type, test::a>));

METAL_ASSERT((std::is_same<test::many<list>::at<test::zero>::type, test::a>));
METAL_ASSERT((std::is_same<test::many<list>::at<test::one>::type, test::b>));
METAL_ASSERT((std::is_same<test::many<list>::at<test::two>::type, test::c>));
METAL_ASSERT((std::is_same<test::many<list>::at<test::three>::type, test::d>));
METAL_ASSERT((std::is_same<test::many<list>::at<test::four>::type, test::e>));
METAL_ASSERT((std::is_same<test::many<list>::at<test::five>::type, test::f>));
METAL_ASSERT((std::is_same<test::many<list>::at<test::six>::type, test::g>));
METAL_ASSERT((std::is_same<test::many<list>::at<test::seven>::type, test::h>));
METAL_ASSERT((std::is_same<test::many<list>::at<test::eight>::type, test::i>));
METAL_ASSERT((std::is_same<test::many<list>::at<test::nine>::type, test::j>));

METAL_ASSERT((equal_to<test::none<list>::size, test::zero>));
METAL_ASSERT((equal_to<test::single<list>::size, test::one>));
METAL_ASSERT((equal_to<test::many<list>::size, test::ten>));
