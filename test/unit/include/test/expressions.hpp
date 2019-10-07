#ifndef METAL_TEST_EXPRESSIONS_HPP
#define METAL_TEST_EXPRESSIONS_HPP

#include "test/numbers.hpp"
#include "test/preprocessor.hpp"

namespace test {
    template<class...>
    union expr_;

    template<class... _>
    using expr0 = typename std::enable_if<!sizeof...(_), NUMBER(0)>::type;

    template<SCAN(ENUM(1, class NIL))> using expr1  = NUMBER(1);
    template<SCAN(ENUM(2, class NIL))> using expr2  = NUMBER(2);
    template<SCAN(ENUM(3, class NIL))> using expr3  = NUMBER(3);
    template<SCAN(ENUM(4, class NIL))> using expr4  = NUMBER(4);
    template<SCAN(ENUM(5, class NIL))> using expr5  = NUMBER(5);
    template<SCAN(ENUM(6, class NIL))> using expr6  = NUMBER(6);
    template<SCAN(ENUM(7, class NIL))> using expr7  = NUMBER(7);
    template<SCAN(ENUM(8, class NIL))> using expr8  = NUMBER(8);
    template<SCAN(ENUM(9, class NIL))> using expr9  = NUMBER(9);
}

#define EXPR(...) CAT(test::expr, __VA_ARGS__)

#endif
