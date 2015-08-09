// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_EXPRESSIONS_HPP
#define METAL_TEST_EXPRESSIONS_HPP

namespace test
{
    template<typename...>
    struct empty;

    template<typename... args>
    union expr
    {
        using type = expr*;
    };

    template<typename...>
    struct expr0;

    template<>
    struct expr0<>
    {
        enum type {};
    };

    template<typename x>
    struct expr1
    {
        union type {};
    };

    template<typename x, typename y>
    using expr2 = expr<x, y>;
}

#endif
