#include <metal.hpp>

#include "example.hpp"

/// [bool]
using true_ = metal::_1;
using false_ = metal::_2;
/// [bool]

IS_SAME(metal::invoke<true_, true_, false_>, true_);
IS_SAME(metal::invoke<true_, false_, true_>, false_);
IS_SAME(metal::invoke<false_, true_, false_>, false_);
IS_SAME(metal::invoke<false_, false_, true_>, true_);

HIDE(
/// [not_expr]
template<typename b>
using not_ = metal::invoke<b, false_, true_>;

IS_SAME(not_<true_>, false_);
IS_SAME(not_<false_>, true_);
/// [not_expr]
)

/// [not]
using not_ = metal::bind<
    metal::lambda<metal::invoke>,
    metal::_1, metal::always<false_>, metal::always<true_>
>;

IS_SAME(metal::invoke<not_, true_>, false_);
IS_SAME(metal::invoke<not_, false_>, true_);
/// [not]

/// [and]
// λx λy x y x
using and_ = metal::bind<
    metal::lambda<metal::invoke>,
    metal::_1, metal::_2, metal::_1
>;

IS_SAME(metal::invoke<and_, true_, true_>, true_);
IS_SAME(metal::invoke<and_, true_, false_>, false_);
IS_SAME(metal::invoke<and_, false_, true_>, false_);
IS_SAME(metal::invoke<and_, false_, false_>, false_);
/// [and]

/// [or]
// λx λy x x y
using or_ = metal::bind<
    metal::lambda<metal::invoke>,
    metal::_1, metal::_1, metal::_2
>;

IS_SAME(metal::invoke<or_, true_, true_>, true_);
IS_SAME(metal::invoke<or_, true_, false_>, true_);
IS_SAME(metal::invoke<or_, false_, true_>, true_);
IS_SAME(metal::invoke<or_, false_, false_>, false_);
/// [or]

/// [xor]
// λx λy x (not y) y
using xor_ = metal::bind<
    metal::lambda<metal::invoke>,
    metal::_1, metal::bind<not_, metal::_2>, metal::_2
>;

IS_SAME(metal::invoke<xor_, true_, true_>, false_);
IS_SAME(metal::invoke<xor_, true_, false_>, true_);
IS_SAME(metal::invoke<xor_, false_, true_>, true_);
IS_SAME(metal::invoke<xor_, false_, false_>, false_);
/// [xor]
