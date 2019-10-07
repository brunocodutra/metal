#ifndef METAL_NUMBER_MAX_HPP
#define METAL_NUMBER_MAX_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../number/greater.hpp"
#include "../number/if.hpp"
#include "../number/number.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class x, class y>
        using max = if_<greater<x, y>, x, y>;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the maximum of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::max<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `M` the maximum between all \numbers in `num_0, ..., num_n-1`,
    ///     then
    ///     \code
    ///         using result = M;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp max
    ///
    /// ### See Also
    /// \see number, greater, less, min
    template<class... nums>
    using max = fold_left<lambda<detail::max>, if_<is_number<nums>, nums>...>;
}

#endif
