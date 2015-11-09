// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_COUNT_IF_HPP
#define METAL_LIST_COUNT_IF_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    struct count_if
    {};

    /// \ingroup list
    /// Eager adaptor for \ref count_if.
    template<typename list, typename lbd>
    using count_if_t = typename metal::count_if<list, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/reduce.hpp>
#include <metal/list/flatten.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/add.hpp>
#include <metal/optional/conditional.hpp>

#include <cstddef>

namespace metal
{
    template<template<typename...> class list, typename... vals, typename lbd>
    struct count_if<list<vals...>, lbd> :
        invoke<
            lift_t<lambda<add>>,
            number<std::ptrdiff_t, 0>,
            invoke<
                conditional<
                    bind_t<lbd, _1>,
                    number<std::ptrdiff_t, 1>,
                    number<std::ptrdiff_t, 0>
                >,
                vals
            >...
        >
    {};
}

#endif
