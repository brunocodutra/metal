// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SIZE_HPP
#define METAL_LIST_SIZE_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename seq>
        struct _size;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Returns the number of elements in a \list.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::size<l>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = metal::number<m>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp size
    ///
    /// ### See Also
    /// \see list, empty
    template<typename seq>
    using size = typename detail::_size<seq>::type;
}

#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename seq>
        struct _size
        {};

        template<typename... vals>
        struct _size<list<vals...>> :
            number<sizeof...(vals)>
        {};
    }
    /// \endcond
}

#endif
