// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_PAIR_PAIR_HPP
#define METAL_PAIR_PAIR_HPP

#include <metal/list/list.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _is_pair;
    }

    /// \ingroup pair
    /// Checks whether some \value is a \pair.
    ///
    /// Usage
    /// -----
    /// For any \value `val`
    /// \code
    ///     metal::is_pair<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \pair, then equivalent to
    ///     \code
    ///         template<>
    ///         struct is_pair<val> :
    ///             true_
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         template<>
    ///         struct is_pair<val> :
    ///             false_
    ///         {};
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet pair/pair.cpp is_pair
    ///
    /// See Also
    /// --------
    /// \see pair
    template<typename val>
    using is_pair = typename detail::_is_pair<val>::type;

    /// \ingroup pair
    /// The standard constructor for \pairs.
    template<typename x, typename y>
    using pair = metal::list<x, y>;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _is_pair :
            false_
        {};

        template<template<typename...> class seq, typename... vals>
        struct _is_pair<seq<vals...>> :
            bool_<sizeof...(vals) == 2>
        {};
    }
}

#endif
