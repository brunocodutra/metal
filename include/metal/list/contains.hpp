// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_CONTAINS_HPP
#define METAL_LIST_CONTAINS_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename val>
        struct contains;
    }
    /// \ingroup list
    /// ...
    template<typename list, typename val>
    using contains = detail::contains<list, val>;

    /// \ingroup list
    /// Eager adaptor for metal::contains.
    template<typename list, typename val>
    using contains_t = typename metal::contains<list, val>::type;
}

#include <metal/number/number.hpp>
#include <metal/number/logical/or.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename list, typename val>
        struct contains
        {};

        template<
            template<typename...> class expr,
            typename... vals, typename val
        >
        struct contains<expr<vals...>, val> :
            or_<typename std::is_same<vals, val>::type...>
        {};
    }
}

#endif
