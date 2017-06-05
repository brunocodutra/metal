// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_CARTESIAN_HPP
#define METAL_LIST_CARTESIAN_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

#include <cstddef>

namespace metal {
    /// \cond
    namespace detail {
        template<std::size_t n>
        struct cartesianer;

        struct cartesianer_impl_0;
    }
    /// \endcond

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
    using cartesian = detail::call<
        detail::cartesianer<sizeof...(seqs)>::template type,
        detail::cartesianer_impl_0, seqs...>;
}

#include "../list/join.hpp"
#include "../list/list.hpp"

namespace metal {
    /// \cond
    namespace detail {
        struct cartesianer_impl_0 {
            template<typename... vals>
            using type = list<list<vals...>>;
        };

        template<typename next, typename seq>
        struct cartesianer_impl {};

        template<typename next, typename... vals>
        struct cartesianer_impl<next, list<vals...>> {
            template<template<typename...> class expr, typename... _>
            struct impl {
                using type = join<expr<vals, _...>...>;
            };

            template<typename... _>
            using type = typename impl<next::template type, _...>::type;
        };

        template<std::size_t n>
        struct cartesianer : cartesianer<(n > 0)> {};

        template<>
        struct cartesianer<1> {
            template<typename next, typename head, typename... tail>
            using type = call<
                cartesianer<sizeof...(tail)>::template type,
                cartesianer_impl<next, head>, tail...>;
        };

        template<>
        struct cartesianer<0> {
            template<typename next>
            using type = typename next::template type<>;
        };
    }
    /// \endcond
}

#endif
