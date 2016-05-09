// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_OR_HPP
#define METAL_NUMBER_OR_HPP

#include <metal/number/number.hpp>
#include <metal/number/not.hpp>
#include <metal/list/list.hpp>
#include <metal/list/same.hpp>

namespace metal
{
    /// \ingroup number
    /// Computes the logical or of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \values `val1, ..., valn`
    /// \code
    ///     metal::or_<val1, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If all \values in `[val1, ..., valn]` are \numbers,
    ///     then equivalent to
    ///     \code
    ///         template<>
    ///         struct or_<val1, ..., valn> :
    ///             bool_<val1::value || ... || valn::value>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/logical.cpp or_
    ///
    /// See Also
    /// --------
    /// \see boolean, not_, and_
    template<typename... nums>
    using or_ =
        not_<same<list<true_, typename detail::_not_<nums>::type...>>>;
}

#endif
