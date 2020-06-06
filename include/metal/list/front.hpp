#ifndef METAL_LIST_FRONT_HPP
#define METAL_LIST_FRONT_HPP

#include "../config.hpp"
#include "../list/at.hpp"
#include "../number/number.hpp"

namespace metal {
/// \ingroup list
///
/// ### Description
/// Retrieves the first element of a \list.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::front<l>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = l[0];
///     \endcode
///
/// ### Example
/// \snippet list.cpp front
///
/// ### See Also
/// \see list, at, back
template <class seq>
using front = metal::at<seq, metal::number<0>>;
}

#endif
