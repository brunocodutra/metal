// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_CORE_ARE_SAME_HPP
#define METAL_CORE_ARE_SAME_HPP

#include <metal/number/number.hpp>
#include <metal/number/logical/and.hpp>

namespace metal
{
    /// \ingroup core
    /// \brief ...
    template<typename... vals>
    struct are_same
    {};

    /// \ingroup core
    /// \brief Eager adaptor for \ref are_same.
    template<typename... vals>
    using are_same_t = typename metal::are_same<vals...>::type;

    template<>
    struct are_same<> :
        boolean<true>
    {};

    template<typename val>
    struct are_same<val> :
        boolean<true>
    {};

    template<typename val>
    struct are_same<val, val> :
        boolean<true>
    {};

    template<typename x, typename y>
    struct are_same<x, y> :
        boolean<false>
    {};

    template<typename head, typename... tail>
    struct are_same<head, tail...> :
        and_<are_same_t<head, tail>...>
    {};
}

#endif

