// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_COUNT_IF_HPP
#define METAL_LIST_COUNT_IF_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct count_if;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    using count_if = detail::count_if<list, lbd>;

    /// \ingroup list
    /// Eager adaptor for metal::count_if.
    template<typename list, typename lbd>
    using count_if_t = typename metal::count_if<list, lbd>::type;
}

#include <metal/list/apply.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/add.hpp>

#include <cstddef>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct count_if :
            invoke<
                apply<_1, transform<_2, _3>>,
                partial_t<lambda<add>, number<std::ptrdiff_t, 0>>, lbd, list
            >
        {};
    }
}

#endif
