// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_EXPRESSIONS_HPP
#define METAL_TEST_EXPRESSIONS_HPP

#include "test/preprocessor.hpp"

template<typename...>
struct expr
{
    using type = expr*;
};

template<typename...>
class expr0;

template<>
class expr0<>
{
public:
    using type = expr0*;
};

template<_enum( 1, typename _bar)> union  expr1  {using type = expr1&;};
template<_enum( 2, typename _bar)> union  expr2  {using type = expr2&;};
template<_enum( 3, typename _bar)> union  expr3  {using type = expr3&;};
template<_enum( 4, typename _bar)> union  expr4  {using type = expr4&;};
template<_enum( 5, typename _bar)> union  expr5  {using type = expr5&;};
template<_enum( 6, typename _bar)> struct expr6  {using type = expr6&&;};
template<_enum( 7, typename _bar)> struct expr7  {using type = expr7&&;};
template<_enum( 8, typename _bar)> struct expr8  {using type = expr8&&;};
template<_enum( 9, typename _bar)> struct expr9  {using type = expr9&&;};
template<_enum(10, typename _bar)> struct expr10 {using type = expr10&&;};

#define _expr(N) _cat(expr, N)
#define _exprs(N) _enum(N, expr)

#endif
