// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REMOVE_HPP
#define METAL_LIST_REMOVE_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename val>
        struct remove;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename val>
    using remove = detail::remove<list, val>;

    /// \ingroup list
    /// Eager adaptor for \ref remove.
    template<typename list, typename val>
    using remove_t = typename metal::remove<list, val>::type;
}

#include <metal/list/remove_if.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename list, typename val>
        struct remove :
            remove_if<list, std::is_same<_1, quote_t<val>>>
        {};
    }
}

#endif
