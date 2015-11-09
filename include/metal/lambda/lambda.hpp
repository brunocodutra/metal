// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_LAMBDA_HPP
#define METAL_LAMBDA_LAMBDA_HPP

namespace metal
{
    /// \ingroup lambda
    /// ...
    template<template<typename...> class expr>
    struct lambda;
}

#include <metal/core/instantiate.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    template<template<typename...> class expr>
    struct lambda
    {
        template<typename... args>
        using type = typename optional<instantiate_t<expr, args...>>::type;
    };
}

#endif

