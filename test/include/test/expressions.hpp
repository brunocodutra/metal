// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_EXPRESSIONS_HPP
#define METAL_TEST_EXPRESSIONS_HPP

namespace test
{
    template<typename...>
    using fundamental = char(&(void))[];

    template<typename...>
    struct incomplete;

    template<typename...>
    struct empty {};

    template<typename...>
    struct evaluable {struct type;};

    template<typename...>
    struct call {};
}

#endif
