#ifndef METAL_LIST_EMPTY_HPP
#define METAL_LIST_EMPTY_HPP

#include "../config.hpp"
#include "../list/size.hpp"
#include "../number/not.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Checks whether a \list has no elements.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::empty<l>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `l` contains at least one element, then
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp empty
    ///
    /// ### See Also
    /// \see list, size
    template<class seq>
    using empty = metal::not_<metal::size<seq>>;
}

#endif
