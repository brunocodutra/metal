// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_PAIR_SECOND_HPP
#define METAL_PAIR_SECOND_HPP

namespace metal
{
    namespace detail
    {
        template<typename pair>
        struct second;
    }

    /// \ingroup pair
    /// ...
    template<typename pair>
    using second = detail::second<pair>;

    /// \ingroup pair
    /// Eager adaptor for \ref second.
    template<typename pair>
    using second_t = typename metal::second<pair>::type;
}

#include <metal/pair/pair.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename pair, typename = boolean<true>>
        struct second_impl
        {};

        template<template<typename...> class pair, typename x, typename y>
        struct second_impl<pair<x, y>, is_pair_t<pair<x, y>>>
        {
            using type = y;
        };

        template<typename pair>
        struct second :
            second_impl<pair>
        {};
    }
}

#endif
