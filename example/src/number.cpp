// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [num1]
using num = metal::false_;
/// [num1]

ASSERT(metal::is_number<num>);
)

HIDE(
/// [num2]
using num = metal::int_<-1>;
/// [num2]

ASSERT(metal::is_number<num>);
)

HIDE(
/// [not_a_num1]
struct not_a_num :
    metal::true_
{};
/// [not_a_num1]

ASSERT(!metal::is_number<not_a_num>);
)

HIDE(
/// [is_number]
ASSERT(metal::is_number<metal::number<short, 0>>);
ASSERT(metal::is_number<metal::int_<-10>>);
ASSERT(metal::is_number<metal::char_<'a'>>);
ASSERT(metal::is_number<metal::true_>);
ASSERT(!metal::is_number<void>);
/// [is_number]
)

HIDE(
/// [cast]
using num = metal::int_<-10>;

ASSERT(std::is_same<metal::cast<num, bool>, metal::true_>);
ASSERT(std::is_same<metal::cast<num, short>, metal::number<short, -10>>);
ASSERT(!metal::is_invocable<metal::lambda<metal::cast>, num, unsigned>);
/// [cast]
)

HIDE(
/// [if_]
ASSERT(std::is_same<
    metal::if_<metal::false_, int, metal::int_<0>, int*, void>,
    void
>);

ASSERT(std::is_same<
    metal::if_<metal::false_,  int, metal::int_<1>, int*, void>,
    int*
>);

ASSERT(std::is_same<
    metal::if_<metal::true_,  int, metal::int_<1>, int*, void>,
    int
>);
/// [if_]
)

HIDE(
/// [greater]
ASSERT(!metal::greater<metal::int_<-10>, metal::number<long, 10>>);
ASSERT(!metal::greater<metal::int_<10>, metal::number<long, 10>>);
ASSERT(metal::greater<metal::int_<10>, metal::number<long, -10>>);
/// [greater]
)

HIDE(
/// [less]
ASSERT(metal::less<metal::int_<-10>, metal::number<long, 10>>);
ASSERT(!metal::less<metal::int_<10>, metal::number<long, 10>>);
ASSERT(!metal::less<metal::int_<10>, metal::number<long, -10>>);
/// [less]
)

HIDE(
/// [not_]
ASSERT(metal::not_<metal::number<short, 0>>);
ASSERT(!metal::not_<metal::int_<-10>>);
ASSERT(!metal::not_<metal::char_<'a'>>);
ASSERT(!metal::not_<metal::true_>);
/// [not_]
)

HIDE(
/// [and_]
ASSERT(!metal::and_<metal::int_<-7>, metal::char_<0>, metal::number<long, 5>>);
/// [and_]
)

HIDE(
/// [or_]
ASSERT(metal::or_<metal::int_<-7>, metal::char_<0>, metal::number<long, 5>>);
/// [or_]
)


HIDE(
/// [inc]
ASSERT(std::is_same<metal::inc<metal::int_<-10>>, metal::int_<-9>>);
ASSERT(!metal::is_invocable<metal::lambda<metal::inc>, metal::true_>);
/// [inc]
)

HIDE(
/// [dec]
ASSERT(std::is_same<metal::dec<metal::int_<-10>>, metal::int_<-11>>);
ASSERT(!metal::is_invocable<metal::lambda<metal::dec>, metal::true_>);
/// [dec]
)

HIDE(
/// [neg]
ASSERT(std::is_same<metal::neg<metal::int_<-10>>, metal::int_<10>>);
ASSERT(!metal::is_invocable<metal::lambda<metal::neg>, metal::true_>);
/// [neg]
)

HIDE(
/// [add]
using num = metal::add<
    metal::int_<-7>,
    metal::number<short, 5>,
    metal::number<long, 1>
>;

ASSERT(std::is_same<num, metal::number<long, -1>>);
/// [add]
)

HIDE(
/// [sub]
using num = metal::sub<
    metal::int_<-7>,
    metal::number<short, 5>,
    metal::number<long, 1>
>;

ASSERT(std::is_same<num, metal::number<long, -13>>);
/// [sub]
)

HIDE(
/// [mul]
using num = metal::mul<
    metal::int_<-7>,
    metal::number<short, 5>,
    metal::number<long, 1>
>;

ASSERT(std::is_same<num, metal::number<long, -35>>);
/// [mul]
)

HIDE(
/// [div]
using num = metal::div<
    metal::int_<-7>,
    metal::number<short, 5>,
    metal::number<long, 1>
>;

ASSERT(std::is_same<num, metal::number<long, -1>>);
ASSERT(!metal::is_invocable<metal::lambda<metal::div>, num, metal::int_<0>>);
/// [div]
)

HIDE(
/// [mod]
using num = metal::mod<
    metal::int_<-7>,
    metal::number<short, 5>,
    metal::number<long, 1>
>;

ASSERT(std::is_same<num, metal::number<long, 0>>);
ASSERT(!metal::is_invocable<metal::lambda<metal::mod>, num, metal::int_<0>>);
/// [mod]
)

HIDE(
/// [pow]
using num = metal::pow<
    metal::int_<-7>,
    metal::number<short, 5>,
    metal::number<long, 1>
>;

ASSERT(std::is_same<num, metal::number<long, -16807>>);
ASSERT(!metal::is_invocable<metal::lambda<metal::pow>, metal::int_<0>, num>);
/// [pow]
)

HIDE(
/// [max]
using num = metal::max<
    metal::int_<-7>,
    metal::number<short, 5>,
    metal::number<long, 1>
>;

ASSERT(std::is_same<num, metal::number<long, 5>>);
/// [max]
)

HIDE(
/// [min]
using num = metal::min<
    metal::int_<-7>,
    metal::number<short, 5>,
    metal::number<long, 1>
>;

ASSERT(std::is_same<num, metal::number<long, -7>>);
/// [min]
)

HIDE(
/// [enumerate]
ASSERT(std::is_same<
    metal::enumerate<metal::char_<'a'>, metal::int_<3>>,
    metal::list<metal::char_<'a'>, metal::char_<'b'>, metal::char_<'c'>>
>);

ASSERT(std::is_same<
    metal::enumerate<metal::int_<2>, metal::size_t<3>, metal::int_<-5>>,
    metal::list<metal::int_<2>, metal::int_<-3>, metal::int_<-8>>
>);

ASSERT(std::is_same<
    metal::enumerate<metal::size_t<2>, metal::int_<-3>, metal::int_<-5>>,
    metal::list<metal::size_t<2>, metal::size_t<7>, metal::size_t<12>>
>);
/// [enumerate]
)
