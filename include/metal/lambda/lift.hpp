// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_LIFT_HPP
#define METAL_LAMBDA_LIFT_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename lbd>
    struct lift;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref lift.
    template<typename lbd>
    using lift_t = typename metal::lift<lbd>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/eval.hpp>

namespace metal
{
    template<typename lbd>
    struct lift
    {
        template<typename... args>
        using _ = invoke<lbd, eval<args>...>;

        using type = lambda<_>;
    };
}

#endif
