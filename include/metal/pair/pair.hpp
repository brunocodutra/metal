// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_PAIR_PAIR_HPP
#define METAL_PAIR_PAIR_HPP

#include <metal/list/list.hpp>

namespace metal
{
    namespace detail
    {
        template<typename pair>
        struct is_pair;
    }

    /// \ingroup pair
    /// ...
    template<typename x, typename y>
    using pair = metal::list<x, y>;

    /// \ingroup pair
    /// ...
    template<typename pair>
    using is_pair = detail::is_pair<pair>;

    /// \ingroup pair
    /// Eager adaptor for \ref is_pair.
    template<typename pair>
    using is_pair_t = typename metal::is_pair<pair>::type;
}

#include <metal/list/size.hpp>
#include <metal/number/number.hpp>
#include <metal/number/comparison/equal_to.hpp>

namespace metal
{
    namespace detail
    {
        template<typename>
        struct is_pair :
            boolean<false>
        {};

        template<template<typename...> class pair, typename x, typename y>
        struct is_pair<pair<x, y>> :
            equal_to<size_t<pair<x, y>>, integer<2>>
        {};
    }
}

#endif
