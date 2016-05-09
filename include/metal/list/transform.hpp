// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_TRANSFORM_HPP
#define METAL_LIST_TRANSFORM_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename head, typename... tail>
        struct _transform;
    }

    /// \ingroup list
    /// ...
    template<typename lbd, typename head, typename... tail>
    using transform = typename detail::_transform<lbd, head, tail...>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/transpose.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/if.hpp>

#include <metal/detail/void.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename seq, typename = void>
        struct _transform_impl
        {};

        template<
            template<template<typename...> class> class lbd,
            template<typename...> class expr,
            template<typename...> class seq,
            typename... vals
        >
        struct _transform_impl<lbd<expr>, seq<vals...>,
            void_<seq<expr<vals>...>>
        >
        {
            using type = seq<expr<vals>...>;
        };

        template<typename lbd, typename head, typename... tail>
        using transform_impl = transform<
            partial<lambda<apply>, lbd>,
            transpose<list<head, tail...>>
        >;

        template<typename lbd, typename head, typename... tail>
        struct _transform :
            _invoke<lambda<transform_impl>, lbd, head, tail...>
        {};

        template<
            typename lbd,
            template<typename...> class seq,
            typename head, typename... tail
        >
        struct _transform<lbd, seq<head, tail...>> :
            _transform_impl<lbd, seq<head, tail...>>
        {};

        template<
            typename lbd,
            template<typename...> class seq,
            typename... vals
        >
        struct _transform<lbd, seq<vals...>> :
            _if_<is_lambda<lbd>, seq<vals...>>
        {};
    }
}

#endif
