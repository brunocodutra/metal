// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_TRANSFORM_HPP
#define METAL_LIST_TRANSFORM_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct transform;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    using transform = detail::transform<list, lbd>;

    /// \ingroup list
    /// Eager adaptor for \ref transform.
    template<typename list, typename lbd>
    using transform_t = typename metal::transform<list, lbd>::type;
}

#include <metal/lambda/defer.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/lambda.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct transform
        {};

        template<
            template<typename...> class expr,
            typename... vals,
            typename lbd
        >
        struct transform<expr<vals...>, lbd> :
            invoke<lift_t<defer_t<lambda<expr>>>, invoke<lbd, vals>...>
        {};
    }
}

#endif
