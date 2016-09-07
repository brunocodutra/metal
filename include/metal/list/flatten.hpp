// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FLATTEN_HPP
#define METAL_LIST_FLATTEN_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename seq>
        struct _flatten;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Flattens a \list by recursively replacing its sub-\lists by their
    /// contents.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::flatten<l>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<...>;
    ///     \endcode
    ///     where `result` is *flat* (i.e. contains no sub-\lists) and contains
    ///     all the elements in `l` and in all its sub-\lists.
    ///
    /// ### Example
    /// \snippet list.cpp flatten
    ///
    /// ### See Also
    /// \see list, join
    template<typename seq>
    using flatten = typename detail::_flatten<seq>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename seq>
        struct _flatten
        {};

        template<typename... vals>
        struct _flatten<list<vals...>> :
            _join<flatten<list<vals>>...>
        {};

        template<typename... vals>
        struct _flatten<list<list<vals...>>> :
            _flatten<list<vals...>>
        {};

        template<typename val>
        struct _flatten<list<val>>
        {
            using type = list<val>;
        };

        template<>
        struct _flatten<list<>>
        {
            using type = list<>;
        };
    }
    /// \endcond
}

#endif
