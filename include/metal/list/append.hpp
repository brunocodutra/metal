#ifndef METAL_LIST_APPEND_HPP
#define METAL_LIST_APPEND_HPP

#include "../config.hpp"
#include "../list/join.hpp"
#include "../list/list.hpp"

namespace metal {
/// \ingroup list
///
/// ### Description
/// Inserts \values at the end of a \list.
///
/// ### Usage
/// For any \list `l` and \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::append<l, val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::list<
///             l[0], ..., l[m-1], val_0, ..., val_n-1
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp append
///
/// ### See Also
/// \see list, insert, prepend
template <class seq, class... vals>
using append = metal::join<seq, metal::list<vals...>>;
}

#endif
