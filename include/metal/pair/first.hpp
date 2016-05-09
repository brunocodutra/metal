// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_PAIR_FIRST_HPP
#define METAL_PAIR_FIRST_HPP

#include <metal/pair/pair.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup pair
    /// Returns the first element of a \pair.
    ///
    /// Usage
    /// -----
    /// For any \value `val`
    /// \code
    ///     metal::first<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \pair, then equivalent to
    ///     \code
    ///         template<>
    ///         struct first<val> :
    ///             at<val, size_t<0>>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet pair/first.cpp first
    ///
    /// See Also
    /// --------
    /// \see pair, second, at
    template<typename seq>
    using first = if_<is_pair<seq>, apply<_1, seq>>;
}

#endif
