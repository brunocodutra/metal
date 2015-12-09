// Copyright Bruno Dutra 2015
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

#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

#include <metal/detail/inherit.hpp>

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct voider
        {
            using type = void;
        };

        template<typename... _>
        using voider_t = typename voider<_...>::type;

        template<typename... bases>
        boolean<true> disambiguate(bases*...);

        template<typename derived, typename... bases>
        auto is_unambiguously_derived_from(derived* _) ->
            decltype(disambiguate<bases...>((voider_t<bases>(), _)...));

        template<typename...>
        boolean<false> is_unambiguously_derived_from(...);

        template<typename list>
        struct distinct
        {};

        template<template<typename...> class list, typename... vals>
        struct distinct<list<vals...>> :
            decltype(
                is_unambiguously_derived_from<
                    inherit<metal::list<vals>...>,
                    metal::list<vals>...
                >(0)
            )
        {};
    }
}

#endif
