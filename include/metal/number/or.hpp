#ifndef METAL_NUMBER_OR_HPP
#define METAL_NUMBER_OR_HPP

#include "../config.hpp"
#include "../number/not.hpp"
#include "../number/number.hpp"
#include "../value/same.hpp"

namespace metal {
/// \ingroup number
///
/// ### Description
/// Computes the logical disjunction of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::or_<num_0, ..., num_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num_0{} || ... || num_n-1{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp or_
///
/// ### See Also
/// \see number, not_, and_
template <class... nums>
using or_ = metal::not_<metal::same<metal::true_, metal::not_<nums>...>>;
}

#endif
