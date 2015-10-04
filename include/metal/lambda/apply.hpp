// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename lbd, typename list>
    struct apply
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref apply.
    template<typename lbd, typename list>
    using apply_t = typename apply<lbd, list>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    template<typename lbd, template<typename...> class list, typename... args>
    struct apply<lbd, list<args...>> :
        invoke<lbd, args...>
    {};

    template<
        template<template<typename...> class> class lambda,
        template<typename...> class list, typename... args
    >
    struct apply<lambda<list>, list<args...>> :
        optional<list<args...>>
    {};
}

#endif
