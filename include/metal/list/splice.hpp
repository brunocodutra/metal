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
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename n, typename other>
        struct splice :
            invoke<
                copy<_1, join<copy<_3, _1, _4, _5>, copy<_3, _2>, copy<_3, _1, _5>>>,
                list, other, metal::list<>, integer<0>, n
            >
        {};
    }
}

#endif
