// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SAME_HPP
#define METAL_LIST_SAME_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct same;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using same = detail::same<list>;

    /// \ingroup list
    /// Eager adaptor for \ref same.
    template<typename list>
    using same_t = typename metal::same<list>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct same_impl :
            boolean<false>
        {};

        template<template<typename> class... _, typename val>
        struct same_impl<_<val>...> :
            boolean<true>
        {};

        template<typename list>
        struct same
        {};

        template<
            template<typename...> class expr,
            typename head, typename... tail
        >
        struct same<expr<head, tail...>> :
            same_impl<same<head>, same<tail>...>
        {};

        template<template<typename...> class expr, typename... vals>
        struct same<expr<vals...>> :
            boolean<true>
        {};
    }
}

#endif
