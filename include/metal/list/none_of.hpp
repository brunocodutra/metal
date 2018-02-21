// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_NONE_OF_HPP
#define METAL_LIST_NONE_OF_HPP

#include "../config.hpp"
#include "../list/any_of.hpp"
#include "../number/not.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Checks whether a predicate does not hold for any element of a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::none_of<l, lbd>;
    /// \endcode
    ///
    /// \pre: For any element `l[i]` contained in `l`,
    /// `metal::invoke<lbd, l[i]>` returns a \number
    /// \returns: \number
    /// \semantics:
    ///     If `metal::invoke<lbd, l[i]>{} == false` for all `l[i]` contained in
    ///     `l`, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp none_of
    ///
    /// ### See Also
    /// \see list, all_of, any_of
    template<typename seq, typename lbd>
    using none_of = metal::not_<metal::any_of<seq, lbd>>;
}

#endif
