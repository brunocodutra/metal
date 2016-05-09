// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_PARTIAL_HPP
#define METAL_LAMBDA_PARTIAL_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... vals>
        struct _partial;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd, typename... vals>
    using partial = typename detail::_partial<lbd, vals...>::type;
}

#include <metal/lambda/invoke.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... vals>
        struct _partial
        {};

        template<
            template<template<typename...> class> class lbd,
            template<typename...> class expr,
            typename... leading
        >
        struct _partial<lbd<expr>, leading...>
        {
            template<typename... trailing>
            using impl = invoke<lbd<expr>, leading..., trailing...>;

            using type = lbd<impl>;
        };

        template<
            template<template<typename...> class> class lbd,
            template<typename...> class expr
        >
        struct _partial<lbd<expr>>
        {
            using type = lbd<expr>;
        };
    }
}

#endif
