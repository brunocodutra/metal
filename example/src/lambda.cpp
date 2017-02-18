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
/// [is_lambda]
IS_SAME(metal::is_lambda<void>, metal::false_);
IS_SAME(metal::is_lambda<metal::lambda<std::add_pointer_t>>, metal::true_);
/// [is_lambda]
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

HIDE(
/// [partial]
using promote = metal::partial<metal::lambda<std::common_type_t>, int>;

IS_SAME(metal::invoke<promote, char>, int);
IS_SAME(metal::invoke<promote, short>, int);
IS_SAME(metal::invoke<promote, long>, long);
/// [partial]
)

HIDE(
/// [quote]
using void_ = metal::quote<void>;

IS_SAME(metal::invoke<void_>, void);
IS_SAME(metal::invoke<void_, short, int, long>, void);
IS_SAME(metal::invoke<metal::quote<void_>, short, int, long>, void_);
/// [quote]
)

HIDE(
/// [arg]
IS_SAME(metal::invoke<metal::arg<1>, bool, char, long, float>, bool);
IS_SAME(metal::invoke<metal::arg<2>, bool, char, long, float>, char);
IS_SAME(metal::invoke<metal::arg<3>, bool, char, long, float>, long);
IS_SAME(metal::invoke<metal::arg<4>, bool, char, long, float>, float);
/// [arg]
)

HIDE(
/// [bind]
using promote = metal::bind<
    metal::lambda<std::common_type_t>,
    metal::quote<int>,
    metal::_1 // equivalent to metal::arg<1>
>;

IS_SAME(metal::invoke<promote, char>, int);
IS_SAME(metal::invoke<promote, short>, int);
IS_SAME(metal::invoke<promote, long>, long);

using uac = metal::bind< // usual arithmetic conversion
    metal::lambda<std::common_type_t>,
    metal::bind<promote, metal::_1>,
    metal::bind<promote, metal::_2>
>;

IS_SAME(metal::invoke<uac, int, long>, long);
IS_SAME(metal::invoke<uac, char, char>, int);
IS_SAME(metal::invoke<uac, short, float>, float);
/// [bind]
)
