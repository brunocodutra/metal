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
    /// Eager adaptor for \ref copy_if.
    template<typename to, typename from, typename lbd>
    using copy_if_t = typename metal::copy_if<to, from, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/empty.hpp>
#include <metal/list/copy.hpp>
#include <metal/list/apply.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename to, typename from, typename lbd,
            typename = boolean<true>
        >
        struct copy_if_impl :
            invoke<
                copy<_1, apply<quote_t<lambda<join>>, transform<_3, _2>>>,
                to, from, conditional<bind_t<lbd, _1>, list<_1>, list<>>
            >
        {};

        template<typename to, typename from, typename lbd>
        struct copy_if_impl<to, from, lbd, empty_t<from>> :
            copy<to, list<>>
        {};

        template<typename to, typename from, typename lbd>
        struct copy_if :
            copy_if_impl<to, from, lbd>
        {};
    }
}

#endif
