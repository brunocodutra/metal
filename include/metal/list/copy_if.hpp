// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_COPY_IF_HPP
#define METAL_LIST_COPY_IF_HPP

#include <metal/config.hpp>

#include <metal/list/transform.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename seq, typename nums>
        struct _copy_if_impl;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Removes all elements from a \list except for those that satisfy a
    /// predicate.
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::copy_if<l, lbd>;
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
    ///     where `result` contains all and only the elements `l[i]` in `l` for
    ///     which `metal::invoke<lbd, l[i]>{} != false`.
    ///
    /// ### Example
    /// \snippet list.cpp copy_if
    ///
    /// ### See Also
    /// \see list, copy, remove_if, replace_if
    template<typename seq, typename lbd>
    using copy_if =
        typename detail::_copy_if_impl<seq, transform<lbd, seq>>::type;
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
        template<typename seq, typename nums>
        struct _copy_if_impl
        {};

        template<>
        struct _copy_if_impl<list<>, list<>>
        {
            using type = list<>;
        };

        template<typename... vals, int_... vs>
        struct _copy_if_impl<list<vals...>, list<number<vs>...>> :
            _join<if_<number<vs>, list<vals>, list<>>...>
        {};
    }
    /// \endcond
}

#endif
