// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_FUNCTIONS_HPP
#define METAL_TEST_FUNCTIONS_HPP

#include "test/expressions.hpp"

namespace test
{
    struct f0
    {
    private:
        template<bool, typename...>
        struct call_if
        {};

        template<typename... args>
        struct call_if<true, args...>
        {
            enum class type;
        };

    public:
        template<typename... args>
        using call = call_if<!sizeof...(args), args...>;
    };

    struct fn
    {
        template<typename... args>
        using call = en<args...>;
    };

    struct f1
    {
        template<typename x>
        using call = e1<x>;
    };

    struct f2
    {
        template<typename x, typename y>
        using call = e2<x, y>;
    };


}

#endif
