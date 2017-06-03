// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SLICE_HPP
#define METAL_LIST_SLICE_HPP

#include "../config.hpp"
#include "../list/at.hpp"
#include "../list/list.hpp"
#include "../list/iota.hpp"
#include "../list/transform.hpp"
#include "../lambda/lambda.hpp"
#include "../lambda/partial.hpp"
#include "../number/if.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Returns a subset of elements in a \list picked at regular intervals in a
    /// range.
    ///
    /// ### Usage
    /// For any \list `l` and \numbers `st`, `sz` and `sd`
    /// \code
    ///     using result = metal::slice<l, st, sz, sd>;
    /// \endcode
    ///
    /// \pre: `metal::number<0>{} &le; n{} &le; metal::size<l>{}` for all `n` in
    /// `metal::iota<st, sz, sd>`
    /// \returns: \list
    /// \semantics:
    ///     If `metal::iota<st, sz, sd>` contains \numbers
    ///     `num_0, ..., num_n-1`, then
    ///     \code
    ///         using result = metal::list<l[num_0], ..., l[num_n-1]>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp slice
    ///
    /// ### See Also
    /// \see list, range
    template<
        typename seq,
        typename start, typename size, typename stride = number<1>
    >
    using slice = metal::transform<
        metal::partial<
            metal::lambda<metal::at>,
            metal::if_<metal::is_list<seq>, seq>
        >,
        metal::iota<start, size, stride>
    >;
}

#endif
