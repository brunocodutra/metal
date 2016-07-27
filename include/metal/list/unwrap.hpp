// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_UNWRAP_HPP
#define METAL_LIST_UNWRAP_HPP

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _unwrap;
    }

    /// \ingroup list
    /// ...
    template<typename seq>
    using unwrap = typename detail::_unwrap<seq>::type;
}

#include <metal/lambda/lambda.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _unwrap
        {};

        template<template<typename...> class seq, typename... vals>
        struct _unwrap<seq<vals...>>
        {
            using type = lambda<seq>;
        };
    }
}

#endif
