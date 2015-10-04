// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_TRANSFORM_HPP
#define METAL_LIST_TRANSFORM_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename lbd>
    struct transform
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref transform.
    template<typename list, typename lbd>
    using transform_t = typename transform<list, lbd>::type;
}

#include <metal/lambda/bind.hpp>
#include <metal/lambda/identity.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/lambda.hpp>

namespace metal
{
    template<template<typename...> class list, typename... args, typename lbd>
    struct transform<list<args...>, lbd> :
        bind<lift_t<lambda<identity>, lambda<list>>, invoke<lbd, args>...>
    {};
}

#endif
