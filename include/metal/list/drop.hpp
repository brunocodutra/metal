#ifndef METAL_LIST_DROP_HPP
#define METAL_LIST_DROP_HPP

#include "../config.hpp"
#include "../list/range.hpp"
#include "../list/size.hpp"

namespace metal {
/// \ingroup list
///
/// ### Description
/// Removes all elements from the beginning up to an arbitrary index of a
/// \list.
///
/// ### Usage
/// For any \list `l` and \number `num`
/// \code
///     using result = metal::drop<l, num>;
/// \endcode
///
/// \pre: `metal::number<0>{} &le; num{} &le; metal::size<l>{}`
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[i], ..., l[m-1]` and
///     `num{} == i`, then
///     \code
///         using result = metal::list<l[i], ..., l[m-1]>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp drop
///
/// ### See Also
/// \see list, range, erase, take
template <class seq, class n>
using drop = metal::range<seq, n, metal::size<seq>>;
}

#endif
