// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_COMBINE_HPP
#define METAL_LIST_COMBINE_HPP

#include "../config.hpp"
#include "../lambda/apply.hpp"
#include "../lambda/lambda.hpp"
#include "../list/cartesian.hpp"
#include "../list/repeat.hpp"
#include "../list/size.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Computes all possible combinations (with repetition) from the
    /// elements in a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \number `num`
    /// \code
    ///     using result = metal::combine<l, num>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]` and `num` holds the
    ///     constant `n`, then
    ///     \code
    ///         using result = metal::list<
    ///             metal::list<l[x_0], ...[...], l[x_n-1]>,
    ///         >;
    ///     \endcode
    ///     where each `x` in `x_0, ..., x_n-1` varies independently from `0` to
    ///     `m-1`.
    ///
    /// ### Example
    /// \snippet list.cpp combine
    ///
    /// ### See Also
    /// \see list, powerset, cartesian, cascade
    template<typename seq, typename num = metal::size<seq>>
    using combine = metal::apply<
        metal::lambda<metal::cartesian>,
        metal::repeat<metal::if_<metal::is_list<seq>, seq>, num>>;
}

#endif
