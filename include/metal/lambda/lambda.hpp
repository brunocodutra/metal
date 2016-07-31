// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_LAMBDA_HPP
#define METAL_LAMBDA_LAMBDA_HPP

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _is_lambda;

        template<template<typename...> class expr>
        struct lambda {};
    }

    /// \ingroup lambda
    /// ...
    template<typename val>
    using is_lambda = typename detail::_is_lambda<val>::type;

    /// \ingroup lambda
    /// ...
    template<template<typename...> class expr>
    using lambda = detail::lambda<expr>;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _is_lambda :
            false_
        {};

        template<template<typename...> class expr>
        struct _is_lambda<lambda<expr>> :
            true_
        {};
    }
}

#endif

