// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_COUNT_HPP
#define METAL_LIST_COUNT_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename val>
    struct count
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref count.
    template<typename list, typename val>
    using count_t = typename count<list, val>::type;
}

#include <metal/optional/eval.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/add.hpp>

#include <cstddef>
#include <type_traits>

namespace metal
{
    template<template<typename...> class list, typename... vals, typename val>
    struct count<list<vals...>, val> :
        add<number<std::ptrdiff_t, 0>, eval<std::is_same<vals, val>>...>
    {};
}

#endif
