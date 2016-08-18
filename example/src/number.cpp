// Copyright Bruno Dutra 2015-2016
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
/// [not_a_num1]
struct not_a_num :
    metal::true_
{};
/// [not_a_num1]

IS_SAME(metal::is_number<not_a_num>, metal::false_);
)

HIDE(
/// [is_number]
IS_SAME(metal::is_number<metal::number<-10>>, metal::true_);
IS_SAME(metal::is_number<metal::true_>, metal::true_);
IS_SAME(metal::is_number<metal::false_>, metal::true_);
IS_SAME(metal::is_number<void>, metal::false_);
/// [is_number]
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
using num = metal::and_<metal::number<-7>, metal::number<0>, metal::number<5>>;

IS_SAME(num, metal::false_);
/// [and_]
)

HIDE(
/// [or_]
using num = metal::or_<metal::number<-7>, metal::number<0>, metal::number<5>>;

IS_SAME(num, metal::true_);
/// [or_]
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
using num = metal::add<metal::number<-7>, metal::number<5>, metal::number<1>>;

IS_SAME(num, metal::number<-1>);
/// [add]
)

HIDE(
/// [sub]
using num = metal::sub<metal::number<-7>, metal::number<5>, metal::number<1>>;

IS_SAME(num, metal::number<-13>);
/// [sub]
)

HIDE(
/// [mul]
using num = metal::mul<metal::number<-7>, metal::number<5>, metal::number<1>>;

IS_SAME(num, metal::number<-35>);
/// [mul]
)

HIDE(
/// [div]
using num = metal::div<metal::number<-7>, metal::number<5>, metal::number<1>>;

IS_SAME(num, metal::number<-1>);
IS_SAME(
    metal::is_invocable<metal::lambda<metal::div>, num, metal::number<0>>,
    metal::false_
);
/// [div]
)

HIDE(
/// [mod]
using num = metal::mod<metal::number<-7>, metal::number<5>, metal::number<1>>;

IS_SAME(num, metal::number<0>);
IS_SAME(
    metal::is_invocable<metal::lambda<metal::mod>, num, metal::number<0>>,
    metal::false_
);
/// [mod]
)

HIDE(
/// [pow]
using num = metal::pow<metal::number<-7>, metal::number<5>, metal::number<1>>;

IS_SAME(num, metal::number<-16807>);
IS_SAME(
    metal::is_invocable<metal::lambda<metal::pow>, metal::number<0>, num>,
    metal::false_
);
/// [pow]
)

HIDE(
/// [max]
using num = metal::max<metal::number<-7>, metal::number<5>, metal::number<1>>;

IS_SAME(num, metal::number<5>);
/// [max]
)

HIDE(
/// [min]
using num = metal::min<metal::number<-7>, metal::number<5>, metal::number<1>>;

IS_SAME(num, metal::number<-7>);
/// [min]
)

HIDE(
/// [enumerate]
IS_SAME(
    metal::enumerate<metal::number<'a'>, metal::number<3>>,
    metal::list<metal::number<'a'>, metal::number<'b'>, metal::number<'c'>>
);

IS_SAME(
    metal::enumerate<metal::number<2>, metal::number<3>, metal::number<-5>>,
    metal::list<metal::number<2>, metal::number<-3>, metal::number<-8>>
);

IS_SAME(
    metal::enumerate<metal::number<2>, metal::number<-3>, metal::number<-5>>,
    metal::list<metal::number<2>, metal::number<7>, metal::number<12>>
);
/// [enumerate]
)
