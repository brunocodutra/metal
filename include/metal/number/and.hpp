// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_AND_HPP
#define METAL_NUMBER_AND_HPP

#include <metal/number/number.hpp>
#include <metal/number/not.hpp>
#include <metal/list/list.hpp>
#include <metal/list/same.hpp>

namespace metal
{
    /// \ingroup number
    /// Computes the logical and of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \values `val1, ..., valn`
    /// \code
    ///     metal::and_<val1, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If all \values in `[val1, ..., valn]` are \numbers,
    ///     then equivalent to
    ///     \code
    ///         template<>
    ///         struct and_<val1, ..., valn> :
    ///             bool_<val1::value && ... && valn::value>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/logical.cpp and_
    ///
    /// See Also
    /// --------
    /// \see boolean, not_, or_
    template<typename... nums>
    using and_ = same<list<false_, typename detail::_not_<nums>::type...>>;
}

#endif
