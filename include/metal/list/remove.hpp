#ifndef METAL_LIST_REMOVE_HPP
#define METAL_LIST_REMOVE_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../lambda/partial.hpp"
#include "../list/remove_if.hpp"
#include "../value/same.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Removes all elements from a \list that are the same as some \value.
    ///
    /// ### Usage
    /// For any \list `l` and \value `val`
    /// \code
    ///     using result = metal::remove<l, val>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<...>;
    ///     \endcode
    ///     where `result` contains all and only the elements in `l` which are
    ///     distinct from `val`.
    ///
    /// ### Example
    /// \snippet list.cpp remove
    ///
    /// ### See Also
    /// \see list, remove_if, copy, replace
    template<typename seq, typename val>
    using remove =
        metal::remove_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}

#endif
