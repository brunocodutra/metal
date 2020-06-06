#ifndef METAL_PAIR_PAIR_HPP
#define METAL_PAIR_PAIR_HPP

#include "../config.hpp"
#include "../lambda/apply.hpp"
#include "../lambda/lambda.hpp"
#include "../list/list.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_pair;
}
/// \endcond

/// \ingroup pair
///
/// ### Description
/// Checks whether some \value is a \pair.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::is_pair<val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `val` is a \pair, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet pair.cpp is_pair
///
/// ### See Also
/// \see pair, is_value, is_number, is_lambda, is_list, is_map
template <class val>
using is_pair = typename detail::_is_pair<val>::type;

/// \ingroup pair
///
/// ### Description
/// Constructs a \pair out of a pair of \values.
///
/// ### Usage
/// For any pair of \values `x` and `y`
/// \code
///     using result = metal::pair<x, y>;
/// \endcode
///
/// \returns: \pair
///
/// ### See Also
/// \see is_pair
template <class x, class y>
using pair = metal::list<x, y>;

/// \ingroup pair
///
/// ### Description
/// Constructs a \pair out of any \value that is a specialization of a
/// template class or union that takes exactly two template parameters that
/// are themselves \values.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::as_pair<val>;
/// \endcode
///
/// \returns: \pair
///
/// ### Example
/// \snippet pair.cpp as_pair
///
/// ### See Also
/// \see pair
template <class val>
using as_pair = metal::apply<metal::lambda<metal::pair>, metal::as_list<val>>;
}

#include "../number/number.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_pair : false_ {
    };

    template <class x, class y>
    struct _is_pair<list<x, y>> : true_ {
    };
}
/// \endcond
}

#endif
