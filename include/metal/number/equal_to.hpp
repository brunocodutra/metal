// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_EQUAL_TO_HPP
#define METAL_NUMBER_EQUAL_TO_HPP

#include <metal/number/less.hpp>
#include <metal/number/not.hpp>
#include <metal/number/or.hpp>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct _equal_to;
    }

    /// \ingroup number
    /// Checks whether two \numbers are equal.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1` and `num_2`
    /// \code
    ///     using result = metal::equal_to<num_1, num_2>;
    /// \endcode
    ///
    /// \returns: \boolean
    /// \semantics:
    ///     \code
    ///         using result = metal::bool_<num_1{} == num_2{}>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp equal_to
    ///
    /// See Also
    /// --------
    /// \see number, greater, less
    template<typename x, typename y>
    using equal_to =
        metal::not_<metal::or_<metal::less<x, y>, metal::less<y, x>>>;
}

#endif
