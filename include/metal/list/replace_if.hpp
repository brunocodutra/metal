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
        seq, transform<lbd, seq>, list<vals...>
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
        template<typename, typename, typename>
        struct _replace_if_impl
        {};

        template<typename... vals, int_... vs, typename seq>
        struct _replace_if_impl<list<vals...>, list<number<vs>...>, seq> :
            _join<if_<number<vs>, seq, list<vals>>...>
        {};

        template<typename vals, typename vs, typename seq>
        struct _replace_if :
            _replace_if_impl<vals, vs, seq>
        {};

        template<typename... vals, int_... vs, typename val>
        struct _replace_if<list<vals...>, list<number<vs>...>, list<val>>
        {
            using type = list<if_<number<vs>, val, vals>...>;
        };

#if defined(METAL_COMPAT_MODE)
        template<typename seq>
        struct _replace_if<list<>, list<>, seq>
        {
            using type = list<>;
        };
#endif
    }
    /// \endcond
}

#endif
