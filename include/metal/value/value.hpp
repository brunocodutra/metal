// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_VALUE_VALUE_HPP
#define METAL_VALUE_VALUE_HPP

#include <metal/config.hpp>

#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        struct na;

        template<typename val = na>
        struct value;
    }
    /// \endcond

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
    /// \see value, nil, is_number, is_lambda, is_pair, is_list, is_map
    template<typename val>
    using is_value = metal::true_;

    /// \ingroup value
    ///
    /// ### Description
    /// Constructs a \value that is guaranteed not to be a \number, or a
    /// \lambda or a \list, out of any other \value.
    ///
    /// The original \value may be retrieved back by naming the nested typename
    /// `type`, unless `metal::value` is [empty](\ref nil), in which case `type`
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

    /// \cond
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
    /// \endcond
}

#endif

