// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_PARTIAL_HPP
#define METAL_LAMBDA_PARTIAL_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename lbd, typename... args>
    struct partial;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref partial.
    template<typename lbd, typename... args>
    using partial_t = typename metal::partial<lbd, args...>::type;
}

#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

namespace metal
{
    template<typename lbd, typename... args>
    struct partial
    {
        template<typename... _>
        using call = invoke<lbd, args..., _...>;

        using type = lambda<call>;
    };
}

#endif
