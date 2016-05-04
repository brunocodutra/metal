// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ANY_HPP
#define METAL_LIST_ANY_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct any;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    using any = detail::any<list, lbd>;

    /// \ingroup list
    /// Eager adaptor for metal::any.
    template<typename list, typename lbd>
    using any_t = typename metal::any<list, lbd>::type;
}

#include <metal/list/apply.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/logical/or.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct any :
            invoke<apply<_1, transform<_3, _2>>, lambda<or_>, list, lbd>
        {};
    }
}


#endif
