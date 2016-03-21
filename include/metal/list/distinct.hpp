// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_DISTINCT_HPP
#define METAL_LIST_DISTINCT_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct distinct;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using distinct = detail::distinct<list>;

    /// \ingroup list
    /// Eager adaptor for \ref distinct.
    template<typename list>
    using distinct_t = typename metal::distinct<list>::type;
}

#include <metal/number/number.hpp>

#include <metal/detail/inherit.hpp>
#include <metal/detail/declptr.hpp>

namespace metal
{
    namespace detail
    {
        template<typename>
        struct wrapper
        {};

        template<typename... bases>
        boolean<true> disambiguate(bases*...);

        template<typename derived, typename... bases>
        auto is_unambiguously_derived_from(derived* _) ->
            decltype(disambiguate<bases...>((declptr<bases>(), _)...));

        template<typename...>
        boolean<false> is_unambiguously_derived_from(...);

        template<typename list>
        struct distinct
        {};

        template<
            template<typename...> class expr,
            typename head, typename... tail
        >
        struct distinct<expr<head, tail...>> :
            decltype(
                is_unambiguously_derived_from<
                    inherit<wrapper<head>, wrapper<tail>...>,
                    wrapper<head>, wrapper<tail>...
                >(0)
            )
        {};

        template<template<typename...> class expr, typename... vals>
        struct distinct<expr<vals...>> :
            boolean<true>
        {};
    }
}

#endif
