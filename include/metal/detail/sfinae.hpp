// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_DETAIL_SFINAE_HPP
#define METAL_DETAIL_SFINAE_HPP

#include <metal/config.hpp>

#include <metal/value/eval.hpp>
#include <metal/value/value.hpp>

#include <metal/detail/declptr.hpp>

#include <type_traits>

namespace metal {
    /// \cond
    namespace detail {
        template<
            template<template<typename...> class...> class,
            template<typename...> class...
        >
        struct forwarder;

        template<
            template<template<typename...> class...> class tmpl,
            template<typename...> class... exprs,
            eval<std::enable_if<is_value<tmpl<exprs...>>::value>>* = nullptr
        >
        value<tmpl<exprs...>> sfinae(forwarder<tmpl, exprs...>*);

        template<template<typename...> class expr, typename... vals>
        struct caller;

        template<
            template<typename...> class expr,
            typename... vals,
            eval<std::enable_if<is_value<expr<vals...>>::value>>* = nullptr
        >
        value<expr<vals...>> sfinae(caller<expr, vals...>*);

        value<> sfinae(...);

                template<
            template<template<typename...> class...> class tmpl,
            template<typename...> class... exprs
        >
        struct forwarder :
            decltype(sfinae(declptr<forwarder<tmpl, exprs...>>()))
        {};

        template<template<typename...> class expr, typename... vals>
        struct caller :
            decltype(sfinae(declptr<caller<expr, vals...>>()))
        {};

#if defined(METAL_WORKAROUND)
        template<
            template<template<typename...> class...> class tmpl,
            template<typename...> class... exprs
        >
        using forward = typename forwarder<tmpl, exprs...>::type;

        template<template<typename...> class expr, typename... vals>
        using call = typename caller<expr, vals...>::type;
#else
        template<
            template<template<typename...> class...> class tmpl,
            template<typename...> class... exprs
        >
        using forward = tmpl<exprs...>;

        template<template<typename...> class expr, typename... vals>
        using call = expr<vals...>;
#endif
    }
    /// \endcond
}

#endif
