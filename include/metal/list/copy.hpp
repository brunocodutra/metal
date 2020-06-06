#ifndef METAL_LIST_COPY_HPP
#define METAL_LIST_COPY_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../lambda/partial.hpp"
#include "../list/copy_if.hpp"
#include "../value/same.hpp"

namespace metal {
/// \ingroup list
///
/// ### Description
/// Removes all elements from a \list except for those that are the same as
/// some \value.
///
/// ### Usage
/// For any \list `l` and \value `val`
/// \code
///     using result = metal::copy<l, val>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<...>;
///     \endcode
///     where `result` contains all and only the occurrences of `val` in
///     `l`.
///
/// ### Example
/// \snippet list.cpp copy
///
/// ### See Also
/// \see list, copy_if, remove, replace
template <class seq, class val>
using copy = metal::copy_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}

#endif
