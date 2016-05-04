// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REPLACE_IF_HPP
#define METAL_LIST_REPLACE_IF_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd, typename val>
        struct replace_if;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd, typename val>
    using replace_if = detail::replace_if<list, lbd, val>;

    /// \ingroup list
    /// Eager adaptor for metal::replace_if.
    template<typename list, typename lbd, typename val>
    using replace_if_t = typename metal::replace_if<list, lbd, val>::type;
}

#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/logical/if.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd, typename val>
        struct replace_if :
            transform<if_<lbd, quote_t<val>, _1>, list>
        {};
    }
}

#endif
