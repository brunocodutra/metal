#ifndef METAL_LIST_SIZE_HPP
#define METAL_LIST_SIZE_HPP

#include "../config.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class seq>
    struct _size;
}
/// \endcond

/// \ingroup list
///
/// ### Description
/// Returns the number of elements in a \list.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::size<l>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::number<m>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp size
///
/// ### See Also
/// \see list, empty
template <class seq>
using size = typename detail::_size<seq>::type;
}

#include "../list/list.hpp"
#include "../number/number.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class seq>
    struct _size {
    };

    template <class... vals>
    struct _size<list<vals...>> : number<sizeof...(vals)> {
    };
}
/// \endcond
}

#endif
