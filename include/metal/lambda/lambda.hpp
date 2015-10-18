// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_LAMBDA_HPP
#define METAL_LAMBDA_LAMBDA_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<template<typename...> class expr>
    struct lambda;
}

#include <metal/lambda/defer.hpp>

namespace metal
{
    template<template<typename...> class expr>
    struct lambda
    {
        template<typename... args>
        using call = defer_t<lambda, args...>;
    };
}

#endif

