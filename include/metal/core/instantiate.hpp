// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_CORE_INSTANTIATE_HPP
#define METAL_CORE_INSTANTIATE_HPP

namespace metal
{
    /// \ingroup core
    /// ...
    template<template<typename...> class tmpl, typename... vals>
    struct instantiate;

    /// \ingroup core
    /// Eager adaptor for \ref instantiate.
    template<template<typename...> class tmpl, typename... vals>
    using instantiate_t = typename metal::instantiate<tmpl, vals...>::type;
}

#include <metal/list/list.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    namespace detail
    {
        template<
            template<typename...> class tmpl, typename... vals,
            typename ret = just<tmpl<vals...>>
        >
        ret instantiate_impl(list<vals...>*);

        template<template<typename...> class>
        nothing instantiate_impl(...);

        template<typename... vals>
        list<vals...>* forward();
    }

    template<template<typename...> class tmpl, typename... vals>
    struct instantiate :
        decltype(detail::instantiate_impl<tmpl>(detail::forward<vals...>()))
    {};
}

#endif

