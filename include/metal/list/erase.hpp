// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_ERASE_HPP
#define METAL_LIST_ERASE_HPP

#include "../config.hpp"
#include "../list/drop.hpp"
#include "../list/join.hpp"
#include "../list/take.hpp"
#include "../number/inc.hpp"
#include "../number/max.hpp"
#include "../number/min.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Removes all elements between two arbitrary indices of a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \numbers `beg` and `end`
    /// \code
    ///     using result = metal::erase<l, beg, end>;
    /// \endcode
    ///
    /// \pre: `metal::number<0>{} &le; beg{} &le; metal::size<l>{}` and
    /// `metal::number<0>{} &le; end{} &le; metal::size<l>{}`
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[i], ..., l[j], ..., l[m-1]`
    ///     and either `beg{} == i` and `end{} == j` or
    ///     `beg{} == j` and `end{} == i`, then
    ///     \code
    ///         using result = metal::list<
    ///             l[0], ..., l[i-1], l[j], ..., l[m-1]
    ///         >;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp erase
    ///
    /// ### See Also
    /// \see list, range, take, drop
    template<typename seq, typename beg, typename end = inc<beg>>
    using erase = metal::join<
        metal::take<seq, metal::min<beg, end>>,
        metal::drop<seq, metal::max<beg, end>>>;
}

#endif
