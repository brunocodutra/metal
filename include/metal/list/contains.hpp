#ifndef METAL_LIST_CONTAINS_HPP
#define METAL_LIST_CONTAINS_HPP

#include "../config.hpp"
#include "../lambda/arg.hpp"
#include "../lambda/lambda.hpp"
#include "../lambda/partial.hpp"
#include "../list/any_of.hpp"
#include "../value/same.hpp"

namespace metal {
/// \ingroup list
///
/// ### Description
/// Checks whether a \value is contained in a \list.
///
/// ### Usage
/// For any \list `l` and \value `val`
/// \code
///     using result = metal::contains<l, val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `val` is contained in `l`, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet list.cpp contains
///
/// ### See Also
/// \see list, count, find
template <class seq, class val>
using contains = metal::any_of<seq, metal::partial<metal::lambda<metal::same>, val>>;
}

#endif
