#ifndef METAL_NUMBER_NOT_HPP
#define METAL_NUMBER_NOT_HPP

#include "../config.hpp"
#include "../number/if.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \ingroup number
    ///
    /// ### Description
    /// Computes the logical inverse of a \number.
    ///
    /// ### Usage
    /// For any \number `num`
    /// \code
    ///     using result = metal::not_<num>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<!num{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp not_
    ///
    /// ### See Also
    /// \see number, and_, or_
    template<class num>
    using not_ = metal::if_<num, metal::false_, metal::true_>;
}

#endif
