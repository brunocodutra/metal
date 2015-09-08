// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_EXPRESSIONS_HPP
#define METAL_TEST_EXPRESSIONS_HPP

#include "test/preprocessor.hpp"

namespace test
{
    template<typename...>
    class expr
    {
    public:
        using type = expr*;
    };

    namespace detail
    {
        template<typename...>
        struct expr0_impl;

        template<>
        struct expr0_impl<>
        {
            using type = expr<>;
        };
    }

    template<typename... _>
    using expr0 = typename detail::expr0_impl<_...>::type;

    template<ENUM( 1, typename BAR)> union  expr1  {using type = expr1&;};
    template<ENUM( 2, typename BAR)> union  expr2  {using type = expr2&;};
    template<ENUM( 3, typename BAR)> union  expr3  {using type = expr3&;};
    template<ENUM( 4, typename BAR)> union  expr4  {using type = expr4&;};
    template<ENUM( 5, typename BAR)> union  expr5  {using type = expr5&;};
    template<ENUM( 6, typename BAR)> struct expr6  {using type = expr6&;};
    template<ENUM( 7, typename BAR)> struct expr7  {using type = expr7&;};
    template<ENUM( 8, typename BAR)> struct expr8  {using type = expr8&;};
    template<ENUM( 9, typename BAR)> struct expr9  {using type = expr9&;};
    template<ENUM(10, typename BAR)> struct expr10 {using type = expr10&;};

#define EXPR(...) CAT(test::expr, __VA_ARGS__)
}
#endif
