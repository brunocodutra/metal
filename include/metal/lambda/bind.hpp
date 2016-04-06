// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_BIND_HPP
#define METAL_LAMBDA_BIND_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... vals>
        struct bind;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd, typename... vals>
    using bind = detail::bind<lbd, vals...>;

    /// \ingroup lambda
    /// Eager adaptor for metal::bind.
    template<typename lbd, typename... vals>
    using bind_t = typename metal::bind<lbd, vals...>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/quote.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... args>
        struct bind
        {
            using type = invoke<quote_t<lbd>, args...>;
        };
    }
}

#endif
