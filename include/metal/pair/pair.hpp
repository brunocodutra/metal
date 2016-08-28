// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_PAIR_PAIR_HPP
#define METAL_PAIR_PAIR_HPP

#include <metal/config.hpp>

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
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::is_pair<val>;
    /// \endcode
    ///
    /// \returns: \number of type `bool`
    /// \semantics:
    ///     If `val` is a \pair, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet pair.cpp is_pair
    ///
    /// ### See Also
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

        template<typename x, typename y>
        struct _is_pair<list<x, y>> :
            true_
        {};
    }
}

#endif
