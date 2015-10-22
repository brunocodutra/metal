// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_COMPOSE_HPP
#define METAL_LAMBDA_COMPOSE_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename... lbds>
    struct compose
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref compose.
    template<typename... lbds>
    using compose_t = typename metal::compose<lbds...>::type;
}

#include <metal/lambda/bind.hpp>

namespace metal
{
    template<typename head, typename... tail>
    struct compose<head, tail...> :
        bind<head, compose_t<tail...>>
    {};

    template<typename lbd>
    struct compose<lbd>
    {
        using type = lbd;
    };
}

#endif
