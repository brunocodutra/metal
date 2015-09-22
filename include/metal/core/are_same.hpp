// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_CORE_ARE_SAME_HPP
#define METAL_CORE_ARE_SAME_HPP

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
}

#include <metal/number/number.hpp>
#include <metal/number/logical/and.hpp>
#include <metal/optional/eval.hpp>

#include <type_traits>

namespace metal
{
    template<>
    struct are_same<> :
        boolean<true>
    {};

    template<typename val>
    struct are_same<val> :
        boolean<true>
    {};

    template<typename x, typename y>
    struct are_same<x, y> :
        std::is_same<x, y>
    {};

    template<typename head, typename... tail>
    struct are_same<head, tail...> :
        and_<eval<std::is_same<head, tail>>...>
    {};
}

#endif

