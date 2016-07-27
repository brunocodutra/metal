// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_NUMBERS_HPP
#define METAL_TEST_NUMBERS_HPP

namespace test
{
    template<typename head, typename... tail>
    using value_type = std::common_type_t<
        typename head::value_type, typename tail::value_type...
    >;

    template<typename t, t v>
    using num = std::integral_constant<t, v>;

    using num0 = num<char,                  0>;
    using num1 = num<signed short,          1>;
    using num2 = num<signed int,            2>;
    using num3 = num<signed long,           3>;
    using num4 = num<signed long long,      4>;
    using num5 = num<unsigned short,        5>;
    using num6 = num<unsigned int,          6>;
    using num7 = num<unsigned long,         7>;
    using num8 = num<unsigned long long,    8>;
}

#define NUMBER(N, ...) \
    test::num<__VA_ARGS__, static_cast<__VA_ARGS__>(N)> \
/**/

#define FACT_0 1
#define FACT_1 1
#define FACT_2 FACT_1*2
#define FACT_3 FACT_2*3
#define FACT_4 FACT_3*4
#define FACT_5 FACT_4*5
#define FACT_6 FACT_5*6
#define FACT_7 FACT_6*7
#define FACT_8 FACT_7*8
#define FACT(N, ...) NUMBER(CAT(FACT_, N), __VA_ARGS__)

#define NUM(N) CAT(test::num, N)
#define NUMS(N) ENUM(N, NUM)

#define BOOL(B) test::num<bool, (B)>
#define TRUE BOOL(true)
#define FALSE BOOL(false)

#define SIZE_T(N) test::num<std::size_t, (N)>
#define PTRDIFF_T(N) test::num<std::ptrdiff_t, (N)>

#endif
