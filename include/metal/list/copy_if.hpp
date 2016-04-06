// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_COPY_IF_HPP
#define METAL_LIST_COPY_IF_HPP

namespace metal
{
    namespace detail
    {
        template<typename to, typename from, typename lbd>
        struct copy_if;
    }

    /// \ingroup list
    /// ...
    template<typename to, typename from, typename lbd>
    using copy_if = detail::copy_if<to, from, lbd>;

    /// \ingroup list
    /// Eager adaptor for metal::copy_if.
    template<typename to, typename from, typename lbd>
    using copy_if_t = typename metal::copy_if<to, from, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/optional/cond.hpp>

namespace metal
{
    namespace detail
    {
        template<typename to, typename from, typename lbd>
        struct copy_if
        {};

        template<
            typename to,
            template<typename...> class expr, typename... vals,
            typename lbd
        >
        struct copy_if<to, expr<vals...>, lbd> :
            invoke<
                copy<quote_t<to>, lift_t<lambda<join>>>,
                list<>, cond<invoke<lbd, vals>, list<vals>, list<>>...
            >
        {};
    }
}

#endif
