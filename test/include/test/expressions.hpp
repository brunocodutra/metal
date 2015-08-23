// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_EXPRESSIONS_HPP
#define METAL_TEST_EXPRESSIONS_HPP

#include "test/preprocessor.hpp"

template<typename...>
union expr
{
    using type = expr*;
};

template<typename...>
struct expr0;

template<>
struct expr0<>
{
    using type = expr0*;
};

template<typename>
class expr1
{
public:
    using type = expr1*;
};

template<typename, typename>
union expr2
{
    using type = expr2*;
};

template<_enum(3, typename _)> using expr3 = expr<_enum(3, _)>;
template<_enum(4, typename _)> using expr4 = expr<_enum(4, _)>;
template<_enum(5, typename _)> using expr5 = expr<_enum(5, _)>;
template<_enum(6, typename _)> using expr6 = expr<_enum(6, _)>;
template<_enum(7, typename _)> using expr7 = expr<_enum(7, _)>;
template<_enum(8, typename _)> using expr8 = expr<_enum(8, _)>;
template<_enum(9, typename _)> using expr9 = expr<_enum(9, _)>;

#define _expr(N) _cat(expr, N)
#define _exprs(N) _enum(N, expr)

#endif
