// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_OR_HPP
#define METAL_NUMBER_LOGICAL_OR_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup logical
    /// \brief ...
    template<typename head, typename... tail>
    struct or_;

    /// \ingroup logical
    /// \brief Eager adaptor for \ref or_.
    template<typename head, typename... tail>
    using or_t = typename or_<head, tail...>::type;

    template<typename h, h hv, typename... t, t... tv>
    struct or_<number<h, hv>, number<t, tv>...> :
            boolean<true>
    {};

    template<typename h, typename... t>
    struct or_<number<h, false>, number<t, false>...> :
            boolean<false>
    {};
}

#endif
