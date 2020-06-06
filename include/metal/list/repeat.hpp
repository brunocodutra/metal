#ifndef METAL_LIST_REPEAT_HPP
#define METAL_LIST_REPEAT_HPP

#include "../config.hpp"
#include "../lambda/always.hpp"
#include "../list/iota.hpp"
#include "../list/transform.hpp"

namespace metal {
/// \ingroup list
///
/// ### Description
/// Returns a \list that contains a \number of copies of the same \value.
///
/// ### Usage
/// For any \value `val` and \number `num`
/// \code
///     using result = metal::repeat<val, num>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `num` holds the constant `n`, then
///     \code
///         using result = metal::list<val_0, ..., val_n-1>;
///     \endcode
///     where `val_0, ..., val_n-1` are all identical to `val`.
///
/// ### Example
/// \snippet list.cpp repeat
///
/// ### See Also
/// \see list, iota
template <class val, class num>
using repeat = metal::transform<
    metal::always<val>,
    metal::iota<metal::number<0>, num, metal::number<0>>>;
}

#endif
