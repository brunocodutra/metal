// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ANY_HPP
#define METAL_LIST_ANY_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct any;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    using any = detail::any<list, lbd>;

    /// \ingroup list
    /// Eager adaptor for \ref any.
    template<typename list, typename lbd>
    using any_t = typename metal::any<list, lbd>::type;
}

#include <metal/number/logical/or.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct any
        {};

        template<
            template<typename...> class expr, typename... vals,
            typename lbd
        >
        struct any<expr<vals...>, lbd> :
            invoke<lift_t<lambda<or_>>, invoke<lbd, vals>...>
        {};
    }
}

#endif
