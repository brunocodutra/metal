#ifndef METAL_PAIR_FIRST_HPP
#define METAL_PAIR_FIRST_HPP

#include "../config.hpp"
#include "../list/front.hpp"
#include "../number/if.hpp"
#include "../pair/pair.hpp"

namespace metal {
    /// \ingroup pair
    ///
    /// ### Description
    /// Retrieves the first element of a \pair.
    ///
    /// ### Usage
    /// For any \pair `p`
    /// \code
    ///     using result = metal::first<p>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `p` contains \values `p_0` and `p_1` in that order, then
    ///     \code
    ///         using result = p_0;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet pair.cpp first
    ///
    /// ### See Also
    /// \see pair, second
    template<typename seq>
    using first = metal::if_<metal::is_pair<seq>, metal::front<seq>>;
}

#endif
