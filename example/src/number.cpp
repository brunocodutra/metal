// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [num1]
using num = metal::false_;
/// [num1]

IS_SAME(metal::is_number<num>, metal::true_);
)

HIDE(
/// [num2]
using num = metal::number<-1>;
/// [num2]

IS_SAME(metal::is_number<num>, metal::true_);
)

HIDE(
/// [num3]
using num = metal::number<'a'>;
/// [num3]

IS_SAME(metal::is_number<num>, metal::true_);
)

HIDE(
/// [not_a_num1]
struct not_a_num :
    metal::true_
{};
/// [not_a_num1]

IS_SAME(metal::is_number<not_a_num>, metal::false_);
)

HIDE(
/// [is_number]
struct one { static const auto value = 1L; };
enum two { value = 2U };

IS_SAME(metal::is_number<void>, metal::false_);
IS_SAME(metal::is_number<one>, metal::false_);
IS_SAME(metal::is_number<two>, metal::false_);
IS_SAME(metal::is_number<std::integral_constant<short, 42>>, metal::false_);
IS_SAME(metal::is_number<metal::number<-10>>, metal::true_);
IS_SAME(metal::is_number<metal::false_>, metal::true_);
/// [is_number]
)

HIDE(
/// [as_number]
struct one { static const auto value = 1L; };
enum two { value = 2U };

IS_SAME(metal::as_number<one>, metal::number<1>);
IS_SAME(metal::as_number<two>, metal::number<2>);
IS_SAME(metal::as_number<std::integral_constant<short, 42>>, metal::number<42>);
/// [as_number]
)

HIDE(
/// [numbers]
IS_SAME(metal::numbers<>, metal::list<>);

IS_SAME(
    metal::numbers<'a', 'b'>,
    metal::list<metal::number<'a'>, metal::number<'b'>>
);

IS_SAME(
    metal::numbers<-7, 5, 1>,
    metal::list<metal::number<-7>, metal::number<5>, metal::number<1>>
);
/// [numbers]
)

HIDE(
/// [if_]
IS_SAME(metal::if_<metal::false_, int, metal::number<0>, int*, void>, void);
IS_SAME(metal::if_<metal::false_,  int, metal::number<1>, int*, void>, int*);
IS_SAME(metal::if_<metal::true_,  int, metal::number<1>, int*, void>, int);
/// [if_]
)

HIDE(
/// [greater]
IS_SAME(metal::greater<metal::number<-10>, metal::number<10>>, metal::false_);
IS_SAME(metal::greater<metal::number<10>, metal::number<10>>, metal::false_);
IS_SAME(metal::greater<metal::number<10>, metal::number<-10>>, metal::true_);
/// [greater]
)

HIDE(
/// [less]
IS_SAME(metal::less<metal::number<-10>, metal::number<10>>, metal::true_);
IS_SAME(metal::less<metal::number<10>, metal::number<10>>, metal::false_);
IS_SAME(metal::less<metal::number<10>, metal::number<-10>>, metal::false_);
/// [less]
)

HIDE(
/// [not_]
IS_SAME(metal::not_<metal::number<0>>, metal::true_);
IS_SAME(metal::not_<metal::number<-10>>, metal::false_);
IS_SAME(metal::not_<metal::number<'a'>>, metal::false_);
IS_SAME(metal::not_<metal::true_>, metal::false_);
/// [not_]
)

HIDE(
/// [and_]
IS_SAME(metal::and_<>, metal::true_);
IS_SAME(metal::and_<metal::number<0>>, metal::false_);
IS_SAME(metal::and_<metal::number<42>>, metal::true_);
IS_SAME(metal::and_<metal::number<42>, metal::number<0>>, metal::false_);
/// [and_]
)

HIDE(
/// [or_]
IS_SAME(metal::or_<>, metal::false_);
IS_SAME(metal::or_<metal::number<0>>, metal::false_);
IS_SAME(metal::or_<metal::number<42>>, metal::true_);
IS_SAME(metal::or_<metal::number<42>, metal::number<0>>, metal::true_);
/// [or_]
)

HIDE(
/// [abs]
IS_SAME(metal::abs<metal::number<-10>>, metal::number<10>);
IS_SAME(metal::abs<metal::number<0>>, metal::number<0>);
/// [abs]
)

HIDE(
/// [inc]
IS_SAME(metal::inc<metal::number<-10>>, metal::number<-9>);
IS_SAME(metal::inc<metal::number<0>>, metal::number<1>);
/// [inc]
)

HIDE(
/// [dec]
IS_SAME(metal::dec<metal::number<-10>>, metal::number<-11>);
IS_SAME(metal::dec<metal::number<0>>, metal::number<-1>);
/// [dec]
)

HIDE(
/// [neg]
IS_SAME(metal::neg<metal::number<-10>>, metal::number<10>);
IS_SAME(metal::neg<metal::number<0>>, metal::number<0>);
/// [neg]
)

HIDE(
/// [add]
using num = metal::add<metal::number<-17>, metal::number<5>, metal::number<3>>;

IS_SAME(num, metal::number<-9>);
/// [add]
)

HIDE(
/// [sub]
using num = metal::sub<metal::number<-17>, metal::number<5>, metal::number<3>>;

IS_SAME(num, metal::number<-25>);
/// [sub]
)

HIDE(
/// [mul]
using num = metal::mul<metal::number<-17>, metal::number<5>, metal::number<3>>;

IS_SAME(num, metal::number<-255>);
/// [mul]
)

HIDE(
/// [div]
using num = metal::div<metal::number<-17>, metal::number<5>, metal::number<3>>;

IS_SAME(num, metal::number<-1>);
IS_SAME(
    metal::is_invocable<metal::lambda<metal::div>, num, metal::number<0>>,
    metal::false_
);
/// [div]
)

HIDE(
/// [mod]
using num = metal::mod<metal::number<-17>, metal::number<5>, metal::number<3>>;

IS_SAME(num, metal::number<-2>);
IS_SAME(
    metal::is_invocable<metal::lambda<metal::mod>, num, metal::number<0>>,
    metal::false_
);
/// [mod]
)

HIDE(
/// [pow]
using num = metal::pow<metal::number<-17>, metal::number<5>, metal::number<3>>;

IS_SAME(num, metal::number<-2862423051509815793>);
IS_SAME(
    metal::is_invocable<metal::lambda<metal::pow>, metal::number<0>, num>,
    metal::false_
);
/// [pow]
)

HIDE(
/// [max]
using num = metal::max<metal::number<-17>, metal::number<5>, metal::number<3>>;

IS_SAME(num, metal::number<5>);
/// [max]
)

HIDE(
/// [min]
using num = metal::min<metal::number<-17>, metal::number<5>, metal::number<3>>;

IS_SAME(num, metal::number<-17>);
/// [min]
)
