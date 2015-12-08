// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_DISTINCT_HPP
#define METAL_LIST_DISTINCT_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list>
    struct distinct
    {};

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
        template<typename... _>
        using void_t = void;

        template<typename... bases>
        boolean<true> disambiguate(bases*...);

        template<typename derived, typename... bases>
        auto is_unambiguously_derived_from(derived* _) ->
            decltype(disambiguate<bases...>((void_t<bases>(), _)...));

        template<typename...>
        boolean<false> is_unambiguously_derived_from(...);
    }

    template<template<typename...> class list, typename... vals>
    struct distinct<list<vals...>> :
        decltype(
            detail::is_unambiguously_derived_from<
                detail::inherit<metal::list<vals>...>,
                metal::list<vals>...
            >(0)
        )
    {};
}

#endif
