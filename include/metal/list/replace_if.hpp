// Copyright Bruno Dutra 2015-2017
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
        template<typename, typename, typename...>
        struct _replace_if;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Replaces every element in a \list that satisfies a predicate by some
    /// \value.
    ///
    /// ### Usage
    /// For any \list `l`, \lambda `lbd` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::replace_if<l, lbd, val_0, ..., val_n-1>;
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
    ///     `metal::invoke<lbd, l[i]>{} != false` has been replaced by
    ///     `val_0, ..., val_n-1`.
    ///
    /// ### Example
    /// \snippet list.cpp replace_if
    ///
    /// ### See Also
    /// \see list, replace, copy_if, remove_if
    template<typename seq, typename lbd, typename... vals>
    using replace_if = typename detail::_replace_if<
        seq, transform<lbd, seq>, vals...
    >::type;
}

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>
#include <metal/number/if.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename vals, typename vs, typename...>
        struct _replace_if
        {};

        template<typename... vals, int_... vs, typename x, typename y, typename... t>
        struct _replace_if<list<vals...>, list<number<vs>...>, x, y, t...> :
            _join<if_<number<vs>, list<x, y, t...>, list<vals>>...>
        {};

        template<typename... vals, int_... vs, typename x>
        struct _replace_if<list<vals...>, list<number<vs>...>, x>
        {
            using type = list<if_<number<vs>, x, vals>...>;
        };

        template<typename... vals, int_... vs>
        struct _replace_if<list<vals...>, list<number<vs>...>> :
            _join<if_<number<vs>, list<>, list<vals>>...>
        {};

        template<typename x, typename y, typename... t>
        struct _replace_if<list<>, list<>, x, y, t...>
        {
            using type = list<>;
        };

        template<typename x>
        struct _replace_if<list<>, list<>, x>
        {
            using type = list<>;
        };

        template<>
        struct _replace_if<list<>, list<>>
        {
            using type = list<>;
        };
    }
    /// \endcond
}

#endif
