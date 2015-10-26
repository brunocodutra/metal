// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SPLICE_HPP
#define METAL_LIST_SPLICE_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename n, typename other>
    struct splice;

    /// \ingroup list
    /// \brief Eager adaptor for \ref splice.
    template<typename list, typename n, typename other>
    using splice_t = typename metal::splice<list, n, other>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/quote.hpp>

namespace metal
{
    template<typename list, typename n, typename other>
    struct splice :
        invoke<
            copy<
                quote_t<list>,
                join<
                    copy<metal::list<>, quote_t<list>, integer<0>, quote_t<n>>,
                    quote_t<other>,
                    copy<metal::list<>, quote_t<list>, quote_t<n>>
                >
            >
        >
    {};
}

#endif
