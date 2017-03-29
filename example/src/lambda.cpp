// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

#include <memory>
#include <tuple>
#include <type_traits>

#if !defined(METAL_COMPAT_MODE)

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
IS_SAME(metal::is_lambda<metal::trait<std::is_pointer>>, metal::true_);
IS_SAME(metal::is_lambda<metal::lazy<std::add_pointer>>, metal::true_);
/// [is_lambda]
)

HIDE(
/// [as_lambda]
IS_SAME(metal::as_lambda<std::shared_ptr<int>>, metal::lambda<std::shared_ptr>);
IS_SAME(metal::as_lambda<std::unique_ptr<int>>, metal::lambda<std::unique_ptr>);
IS_SAME(metal::as_lambda<std::tuple<int, char, float>>, metal::lambda<std::tuple>);
/// [as_lambda]
)

HIDE(
/// [trait]
IS_SAME(metal::invoke<metal::trait<std::is_fundamental>, int>, metal::true_);
IS_SAME(metal::invoke<metal::trait<std::is_fundamental>, void>, metal::true_);

IS_SAME(metal::invoke<metal::trait<std::is_integral>, int>, metal::true_);
IS_SAME(metal::invoke<metal::trait<std::is_integral>, void>, metal::false_);

IS_SAME(metal::invoke<metal::trait<std::is_class>, int>, metal::false_);
IS_SAME(metal::invoke<metal::trait<std::is_class>, void>, metal::false_);

IS_SAME(metal::invoke<metal::trait<std::is_convertible>, int*, void*>, metal::true_);
IS_SAME(metal::invoke<metal::trait<std::is_convertible>, void*, int*>, metal::false_);
/// [trait]
)

HIDE(
/// [lazy]
IS_SAME(metal::invoke<metal::lazy<std::add_pointer>, int>, int*);
IS_SAME(metal::invoke<metal::lazy<std::decay>, int()>, int(*)());
IS_SAME(metal::invoke<metal::lazy<std::common_type>, int[], void*>, void*);
/// [lazy]
)

HIDE(
/// [is_invocable]
template<typename val>
using array = metal::eval<metal::value<val[]>>; // MSVC friendly

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

IS_SAME(metal::apply<lbd, metal::list<bool, char, long, float>>, float);
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
/// [always]
using void_ = metal::always<void>;

IS_SAME(metal::invoke<void_>, void);
IS_SAME(metal::invoke<void_, short, int, long>, void);
IS_SAME(metal::invoke<metal::always<void_>, short, int, long>, void_);
/// [always]
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
    metal::always<int>,
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

#endif
