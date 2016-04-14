// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SORT_HPP
#define METAL_LIST_SORT_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct sort;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    using sort = detail::sort<list, lbd>;

    /// \ingroup list
    /// Eager adaptor for metal::sort.
    template<typename list, typename lbd>
    using sort_t = typename metal::sort<list, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/copy.hpp>
#include <metal/list/merge.hpp>
#include <metal/list/reduce.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/quote.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct sort
        {};

        template<typename... vals, typename lbd>
        struct sort<list<vals...>, lbd> :
            reduce<list<list<vals>...>, merge<quote_t<lbd>, _1, _2>>
        {};

        template<typename lbd>
        struct sort<list<>, lbd> :
            list<>
        {};

        template<
            template<typename...> class expr,
            typename... vals, typename lbd
        >
        struct sort<expr<vals...>, lbd> :
            invoke<
                copy<_1, sort<_2, _3>>,
                expr<vals...>, list<vals...>, lbd
            >
        {};
    }
}

#endif
