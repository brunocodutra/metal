// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_REPLACE_IF_HPP
#define METAL_LIST_REPLACE_IF_HPP

#include <metal/config.hpp>

#include <metal/list/transform.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename, typename, typename>
        struct _replace_if_impl;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Replaces every element in a \list that satisfies a predicate by some
    /// \value.
    ///
    /// ### Usage
    /// For any \list `l`, \lambda `lbd` and \value `val`
    /// \code
    ///     using result = metal::replace_if<l, lbd, val>;
    /// \endcode
    ///
    /// \pre: For any element `l[i]` contained in `l`,
    /// `metal::invoke<lbd, l[i]>` returns a \number
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<...>;
    ///     \endcode
    ///     where `result` contains all and only the elements in `l`, except
    ///     that every element `l[i]` for which
    ///     `metal::invoke<lbd, l[i]>{} != false` has been replaced by `val`.
    ///
    /// ### Example
    /// \snippet list.cpp replace_if
    ///
    /// ### See Also
    /// \see list, replace, copy_if, remove_if
    template<typename seq, typename lbd, typename val>
    using replace_if =
        typename detail::_replace_if_impl<seq, transform<lbd, seq>, val>::type;
}

#include <metal/list/list.hpp>
#include <metal/number/if.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename, typename, typename>
        struct _replace_if_impl
        {};

        template<typename val>
        struct _replace_if_impl<list<>, list<>, val>
        {
            using type = list<>;
        };

        template<typename... vals, int_... vs, typename val>
        struct _replace_if_impl<list<vals...>, list<number<vs>...>, val>
        {
            using type = list<if_<number<vs>, val, vals>...>;
        };
    }
    /// \endcond
}

#endif
