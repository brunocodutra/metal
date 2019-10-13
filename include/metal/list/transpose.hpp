#ifndef METAL_LIST_TRANSPOSE_HPP
#define METAL_LIST_TRANSPOSE_HPP

#include "../config.hpp"
#include "../lambda/apply.hpp"
#include "../lambda/lambda.hpp"
#include "../lambda/partial.hpp"
#include "../list/list.hpp"
#include "../list/transform.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Transposes a \list of \lists.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::transpose<l>;
    /// \endcode
    ///
    /// \pre: If `l` contains elements `l[0], ..., l[m-1]`,
    /// `metal::size<l[0]>{} == metal::size<>{}... == metal::size<l[n-1]>{}`
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<
    ///             metal::list<l[0][0], ...[0], l[m-1][0]>,
    ///             ...,
    ///             metal::list<l[0][n-1], ...[n-1], l[m-1][n-1]>
    ///         >;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp transpose
    ///
    /// ### See Also
    /// \see list, cartesian
    template<class seq>
    using transpose = metal::apply<
        metal::partial<
            metal::lambda<metal::transform>, metal::lambda<metal::list>>,
        seq>;
}

#endif
