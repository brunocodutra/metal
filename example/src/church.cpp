// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

using true_ = metal::_1;
using false_ = metal::_2;

IS_SAME(metal::invoke<true_, true_, false_>, true_);
IS_SAME(metal::invoke<true_, false_, true_>, false_);
IS_SAME(metal::invoke<false_, true_, false_>, false_);
IS_SAME(metal::invoke<false_, false_, true_>, true_);

using not_ = metal::bind<metal::lambda<metal::invoke>, metal::_1, metal::quote<false_>, metal::quote<true_>>;

IS_SAME(metal::invoke<not_, true_>, false_);
IS_SAME(metal::invoke<not_, false_>, true_);

using and_ = metal::bind<metal::lambda<metal::invoke>, metal::_1, metal::_2, metal::_1>;

IS_SAME(metal::invoke<and_, true_, true_>, true_);
IS_SAME(metal::invoke<and_, true_, false_>, false_);
IS_SAME(metal::invoke<and_, false_, true_>, false_);
IS_SAME(metal::invoke<and_, false_, false_>, false_);

using or_ = metal::bind<metal::lambda<metal::invoke>, metal::_1, metal::_1, metal::_2>;

IS_SAME(metal::invoke<or_, true_, true_>, true_);
IS_SAME(metal::invoke<or_, true_, false_>, true_);
IS_SAME(metal::invoke<or_, false_, true_>, true_);
IS_SAME(metal::invoke<or_, false_, false_>, false_);

using xor_ = metal::bind<metal::lambda<metal::invoke>, metal::_1, metal::bind<not_, metal::_2>, metal::_2>;

IS_SAME(metal::invoke<xor_, true_, true_>, false_);
IS_SAME(metal::invoke<xor_, true_, false_>, true_);
IS_SAME(metal::invoke<xor_, false_, true_>, true_);
IS_SAME(metal::invoke<xor_, false_, false_>, false_);
