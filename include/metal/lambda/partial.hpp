// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_PARTIAL_HPP
#define METAL_LAMBDA_PARTIAL_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... args>
        struct partial;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd, typename... args>
    using partial = detail::partial<lbd, args...>;

    /// \ingroup lambda
    /// Eager adaptor for metal::partial.
    template<typename lbd, typename... args>
    using partial_t = typename metal::partial<lbd, args...>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... leading>
        struct partial
        {
            template<typename... trailing>
            using _ = invoke<lbd, leading..., trailing...>;

            using type = lambda<_>;
        };
    }
}

#endif
