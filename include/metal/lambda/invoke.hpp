// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

#include <metal/number/not.hpp>

#include <metal/detail/nil.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... args>
        struct _invoke;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd, typename... args>
    using invoke = typename detail::_invoke<lbd, args...>::type;

    /// \ingroup lambda
    /// ...
    template<typename lbd, typename... args>
    using is_invocable = not_<
        typename std::is_base_of<
            detail::nil,
            detail::_invoke<lbd, args...>
        >::type
    >;
}

#include <metal/list/list.hpp>

#include <metal/detail/void.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename seq, typename = void>
        struct _invoke_impl :
            detail::nil
        {};

        template<
            template<template<typename...> class> class lbd,
            template<typename...> class expr,
            typename head, typename... tail
        >
        struct _invoke_impl<lbd<expr>, list<head, tail...>,
            void_<expr<head, tail...>>
        >
        {
            using type = expr<head, tail...>;
        };

        template<
            template<template<typename...> class> class lbd,
            template<typename...> class expr
        >
        struct _invoke_impl<lbd<expr>, list<>,
            void_<expr<>>
        >
        {
            using type = expr<>;
        };

        template<typename lbd, typename... args>
        struct _invoke :
            _invoke_impl<lbd, list<args...>>
        {};
    }
}

#endif
