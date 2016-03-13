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
    /// Eager adaptor for \ref count_if.
    template<typename list, typename lbd>
    using count_if_t = typename metal::count_if<list, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/reduce.hpp>
#include <metal/list/flatten.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/add.hpp>
#include <metal/optional/conditional.hpp>

#include <cstddef>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct count_if
        {};

        template<
            template<typename...> class expr,
            typename... vals, typename lbd
        >
        struct count_if<expr<vals...>, lbd> :
            invoke<
                lift_t<lambda<add>>,
                number<std::ptrdiff_t, 0>, invoke<lbd, vals>...
            >
        {};
    }
}

#endif
