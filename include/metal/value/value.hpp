#ifndef METAL_VALUE_VALUE_HPP
#define METAL_VALUE_VALUE_HPP

#include "../config.hpp"
#include "../number/number.hpp"

namespace metal {
/// \cond
namespace detail {
    struct na;

    template <class val>
    struct maybe;

#if defined(METAL_WORKAROUND)
    template <class val>
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
template <class val>
using is_value =
#if defined(METAL_WORKAROUND)
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
template <class val = detail::na>
#if defined(METAL_DOXYGENATING)
using value = struct {
    using type = val;
};
#else
using value = detail::maybe<val>;
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
namespace detail {
    template <class val>
    struct maybe {
        using type = val;
    };

    template <>
    struct maybe<detail::na> {
    };

#if defined(METAL_WORKAROUND)
    template <class val>
    struct _is_value {
        using type = true_;
    };
#endif
}
/// \endcond
}

#endif
