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
    /// Eager adaptor for \ref replace_if.
    template<typename list, typename lbd, typename val>
    using replace_if_t = typename metal::replace_if<list, lbd, val>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd, typename val>
        struct replace_if
        {};

        template<
            template<typename...> class expr, typename... vals,
            typename lbd, typename val
        >
        struct replace_if<expr<vals...>, lbd, val> :
            invoke<
                copy<quote_t<expr<vals...>>, lift_t<lambda<join>>>,
                list<>, conditional<invoke<lbd, vals>, list<val>, list<vals>>...
            >
        {};
    }
}

#endif
