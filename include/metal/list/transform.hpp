// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_TRANSFORM_HPP
#define METAL_LIST_TRANSFORM_HPP

#include "../config.hpp"
#include "../list/size.hpp"
#include "../number/if.hpp"
#include "../value/same.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename lbd>
        struct _transform;
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
    template<typename lbd, typename... seqs>
    using transform = detail::call<
        if_<same<size<seqs>...>, detail::_transform<lbd>>::template type,
        seqs...>;
}

#include "../lambda/lambda.hpp"
#include "../list/at.hpp"
#include "../list/indices.hpp"
#include "../list/list.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename num, typename... seqs>
        struct transformer_impl {
            template<template<typename...> class expr>
            using type = expr<at<seqs, num>...>;
        };

        template<template<typename...> class expr, typename... seqs>
        struct transformer {
            template<typename num>
            using type =
                forward<transformer_impl<num, seqs...>::template type, expr>;
        };

        template<typename head, typename... tail>
        struct _transform_impl {
            template<template<typename...> class expr>
            using type = forward<
                _transform_impl<indices<head>>::template type,
                transformer<expr, head, tail...>::template type>;
        };

        template<typename... xs, typename... ys, typename... zs>
        struct _transform_impl<list<xs...>, list<ys...>, list<zs...>> {
            template<template<typename...> class expr>
            using type = list<expr<xs, ys, zs>...>;
        };

        template<typename... xs, typename... ys>
        struct _transform_impl<list<xs...>, list<ys...>> {
            template<template<typename...> class expr>
            using type = list<expr<xs, ys>...>;
        };

        template<typename... xs>
        struct _transform_impl<list<xs...>> {
            template<template<typename...> class expr>
            using type = list<expr<xs>...>;
        };

        template<typename lbd>
        struct _transform {};

        template<template<typename...> class expr>
        struct _transform<lambda<expr>> {
            template<typename... seqs>
            using type = forward<_transform_impl<seqs...>::template type, expr>;
        };
    }
    /// \endcond
}

#endif
