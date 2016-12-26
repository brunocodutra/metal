// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_EXPRESSIONS_HPP
#define METAL_TEST_EXPRESSIONS_HPP

#include "test/numbers.hpp"
#include "test/preprocessor.hpp"

namespace test
{
    template<typename... _>
    struct length :
        std::integral_constant<std::size_t, sizeof...(_)>
    {};

    template<typename...>
    union expr_;

    template<typename... _>
    using expr0 =
        typename std::enable_if<length<_...>::value == 0, NUMBER(0)>::type;

    template<typename... _>
    using expr1 =
        typename std::enable_if<length<_...>::value == 1, NUMBER(1)>::type;

    template<SCAN(ENUM(2, typename NIL))> using expr2  = NUMBER(2);
    template<SCAN(ENUM(3, typename NIL))> using expr3  = NUMBER(3);
    template<SCAN(ENUM(4, typename NIL))> using expr4  = NUMBER(4);
    template<SCAN(ENUM(5, typename NIL))> using expr5  = NUMBER(5);
    template<SCAN(ENUM(6, typename NIL))> using expr6  = NUMBER(6);
    template<SCAN(ENUM(7, typename NIL))> using expr7  = NUMBER(7);
    template<SCAN(ENUM(8, typename NIL))> using expr8  = NUMBER(8);
    template<SCAN(ENUM(9, typename NIL))> using expr9  = NUMBER(9);
}

#define EXPR(...) CAT(test::expr, __VA_ARGS__)

#endif
