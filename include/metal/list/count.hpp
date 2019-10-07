#ifndef METAL_LIST_COUNT_HPP
#define METAL_LIST_COUNT_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../lambda/partial.hpp"
#include "../list/count_if.hpp"
#include "../value/same.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Counts the occurrences of a \value in a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \value `val`
    /// \code
    ///     using result = metal::count<l, val>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<n>;
    ///     \endcode
    ///     where `n` is the number of occurrences of `val` in `l`.
    ///
    /// ### Example
    /// \snippet list.cpp count
    ///
    /// ### See Also
    /// \see list, count_if, contains, find
    template<class seq, class val>
    using count =
        metal::count_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}

#endif
