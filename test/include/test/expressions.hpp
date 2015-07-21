// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_EXPRESSIONS_HPP
#define METAL_TEST_EXPRESSIONS_HPP

namespace test
{
    template<typename... args>
    using alias = char(&(args...))[sizeof...(args)];

    template<typename...>
    struct empty
    {};

    template<typename...>
    struct call
    {
        //typedef call

        //template<typename...>
        //typedef call
    };

    template<typename = void>
    struct e0;

    template<>
    struct e0<>
    {
        enum type {};
    };

    template<typename... args>
    union en
    {
        using type = en*;
    };

    template<typename x>
    using e1 = en<x>;

    template<typename x, typename y>
    using e2 = en<x, y>;


}

#endif
