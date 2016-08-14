// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_AND_HPP
#define METAL_NUMBER_AND_HPP

#include <metal/number/number.hpp>
#include <metal/number/not.hpp>
#include <metal/value/same.hpp>

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
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num_1{} && ... && num_n{}>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp and_
    ///
    /// See Also
    /// --------
    /// \see number, not_, or_
    template<typename... nums>
    using and_ = metal::same<metal::false_, metal::not_<nums>...>;
}

#endif
