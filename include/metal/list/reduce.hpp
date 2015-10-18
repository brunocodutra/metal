// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REDUCE_HPP
#define METAL_LIST_REDUCE_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename lbd>
    struct reduce
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref reduce.
    template<typename list, typename lbd>
    using reduce_t = typename reduce<list, lbd>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/number/number.hpp>

#include <cstddef>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename>
        struct reduce_impl;

        template<typename list, typename lbd, typename t, t l, t r>
        struct reduce_impl<list, lbd, number<t, l>, number<t, r>> :
            invoke<
                lift_t<lbd>,
                reduce_impl<list, lbd, number<t, l>, number<t, (l + r)/2>>,
                reduce_impl<list, lbd, number<t, (l + r)/2>, number<t, r>>
            >
        {};

        template<typename list, typename lbd, typename t, t l>
        struct reduce_impl<list, lbd, number<t, l>, number<t, l + 2>> :
            invoke<lbd, at_t<list, number<t, l>>, at_t<list, number<t, l + 1>>>
        {};

        template<typename list, typename lbd, typename t, t l>
        struct reduce_impl<list, lbd, number<t, l>, number<t, l + 1>> :
            invoke<lbd, at_t<list, number<t, l>>>
        {};

        template<typename list, typename lbd, typename t, t l>
        struct reduce_impl<list, lbd, number<t, l>, number<t, l>> :
            invoke<lbd>
        {};
    }

    template<template<typename...> class list, typename... vals, typename lbd>
    struct reduce<list<vals...>, lbd> :
        detail::reduce_impl<
            list<vals...>, lbd, number<std::size_t, 0>, size_t<list<vals...>>
        >
    {};
}

#endif
