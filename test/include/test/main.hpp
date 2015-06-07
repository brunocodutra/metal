// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_TEST_MAIN_HPP
#define BOOST_MPL2_TEST_MAIN_HPP

#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/core/logical.hpp>

#include <type_traits>

namespace test
{
    template<typename...>
    using fundamental = void;

    template<typename...>
    using function = void();

    template<typename...>
    struct incomplete;

    template<typename...>
    struct empty {};

    template<typename...>
    struct evaluable {struct type;};

    template<typename...>
    struct tagged {struct tag;};

    template<typename...>
    struct call {};

    template<typename...>
    struct tag {};

    template<template<typename...> class base, typename... _>
    struct eponym : base<_...> {};
}

int main()
{
    return 0;
}

#endif
