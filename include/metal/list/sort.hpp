// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SORT_HPP
#define METAL_LIST_SORT_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    struct sort
    {};

    /// \ingroup list
    /// Eager adaptor for \ref sort.
    template<typename list, typename lbd>
    using sort_t = typename metal::sort<list, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/copy.hpp>
#include <metal/list/partition.hpp>
#include <metal/pair/first.hpp>
#include <metal/pair/second.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    template<typename head, typename... tail, typename lbd>
    struct sort<list<head, tail...>, lbd> :
        invoke<
            lift_t<join<sort<first<_1>, _2>, _3, sort<second<_1>, _2>>>,
            partition<list<tail...>, bind_t<lbd, _1, head>>,
            just<lbd>,
            list<head>
        >
    {};

    template<typename val, typename lbd>
    struct sort<list<val>, lbd> :
        list<val>
    {};

    template<typename lbd>
    struct sort<list<>, lbd> :
        list<>
    {};

    template<template<typename...> class list, typename... vals, typename lbd>
    struct sort<list<vals...>, lbd> :
        invoke<
            lift_t<lambda<copy>>,
            just<list<vals...>>,
            sort<metal::list<vals...>, lbd>
        >
    {};
}

#endif
