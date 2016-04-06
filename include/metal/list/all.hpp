// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ALL_HPP
#define METAL_LIST_ALL_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct all;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    using all = detail::all<list, lbd>;

    /// \ingroup list
    /// Eager adaptor for metal::all.
    template<typename list, typename lbd>
    using all_t = typename metal::all<list, lbd>::type;
}

#include <metal/number/logical/and.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct all
        {};

        template<
            template<typename...> class expr, typename... vals,
            typename lbd
        >
        struct all<expr<vals...>, lbd> :
            invoke<lift_t<lambda<and_>>, invoke<lbd, vals>...>
        {};
    }
}

#endif
