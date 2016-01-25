// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REPLACE_IF_HPP
#define METAL_LIST_REPLACE_IF_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list, typename lbd, typename val>
    struct replace_if;

    /// \ingroup list
    /// Eager adaptor for \ref replace_if.
    template<typename list, typename lbd, typename val>
    using replace_if_t = typename metal::replace_if<list, lbd, val>::type;
}

#include <metal/list/list.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    template<typename list, typename lbd, typename val>
    struct replace_if :
        invoke<
            copy<_1, apply<_2, transform<_1, _3>>>,
            list,
            lambda<join>,
            conditional<
                bind_t<lbd, _1>,
                quote_t<metal::list<val>>,
                metal::list<_1>
            >
        >
    {};
}

#endif
