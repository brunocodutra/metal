// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_TRANSFORM_HPP
#define METAL_LIST_TRANSFORM_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... lists>
        struct transform;
    }

    /// \ingroup list
    /// ...
    template<typename lbd, typename... lists>
    using transform = detail::transform<lbd, lists...>;

    /// \ingroup list
    /// Eager adaptor for metal::transform.
    template<typename lbd, typename... lists>
    using transform_t = typename metal::transform<lbd, lists...>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/apply.hpp>
#include <metal/list/transpose.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/quote.hpp>

#include <metal/detail/void.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename list, typename = void>
        struct transform_impl
        {};

        template<
            typename lbd,
            template<typename...> class expr,
            typename... vals
        >
        struct transform_impl<lbd, expr<vals...>,
            void_t<expr<invoke_t<lbd, vals>...>>
        >
        {
            using type = expr<invoke_t<lbd, vals>...>;
        };

        template<typename lbd, typename... lists>
        struct transform :
            invoke<
                transform<_1, transpose<_2>>,
                apply<quote_t<lbd>, _1>, list<lists...>
            >
        {};

        template<typename lbd, typename list>
        struct transform<lbd, list> :
            transform_impl<lbd, list>
        {};
    }
}

#endif
