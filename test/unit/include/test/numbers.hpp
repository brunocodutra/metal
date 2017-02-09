// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_NUMBERS_HPP
#define METAL_TEST_NUMBERS_HPP

#include "test/preprocessor.hpp"

namespace test
{
    using num0  = metal::number<0>;
    using num1  = metal::number<1>;
    using num2  = metal::number<2>;
    using num3  = metal::number<3>;
    using num4  = metal::number<4>;
    using num5  = metal::number<5>;
    using num6  = metal::number<6>;
    using num7  = metal::number<7>;
    using num8  = metal::number<8>;
    using num9  = metal::number<9>;
}

#define FACT_0 1
#define FACT_1 1
#define FACT_2 FACT_1*2
#define FACT_3 FACT_2*3
#define FACT_4 FACT_3*4
#define FACT_5 FACT_4*5
#define FACT_6 FACT_5*6
#define FACT_7 FACT_6*7
#define FACT_8 FACT_7*8
#define FACT_9 FACT_7*9
#define FACT(N) (CAT(FACT_, N))

#define NUMBER(N) CAT(test::num, N)
#define NUMBERS(N) ENUM(N, NUMBER)

#define BOOL(B) metal::number<(B)>
#define TRUE BOOL(true)
#define FALSE BOOL(false)

#endif
