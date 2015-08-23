// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_BIND_HPP
#define METAL_LAMBDA_BIND_HPP

#include <metal/lambda/apply.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct bind;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref bind.
    template<typename... args>
    using bind_t = typename metal::bind<args...>::type;

    namespace detail
    {
        template<typename val>
        struct backquote
        {
            using type = val;
        };

        template<typename val>
        using backquote_t = typename backquote<val>::type;

        template<template<typename...> class expr, typename... params>
        struct backquote<expr<params...>>
        {
            template<typename... args>
            struct _
            {
                using type = expr<args...>;
            };

            using type = _<backquote_t<params>...>;
        };
    }

    template<typename lbd, typename... args>
    struct bind<lbd, args...> :
        apply<detail::backquote_t<lbd>, args...>
    {};
}

#endif
