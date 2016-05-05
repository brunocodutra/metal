// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_EXPRESSIONS_HPP
#define METAL_TEST_EXPRESSIONS_HPP

#include "test/preprocessor.hpp"

#include <type_traits>

namespace test
{
    enum na {};

    template<EVAL(ENUM, LIMIT, typename = na BAR)>
    class expr
    {
    public:
        using type = expr*;
    };

    template<typename... _>
    using expr0 = std::enable_if_t<sizeof...(_) == 0, expr<_...>>;

    template<EVAL(ENUM,  1, typename _)> using expr1  = expr<EVAL(ENUM,  1, _)>;
    template<EVAL(ENUM,  2, typename _)> using expr2  = expr<EVAL(ENUM,  2, _)>;
    template<EVAL(ENUM,  3, typename _)> using expr3  = expr<EVAL(ENUM,  3, _)>;
    template<EVAL(ENUM,  4, typename _)> using expr4  = expr<EVAL(ENUM,  4, _)>;
    template<EVAL(ENUM,  5, typename _)> using expr5  = expr<EVAL(ENUM,  5, _)>;
    template<EVAL(ENUM,  6, typename _)> using expr6  = expr<EVAL(ENUM,  6, _)>;
    template<EVAL(ENUM,  7, typename _)> using expr7  = expr<EVAL(ENUM,  7, _)>;
    template<EVAL(ENUM,  8, typename _)> using expr8  = expr<EVAL(ENUM,  8, _)>;
    template<EVAL(ENUM,  9, typename _)> using expr9  = expr<EVAL(ENUM,  9, _)>;
    template<EVAL(ENUM, 10, typename _)> using expr10 = expr<EVAL(ENUM, 10, _)>;
}

#define NA(...) test::na
#define PARAMS(N) ARGS(N) COMMA(AND(N, CMPL(N))) ENUM(CMPL(N), ADAPT(NA))
#define EXPR(...) CAT(test::expr, __VA_ARGS__)

#endif
