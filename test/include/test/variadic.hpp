// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_TEST_VARIADIC_HPP
#define BOOST_MPL2_TEST_VARIADIC_HPP

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
    struct call {};

    template<template<typename...> class base, typename... _>
    struct eponym : base<_...> {};
}

#endif
