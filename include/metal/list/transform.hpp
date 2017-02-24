// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_TRANSFORM_HPP
#define METAL_LIST_TRANSFORM_HPP

#include <metal/config.hpp>

#include <metal/list/size.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/if.hpp>
#include <metal/value/same.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename lbd, typename head, typename... tail>
        struct _transform;

        template<typename lbd, typename head, typename... tail>
        using transform = typename _transform<lbd, head, tail...>::type;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Transforms one or more \lists into a new \list through an arbitrary
    /// n-ary \lambda.
    ///
    /// ### Usage
    /// For any \lambda `lbd` and \lists `l_0, ..., l_n-1`
    /// \code
    ///     using result = metal::transform<lbd, l_0, ..., l_n-1>;
    /// \endcode
    ///
    /// \pre: `metal::size<l_0>{} == metal::size<>{}... == metal::size<l_n-1>{}`
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<
    ///             metal::invoke<lbd, l[0]...>,
    ///             metal::invoke<lbd, l[1]...>,
    ///             ...,
    ///             metal::invoke<lbd, l[m-1]...>,
    ///         >;
    ///     \endcode
    ///     where `l[N]...` stands for `l_0[N], ...[N], l_n-1[N]`.
    ///
    /// ### Example
    /// \snippet list.cpp transform
    ///
    /// ### See Also
    /// \see list, accumulate
    template<typename lbd, typename head, typename... tail>
    using transform = typename if_<
        same<size<head>, size<tail>...>,
        detail::_transform<if_<is_lambda<lbd>, lbd>, head, tail...>
    >::type;
}

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/list/indices.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/number.hpp>
#include <metal/value/value.hpp>

#include <metal/detail/declptr.hpp>

#include <type_traits>

namespace metal
{
    /// \cond
    namespace detail
    {
#if defined(METAL_COMPAT_MODE)
        template<template<typename...> class expr, typename... vals,
            typename std::enable_if<
                is_value<list<expr<vals>...>>::value
            >::type* = nullptr
        >
        value<list<expr<vals>...>>
            transform_impl(lambda<expr>*, list<vals...>*);

        value<> transform_impl(...);

        template<typename lbd, typename seq>
        struct _transform_impl :
            decltype(transform_impl(declptr<lbd>(), declptr<seq>()))
        {};
#else
        template<typename, typename, typename = true_>
        struct _transform_impl
        {};

        template<template<typename...> class expr, typename... vals>
        struct _transform_impl<lambda<expr>, list<vals...>,
            is_value<list<expr<vals>...>>
        > :
            value<list<expr<vals>...>>
        {};
#endif

        template<typename lbd, typename... seqs>
        struct transformer
        {
            template<typename num>
            using type = invoke<lbd, at<seqs, num>...>;
        };

        template<typename lbd, typename head, typename... tail>
        struct _transform :
            _transform<
                lambda<transformer<lbd, head, tail...>::template type>,
                indices<head>
            >
        {};

        template<
            typename lbd,
            typename x, typename y, typename z,
            typename h, typename... t
        >
        struct _transform<lbd, list<x>, list<y>, list<z>, list<h>, list<t>...> :
            _invoke<bind<lambda<list>, lbd>, x, y, z, h, t...>
        {};

        template<typename lbd, typename... x, typename... y, typename... z>
        struct _transform<lbd, list<x...>, list<y...>, list<z...>> :
            _transform_impl<partial<lambda<apply>, lbd>, list<list<x, y, z>...>>
        {};

        template<typename lbd, typename... x, typename... y>
        struct _transform<lbd, list<x...>, list<y...>> :
            _transform_impl<partial<lambda<apply>, lbd>, list<list<x, y>...>>
        {};

        template<typename lbd, typename... x>
        struct _transform<lbd, list<x...>> :
            _transform_impl<lbd, list<x...>>
        {};

        template<typename lbd>
        struct _transform<lbd, list<>>
        {
            using type = list<>;
        };
    }
    /// \endcond
}

#endif
