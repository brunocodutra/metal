#ifndef METAL_LIST_FLATTEN_HPP
#define METAL_LIST_FLATTEN_HPP

#include "../config.hpp"
#include "../lambda/apply.hpp"
#include "../lambda/lambda.hpp"
#include "../list/join.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Collapses a \list of \lists into a flat \list that contains all the
    /// elements of the inner \lists preserving their order.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::flatten<l>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = metal::list<l[0][:], ...[:], l[n-1][:]>;
    ///     \endcode
    ///     where `l[:]` stands for the expansion of all elements contained in
    ///     `l`.
    ///
    /// ### Example
    /// \snippet list.cpp flatten
    ///
    /// ### See Also
    /// \see list, join
    template<class seq>
    using flatten = metal::apply<metal::lambda<metal::join>, seq>;
}

#endif
