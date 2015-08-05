// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_BIND_HPP
#define METAL_LAMBDA_BIND_HPP

#include <metal/lambda/apply.hpp>
#include <metal/lambda/quote.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename lambda, typename... args>
    struct bind;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref bind.
    template<typename lambda, typename... args>
    using bind_t = typename metal::bind<lambda, args...>::type;

    template<typename lambda, typename... args>
    struct bind
    {
        using type = apply<metal::quote_t<lambda>, args...>;
    };
}

#endif
