#ifndef METAL_LIST_REPLACE_HPP
#define METAL_LIST_REPLACE_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../lambda/partial.hpp"
#include "../list/replace_if.hpp"
#include "../value/same.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Replaces every occurrence of a \value in a \list by another \value.
    ///
    /// ### Usage
    /// For any \list `l` and \values `val` and `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::replace<l, val, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<...>;
    ///     \endcode
    ///     where `result` contains all and only the elements in `l`, except
    ///     that every occurrence of `val` has been replaced by
    ///     `val_0, ..., val_n-1`.
    ///
    /// ### Example
    /// \snippet list.cpp replace
    ///
    /// ### See Also
    /// \see list, replace_if, copy, remove
    template<typename seq, typename val, typename... vals>
    using replace = metal::replace_if<
        seq, metal::partial<metal::lambda<metal::same>, val>, vals...>;
}

#endif
