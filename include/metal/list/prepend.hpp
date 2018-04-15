#ifndef METAL_LIST_PREPEND_HPP
#define METAL_LIST_PREPEND_HPP

#include "../config.hpp"
#include "../list/join.hpp"
#include "../list/list.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Inserts \values at the beginning of a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::prepend<l, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = metal::list<
    ///             val_0, ..., val_n-1, l[0], ..., l[m-1]
    ///         >;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp prepend
    ///
    /// ### See Also
    /// \see list, insert, append
    template<typename seq, typename... vals>
    using prepend = metal::join<metal::list<vals...>, seq>;
}

#endif
