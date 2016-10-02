// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_VALUE_VALUE_HPP
#define METAL_VALUE_VALUE_HPP

#include <metal/config.hpp>

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        struct na;

        template<typename val = na>
        struct value;
    }

    /// \ingroup value
    ///
    /// ### Description
    /// A tautological predicate that checks whether some type is a \value.
    ///
    /// \tip{Use `metal::is_value` to trigger \SFINAE.}
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::is_value<val>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet value.cpp is_value
    ///
    /// ### See Also
    /// \see value, nil
    template<typename val>
    using is_value = metal::true_;

    /// \ingroup value
    ///
    /// ### Description
    /// Constructs a \value that is guaranteed not to be a \number, or a
    /// \lambda or a \list, out of any other \value.
    ///
    /// The original \value may be retrieved back by naming its nested typename
    /// `::type`, unless `metal::value` is [empty](\ref nil), in which case it
    /// is undefined.
    ///
    /// \tip{Use `metal::value` to prevent undesired template pattern matching.}
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::value<val>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = struct {using type = val;};
    ///     \endcode
    ///
    /// ### Example
    /// \snippet value.cpp value
    ///
    /// ### See Also
    /// \see is_value, nil
    template<typename val = detail::na>
    using value = detail::value<val>;

    /// \ingroup value
    ///
    /// ### Description
    /// An *empty* `metal::value`.
    ///
    /// \tip{Use `metal::nil` and `metal::value` to emulate [optionals].}
    /// [optionals]: http://en.cppreference.com/w/cpp/utility/optional
    ///
    /// ### Usage
    ///
    /// \code
    ///     using result = metal::nil;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = struct {};
    ///     \endcode
    ///
    /// ### See Also
    /// \see is_value, value
    using nil = metal::value<>;

    namespace detail
    {
        template<typename val>
        struct value
        {
            using type = val;
        };

        template<>
        struct value<na> {};
    }
}

#endif

