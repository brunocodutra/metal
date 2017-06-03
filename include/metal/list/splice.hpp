// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SPLICE_HPP
#define METAL_LIST_SPLICE_HPP

#include "../config.hpp"
#include "../list/join.hpp"
#include "../list/drop.hpp"
#include "../list/take.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Splices one \list into another at an arbitrary position.
    ///
    /// ### Usage
    /// For any \lists `l_1` and `l_2` and \number `num`
    /// \code
    ///     using result = metal::splice<l_1, num, l_2>;
    /// \endcode
    ///
    /// \pre: `metal::number<0>{} &le; num{} &le; metal::size<l_1>{}`
    /// \returns: \list
    /// \semantics:
    ///     If `l_1` contains elements `l_1[0], ..., l_1[i], ..., l_1[m-1]`,
    ///     `l_2` contains elements `l_2[0], ..., l_2[n-1]` and `num{} == i`, then
    ///     \code
    ///         using result = metal::list<
    ///             l_1[0], ..., l_2[0], ..., l_2[n-1], l_1[i], ..., l_1[m-1]
    ///         >;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp splice
    ///
    /// ### See Also
    /// \see list, insert
    template<typename seq, typename num, typename other>
    using splice =
        metal::join<metal::take<seq, num>, other, metal::drop<seq, num>>;
}

#endif
