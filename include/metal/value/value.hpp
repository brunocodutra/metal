// Copyright Bruno Dutra 2015-2017
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

#if defined(METAL_COMPAT_MODE)
        template<typename val>
        struct _is_value;
#endif
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
    using is_value =
#if defined(METAL_COMPAT_MODE) && !defined(METAL_DOXYGENATING)
        typename detail::_is_value<val>::type;
#else
        metal::true_;
#endif

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
    ///         using result = { using type = val; };
    ///     \endcode
    ///
    /// ### Example
    /// \snippet value.cpp value
    ///
    /// ### See Also
    /// \see is_value, nil
    template<typename val = detail::na>
#if defined(METAL_DOXYGENATING)
    using value = { using type = val; };
#else
    struct value;
#endif

    /// \ingroup value
    ///
    /// ### Description
    /// An *empty* `metal::value`.
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
    ///         using result = {};
    ///     \endcode
    ///
    /// ### See Also
    /// \see is_value, value
    using nil = metal::value<>;

    /// \cond
    template<typename val>
    struct value
    {
        using type = val;
    };

    template<>
    struct value<detail::na> {};

    namespace detail
    {
#if defined(METAL_COMPAT_MODE)
        template<typename val>
        struct _is_value
        {
            using type = true_;
        };
#endif
    }
    /// \endcond
}

#endif

