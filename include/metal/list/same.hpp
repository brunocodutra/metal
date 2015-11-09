// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SAME_HPP
#define METAL_LIST_SAME_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list>
    struct same
    {};

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

        template<>
        struct same_impl<> :
            boolean<true>
        {};
    }

    template<template<typename...> class list, typename... vals>
    struct same<list<vals...>> :
        detail::same_impl<same<vals>...>
    {};
}

#endif
