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
    /// Returns the second element of a \pair.
    ///
    /// Usage
    /// -----
    /// For any \value `val`
    /// \code
    ///     metal::second<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \pair, then equivalent to
    ///     \code
    ///         template<>
    ///         struct second<val> :
    ///             at<val, integer<1>>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet pair/second.cpp second
    ///
    /// See Also
    /// --------
    /// \see pair, first, at
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
