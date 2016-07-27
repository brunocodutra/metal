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
    /// Computes the logical conjunction of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1, ..., num_n`
    /// \code
    ///     using result = metal::and_<num_1, ..., num_n>;
    /// \endcode
    ///
    /// \returns: \boolean
    /// \semantics:
    ///     \code
    ///         using result = metal::bool_<num_1{} && ... && num_n{}>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp and_
    ///
    /// See Also
    /// --------
    /// \see not_, or_
    template<typename... nums>
    using and_ = same<list<false_, typename detail::_not_<nums>::type...>>;
}

#endif
