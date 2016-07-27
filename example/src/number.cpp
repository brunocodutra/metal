// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [num1]
using num = std::false_type;
/// [num1]

static_assert(metal::is_number<num>::value, "");
)

HIDE(
/// [num2]
using num = std::integral_constant<int, -1>;
/// [num2]

static_assert(metal::is_number<num>::value, "");
)

HIDE(
/// [not_a_num1]
struct not_a_num :
    std::true_type
{};
/// [not_a_num1]

static_assert(!metal::is_number<not_a_num>::value, "");
)

HIDE(
/// [is_number]
static_assert(metal::equal<metal::is_number<metal::number<short, 0>>, metal::true_>::value, "");
static_assert(metal::equal<metal::is_number<metal::int_<-10>>, metal::true_>::value, "");
static_assert(metal::equal<metal::is_number<metal::false_>, metal::true_>::value, "");
static_assert(metal::equal<metal::is_number<metal::true_>, metal::true_>::value, "");
static_assert(metal::equal<metal::is_number<void>, metal::false_>::value, "");
/// [is_number]
)

HIDE(
/// [greater]
static_assert(metal::equal<metal::greater<metal::int_<-10>, metal::number<long, 10>>, metal::false_>::value, "");
static_assert(metal::equal<metal::greater<metal::number<short, 0>, metal::false_>, metal::false_>::value, "");
/// [greater]
)

HIDE(
/// [less]
static_assert(metal::equal<metal::less<metal::int_<-10>, metal::number<long, 10>>, metal::true_>::value, "");
static_assert(metal::equal<metal::less<metal::number<short, 0>, metal::false_>, metal::false_>::value, "");
/// [less]
)

HIDE(
/// [not_]
static_assert(metal::equal<metal::not_<metal::int_<-10>>, metal::false_>::value, "");
static_assert(metal::equal<metal::not_<metal::number<short, 0>>, metal::true_>::value, "");
static_assert(metal::equal<metal::not_<metal::false_>, metal::true_>::value, "");
static_assert(metal::equal<metal::not_<metal::true_>, metal::false_>::value, "");
/// [not_]
)

HIDE(
/// [and_]
using x = metal::and_<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::false_
>;

static_assert(metal::equal<x, metal::false_>::value, "");
/// [and_]
)

HIDE(
/// [or_]
using x = metal::or_<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::false_
>;

static_assert(metal::equal<x, metal::true_>::value, "");
/// [or_]
)


HIDE(
/// [inc]
static_assert(metal::equal<metal::inc<metal::int_<-10>>, metal::int_<-9>>::value, "");
static_assert(metal::equal<metal::inc<metal::number<short, 0>>, metal::number<short, 1>>::value, "");
/// [inc]
)

HIDE(
/// [dec]
static_assert(metal::equal<metal::dec<metal::int_<-10>>, metal::int_<-11>>::value, "");
static_assert(metal::equal<metal::dec<metal::number<short, 0>>, metal::number<short, -1>>::value, "");
/// [dec]
)

HIDE(
/// [neg]
static_assert(metal::equal<metal::neg<metal::int_<-10>>, metal::int_<10>>::value, "");
static_assert(metal::equal<metal::neg<metal::number<short, 0>>, metal::number<short, 0>>::value, "");
/// [neg]
)

HIDE(
/// [add]
using x = metal::add<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(metal::equal<x, metal::number<long, -1>>::value, "");
/// [add]
)

HIDE(
/// [sub]
using x = metal::sub<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(metal::equal<x, metal::number<long, -13>>::value, "");
/// [sub]
)

HIDE(
/// [mul]
using x = metal::mul<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(metal::equal<x, metal::number<long, -35>>::value, "");
/// [mul]
)

HIDE(
/// [div]
using x = metal::div<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(metal::equal<x, metal::number<long, -1>>::value, "");
static_assert(!metal::is_invocable<metal::lambda<metal::div>, metal::int_<1>, metal::int_<0>>::value, "");
/// [div]
)

HIDE(
/// [mod]
using x = metal::mod<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(metal::equal<x, metal::number<long, 0>>::value, "");
static_assert(!metal::is_invocable<metal::lambda<metal::mod>, metal::int_<1>, metal::int_<0>>::value, "");
/// [mod]
)

HIDE(
/// [pow]
using x = metal::pow<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(metal::equal<x, metal::number<long, -16807>>::value, "");
static_assert(!metal::is_invocable<metal::lambda<metal::pow>, metal::int_<0>, metal::int_<-3>>::value, "");
/// [pow]
)

HIDE(
/// [enumerate]
using w = metal::enumerate<metal::int_<2>, metal::int_<2>>;
using x = metal::enumerate<metal::char_<'a'>, metal::int_<3>>;
using y = metal::enumerate<metal::number<long, 2>, metal::int_<3>, metal::int_<-5>>;
using z = metal::enumerate<metal::size_t<2>, metal::int_<-3>, metal::int_<-5>>;

static_assert(metal::equal<w, metal::list<metal::int_<2>, metal::int_<3>>>::value, "");
static_assert(metal::equal<x, metal::list<metal::char_<'a'>, metal::char_<'b'>, metal::char_<'c'>>>::value, "");
static_assert(metal::equal<y, metal::list<metal::number<long, 2>, metal::number<long, -3>, metal::number<long, -8>>>::value, "");
static_assert(metal::equal<z, metal::list<metal::size_t<2>, metal::size_t<7>, metal::size_t<12>>>::value, "");
/// [enumerate]
)
