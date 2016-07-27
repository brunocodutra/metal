// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

using true_ = metal::_1;
using false_ = metal::_2;

static_assert(metal::equal<metal::invoke<true_, true_, false_>, true_>::value, "");
static_assert(metal::equal<metal::invoke<true_, false_, true_>, false_>::value, "");
static_assert(metal::equal<metal::invoke<false_, true_, false_>, false_>::value, "");
static_assert(metal::equal<metal::invoke<false_, false_, true_>, true_>::value, "");

using not_ = metal::bind<metal::lambda<metal::invoke>, metal::_1, metal::quote<false_>, metal::quote<true_>>;

static_assert(metal::equal<metal::invoke<not_, true_>, false_>::value, "");
static_assert(metal::equal<metal::invoke<not_, false_>, true_>::value, "");

using and_ = metal::bind<metal::lambda<metal::invoke>, metal::_1, metal::_2, metal::_1>;

static_assert(metal::equal<metal::invoke<and_, true_, true_>, true_>::value, "");
static_assert(metal::equal<metal::invoke<and_, true_, false_>, false_>::value, "");
static_assert(metal::equal<metal::invoke<and_, false_, true_>, false_>::value, "");
static_assert(metal::equal<metal::invoke<and_, false_, false_>, false_>::value, "");

using or_ = metal::bind<metal::lambda<metal::invoke>, metal::_1, metal::_1, metal::_2>;

static_assert(metal::equal<metal::invoke<or_, true_, true_>, true_>::value, "");
static_assert(metal::equal<metal::invoke<or_, true_, false_>, true_>::value, "");
static_assert(metal::equal<metal::invoke<or_, false_, true_>, true_>::value, "");
static_assert(metal::equal<metal::invoke<or_, false_, false_>, false_>::value, "");

using xor_ = metal::bind<metal::lambda<metal::invoke>, metal::_1, metal::bind<not_, metal::_2>, metal::_2>;

static_assert(metal::equal<metal::invoke<xor_, true_, true_>, false_>::value, "");
static_assert(metal::equal<metal::invoke<xor_, true_, false_>, true_>::value, "");
static_assert(metal::equal<metal::invoke<xor_, false_, true_>, true_>::value, "");
static_assert(metal::equal<metal::invoke<xor_, false_, false_>, false_>::value, "");
