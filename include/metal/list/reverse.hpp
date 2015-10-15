// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REVERSE_HPP
#define METAL_LIST_REVERSE_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list>
    struct reverse
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref reverse.
    template<typename list>
    using reverse_t = typename reverse<list>::type;
}

#include <metal/list/slice.hpp>
#include <metal/list/size.hpp>
#include <metal/lambda/defer.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>

#include <cstddef>

namespace metal
{
    template<template<typename...> class list, typename... vals>
    struct reverse<list<vals...>> :
        slice_t<
            defer<lambda<list>, vals...>,
            size_t<list<vals...>>,
            size_t<list<vals...>>,
            integer<-1>
        >
    {};
}

#endif
