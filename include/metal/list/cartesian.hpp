// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_CARTESIAN_HPP
#define METAL_LIST_CARTESIAN_HPP

#include <metal/config.hpp>

#include <metal/list/list.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... seqs>
        struct _cartesian;

        template<typename... seqs>
        using cartesian = typename detail::_cartesian<seqs...>::type;
    }

    /// \ingroup list
    ///
    /// ### Description
    /// Computes the cartesian product of \lists.
    ///
    /// ### Usage
    /// For any \lists `l_0, ..., l_n-1`
    /// \code
    ///     using result = metal::cartesian<l_0, ..., l_n-1>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<
    ///             metal::list<l_0[x_0], ...[...], l_n-1[x_n-1]>,
    ///         >;
    ///     \endcode
    ///     where each `x` in `x_0, ..., x_n-1` varies independently from `0` to
    ///     `n-1`.
    ///
    /// ### Example
    /// \snippet list.cpp cartesian
    ///
    /// ### See Also
    /// \see list, transpose
    template<typename... seqs>
    using cartesian = detail::cartesian<if_<is_list<seqs>, seqs>...>;
}

#include <metal/list/join.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename...>
        struct _cartesian_impl
        {};

        template<typename result, typename... seqs>
        using cartesian_impl = typename _cartesian_impl<result, seqs...>::type;

        template<typename result>
        struct _cartesian_impl<result>
        {
            using type = list<result>;
        };

        template<typename... _, typename... hs, typename... tail>
        struct _cartesian_impl<list<_...>, list<hs...>, tail...>
        {
            using type = join<cartesian_impl<list<_..., hs>, tail...>...>;
        };

        template<typename... seqs>
        struct _cartesian :
            _cartesian_impl<list<>, seqs...>
        {};
    }
}

#endif
