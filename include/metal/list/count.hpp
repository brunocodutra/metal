// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_COUNT_HPP
#define METAL_LIST_COUNT_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename val>
        struct count;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename val>
    using count = detail::count<list, val>;

    /// \ingroup list
    /// Eager adaptor for \ref count.
    template<typename list, typename val>
    using count_t = typename metal::count<list, val>::type;
}

#include <metal/list/count_if.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename list, typename val>
        struct count
        {};

        template<
            template<typename...> class expr,
            typename... vals, typename val
        >
        struct count<expr<vals...>, val> :
            add<
                number<std::ptrdiff_t, 0>,
                typename std::is_same<vals, val>::type...
            >
        {};
    }
}

#endif
