#ifndef METAL_LIST_BACK_HPP
#define METAL_LIST_BACK_HPP

#include "../config.hpp"
#include "../list/at.hpp"
#include "../list/size.hpp"
#include "../number/dec.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Retrieves the last element of a \list.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::back<l>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = l[m-1];
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp back
    ///
    /// ### See Also
    /// \see list, at, front
    template<typename seq>
    using back = metal::at<seq, metal::dec<metal::size<seq>>>;
}

#endif
