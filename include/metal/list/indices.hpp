#ifndef METAL_LIST_INDICES_HPP
#define METAL_LIST_INDICES_HPP

#include "../config.hpp"
#include "../list/iota.hpp"
#include "../list/size.hpp"
#include "../number/number.hpp"

namespace metal {
/// \ingroup list
///
/// ### Description
/// Replaces each element of a \list by its corresponding index.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::indices<l>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::list<
///             metal::number<0>, metal::number<>..., metal::number<m-1>
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp indices
///
/// ### See Also
/// \see list, iota
template <class seq>
using indices = metal::iota<metal::number<0>, metal::size<seq>>;
}

#endif
