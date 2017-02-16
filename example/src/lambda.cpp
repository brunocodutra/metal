// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [lbd1]
using lbd = metal::lambda<std::add_pointer_t>;
/// [lbd1]

IS_SAME(metal::is_lambda<lbd>, metal::true_);
)

HIDE(
/// [is_invocable]
template<typename val>
using array = typename metal::value<val[]>::type; // MSVC friendly

using lbd = metal::lambda<array>;

IS_SAME(metal::is_invocable<lbd, int, int>, metal::false_); // arity mismatch
IS_SAME(metal::is_invocable<lbd, void>, metal::false_); // void[] is ill-formed
IS_SAME(metal::is_invocable<lbd, int>, metal::true_);
/// [is_invocable]
)

HIDE(
/// [invoke]
using lbd = metal::lambda<std::common_type_t>;

IS_SAME(metal::invoke<lbd, bool, char, long, float>, float);
/// [invoke]
)

HIDE(
/// [apply]
using lbd = metal::lambda<std::common_type_t>;
using l = metal::list<bool, char, long, float>;

IS_SAME(metal::apply<lbd, l>, float);
/// [apply]
)
