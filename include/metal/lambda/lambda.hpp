// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_LAMBDA_HPP
#define METAL_LAMBDA_LAMBDA_HPP

namespace metal
{
    namespace detail
    {
        template<template<typename...> class expr>
        struct lambda;
    }

    /// \ingroup lambda
    /// ...
    template<template<typename...> class expr>
    using lambda = detail::lambda<expr>;

    namespace detail
    {
        template<template<typename...> class expr>
        struct lambda
        {
            using type = lambda;
        };
    }
}

#endif

