// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_EXPRESSIONS_HPP
#define METAL_TEST_EXPRESSIONS_HPP

namespace test
{
    template<typename...>
    using alias = char(&(void))[];


    template<typename... _>
    struct empty
    {};

    template<typename...>
    struct call
    {
        //typedef call

        //template<typename...>
        //typedef call
    };

    template<typename...>
    union union_
    {
        struct type;
    };

    template<typename...>
    struct evaluable
    {
        struct type;
    };

    template<typename... args>
    struct wrap
    {
        using type = wrap;
    };

    template<typename = void>
    struct e0;

    template<>
    struct e0<> :
            evaluable<>
    {};

    template<typename x>
    struct e1 : evaluable<x> {};

    template<typename x, typename y>
    using e2 = evaluable<x, y>;

    template<typename... args>
    using en = evaluable<args...>;
}

#endif
