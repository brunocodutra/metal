#ifndef METAL_LIST_POWERSET_HPP
#define METAL_LIST_POWERSET_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../list/accumulate.hpp"
#include "../list/list.hpp"
#include "../list/reverse.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class, class>
    struct _power;

    template <class seqs, class val>
    using power = typename _power<seqs, val>::type;
}
/// \endcond

/// \ingroup list
///
/// ### Description
/// Computes the powerset of a \list.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::powerset<l>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::list<metal::list<l[2^m]>...>;
///     \endcode
///     where the notation `l[2^m]` stands for the expansion of all elements
///     in `l`, whose indices correspond to _1-bits_ of the number `2^m`
///     written in binary base and `metal::list<l[2^m]>...` stands for the
///     expansion for all numbers in `0...2^m`.
///
/// ### Example
/// \snippet list.cpp powerset
///
/// ### See Also
/// \see list, combine, cartesian, cascade
template <class seq>
using powerset = accumulate<lambda<detail::power>, list<list<>>, metal::reverse<seq>>;
}

#include "../list/join.hpp"

namespace metal {
/// \cond
namespace detail {
    template <class, class>
    struct _power_impl {
    };

    template <class... xs, class y>
    struct _power_impl<list<xs...>, y> {
        using type = list<list<xs...>, list<y, xs...>>;
    };

    template <class xs, class y>
    using power_impl = typename _power_impl<xs, y>::type;

    template <class, class>
    struct _power {
    };

    template <class... seqs, class val>
    struct _power<list<seqs...>, val> {
        using type = join<power_impl<seqs, val>...>;
    };
}
/// \endcond
}

#endif
