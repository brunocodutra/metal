// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_DISTINCT_HPP
#define METAL_LIST_DISTINCT_HPP

#include <metal/list/list.hpp>
#include <metal/core/inherit.hpp>
#include <metal/core/voider.hpp>

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list>
    struct distinct
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref distinct.
    template<typename list>
    using distinct_t = typename distinct<list>::type;

    namespace detail
    {
        template<typename... bases>
        boolean<true> disambiguate(bases*...);

        template<typename derived, typename... bases>
        auto is_unambiguously_derived_from(int) ->
            decltype(
                disambiguate<bases...>(
                    (voider_t<bases>(), static_cast<derived*>(0))...
                )
            );

        template<typename...>
        boolean<false> is_unambiguously_derived_from(...);
    }

    template<template<typename...> class list, typename... vals>
    struct distinct<list<vals...>> :
            decltype(
                detail::is_unambiguously_derived_from<
                    inherit<metal::list<vals>...>,
                    metal::list<vals>...
                >(0)
            )
    {};
}

#endif
