// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_PAIR_FIRST_HPP
#define METAL_PAIR_FIRST_HPP

namespace metal
{
    namespace detail
    {
        template<typename pair>
        struct first;
    }

    /// \ingroup pair
    /// Returns the first element of a \pair.
    ///
    /// Usage
    /// -----
    /// For any \value `val`
    /// \code
    ///     using result = metal::first<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \pair, then equivalent to
    ///     \code
    ///         struct result :
    ///             metal::at<val, metal::integer<0>>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet pair/first.cpp first
    ///
    /// See Also
    /// --------
    /// \see pair, second, at
    template<typename pair>
    using first = detail::first<pair>;

    /// \ingroup pair
    /// Eager adaptor for \ref first.
    template<typename pair>
    using first_t = typename metal::first<pair>::type;
}

#include <metal/pair/pair.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename pair, typename = boolean<true>>
        struct first_impl
        {};

        template<template<typename...> class pair, typename x, typename y>
        struct first_impl<pair<x, y>, is_pair_t<pair<x, y>>>
        {
            using type = x;
        };

        template<typename pair>
        struct first :
            first_impl<pair>
        {};
    }
}


#endif
