// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_COPY_IF_HPP
#define METAL_LIST_COPY_IF_HPP

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename lbd>
    using copy_if = apply<
        partial<lambda<join>, list<>>,
        transform<bind<lambda<if_>, lbd, lambda<list>, quote<list<>>>, seq>
    >;
}

#endif
