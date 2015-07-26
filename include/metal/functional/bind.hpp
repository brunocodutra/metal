// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_BIND_HPP
#define METAL_FUNCTIONAL_BIND_HPP

#include <metal/functional/apply.hpp>

namespace metal
{
    /// \ingroup functional
    /// \brief ...
    template<typename lambda, typename... args>
    struct bind;

    /// \ingroup functional
    /// \brief Eager adaptor for \ref bind.
    template<typename lambda, typename... args>
    using bind_t = typename bind<lambda, args...>::type;

    template<typename lambda, typename... args>
    struct bind
    {
        using type = apply<lambda, args...>;
    };

}

#endif
