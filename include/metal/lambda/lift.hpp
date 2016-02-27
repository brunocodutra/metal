// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_LIFT_HPP
#define METAL_LAMBDA_LIFT_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd>
        struct lift;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd>
    using lift = detail::lift<lbd>;

    /// \ingroup lambda
    /// Eager adaptor for \ref lift.
    template<typename lbd>
    using lift_t = typename metal::lift<lbd>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd>
        struct lift
        {
            template<typename... args>
            using _ = invoke<lbd, typename optional<args>::type...>;

            using type = lambda<_>;
        };
    }
}

#endif
