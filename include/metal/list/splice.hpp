// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SPLICE_HPP
#define METAL_LIST_SPLICE_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list, typename n, typename other>
    struct splice;

    /// \ingroup list
    /// Eager adaptor for \ref splice.
    template<typename list, typename n, typename other>
    using splice_t = typename metal::splice<list, n, other>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/quote.hpp>

namespace metal
{
    template<typename list, typename n, typename other>
    struct splice :
        invoke<
            lift_t<copy<quote_t<list>, join<_1, _2, _3>>>,
            copy<metal::list<>, list, integer<0>, n>,
            copy<metal::list<>, other>,
            copy<metal::list<>, list, n>
        >
    {};
}

#endif
