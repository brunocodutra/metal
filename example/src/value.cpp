// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [val1]
using val = int;
/// [val1]

IS_SAME(metal::is_value<val>, metal::true_);
)

HIDE(
/// [val2]
using val = decltype(3.14);
/// [val2]

IS_SAME(metal::is_value<val>, metal::true_);
)

HIDE(
/// [val3]
struct val { /*...*/ };
/// [val3]

IS_SAME(metal::is_value<val>, metal::true_);
)

HIDE(
/// [not_a_val1]
int not_a_val;
/// [not_a_val1]
)

#if !defined(METAL_COMPAT_MODE)

HIDE(
static constexpr
/// [not_a_val2]
decltype(auto) not_a_val = 3.14;
/// [not_a_val2]
)

#endif

HIDE(
/// [not_a_val3]
template<typename...>
struct not_a_val { /*...*/ };
/// [not_a_val3]
)

HIDE(
/// [value]
using num = metal::number<42>;
IS_SAME(metal::is_number<metal::value<num>>, metal::false_);
IS_SAME(metal::value<num>::type, num);

using lbd = metal::lambda<metal::identity>;
IS_SAME(metal::is_lambda<metal::value<lbd>>, metal::false_);
IS_SAME(metal::value<lbd>::type, lbd);

using list = metal::list<>;
IS_SAME(metal::is_list<metal::value<list>>, metal::false_);
IS_SAME(metal::value<list>::type, list);
/// [value]
)

HIDE(
/// [is_value]
template<typename T, typename = metal::true_>
struct has_type_impl :
    metal::false_
{};

template<typename T>
struct has_type_impl<T, metal::is_value<typename T::type>> :
    metal::true_
{};

template<typename T>
using has_type = typename has_type_impl<T>::type;


IS_SAME(has_type<metal::value<void>>, metal::true_);
IS_SAME(has_type<metal::value<>>, metal::false_);
/// [is_value]
)

HIDE(
/// [eval]
IS_SAME(metal::eval<metal::value<void>>, void);
IS_SAME(metal::eval<std::add_pointer<void>>, void*);
/// [eval]
)

HIDE(
/// [identity]
IS_SAME(metal::identity<void>, void);
IS_SAME(metal::invoke<metal::lambda<metal::identity>, void>, void);

template<typename pred, typename lbd, typename seq>
using transform_if = metal::transform<
    metal::bind<metal::lambda<metal::if_>, pred, lbd, metal::lambda<metal::identity>>,
    seq
>;

using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    transform_if<metal::trait<std::is_integral>, metal::lazy<std::add_pointer>, l>,
    metal::list<short*, int*, long*, float, double, void>
);
/// [identity]
)

HIDE(
/// [same]
IS_SAME(metal::same<>, metal::true_);
IS_SAME(metal::same<void>, metal::true_);
IS_SAME(metal::same<void, void, void, void, void>, metal::true_);
IS_SAME(metal::same<void, void*, void, void, void>, metal::false_);
IS_SAME(metal::same<void, void*, void**, void***, void****>, metal::false_);
/// [same]
)

HIDE(
/// [distinct]
IS_SAME(metal::distinct<>, metal::true_);
IS_SAME(metal::distinct<void>, metal::true_);
IS_SAME(metal::distinct<void, void, void, void, void>, metal::false_);
IS_SAME(metal::distinct<void, void*, void, void, void>, metal::false_);
IS_SAME(metal::distinct<void, void*, void**, void***, void****>, metal::true_);
/// [distinct]
)

HIDE(
/// [fold_left]
template<typename x, typename y>
struct f {};

using lbd = metal::lambda<f>;

IS_SAME(
    metal::fold_left<lbd, short, int, long, float, double, void>,
    f<f<f<f<f<short, int>, long>, float>, double>, void>
);
/// [fold_left]
)

HIDE(
/// [fold_right]
template<typename x, typename y>
struct f {};

using lbd = metal::lambda<f>;

IS_SAME(
    metal::fold_right<lbd, short, int, long, float, double, void>,
    f<short, f<int, f<long, f<float, f<double, void>>>>>
);
/// [fold_right]
)
