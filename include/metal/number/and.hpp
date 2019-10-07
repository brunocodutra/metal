#ifndef METAL_NUMBER_AND_HPP
#define METAL_NUMBER_AND_HPP

#include "../config.hpp"
#include "../number/not.hpp"
#include "../number/number.hpp"
#include "../value/same.hpp"

namespace metal {
    /// \ingroup number
    ///
    /// ### Description
    /// Computes the logical conjunction of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::and_<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} && ... && num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp and_
    ///
    /// ### See Also
    /// \see number, not_, or_
    template<class... nums>
    using and_ = metal::same<metal::false_, metal::not_<nums>...>;
}

#endif
