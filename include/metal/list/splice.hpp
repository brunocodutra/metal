// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SPLICE_HPP
#define METAL_LIST_SPLICE_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename n, typename other>
        struct splice;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename n, typename other>
    using splice = detail::splice<list, n, other>;

    /// \ingroup list
    /// Eager adaptor for metal::splice.
    template<typename list, typename n, typename other>
    using splice_t = typename metal::splice<list, n, other>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/quote.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename n, typename other>
        struct splice :
            invoke<
                copy<quote_t<list>, lift_t<lambda<join>>>,
                copy<metal::list<>, list, integer<0>, n>,
                copy<metal::list<>, other>,
                copy<metal::list<>, list, n>
            >
        {};
    }
}

#endif
