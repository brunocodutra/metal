// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_IF_HPP
#define METAL_NUMBER_LOGICAL_IF_HPP

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct if_;
    }

    /// \ingroup number
    /// ...
    ///
    template<typename cond, typename then_, typename... else_>
    using if_ = detail::if_<cond, then_, else_...>;

    /// \ingroup number
    /// Eager adaptor for metal::if_.
    template<typename cond, typename then_, typename... else_>
    using if_t = typename metal::if_<cond, then_, else_...>::type;
}


#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct if_
        {};

        template<typename t, typename then_, typename... else_>
        struct if_<number<t, static_cast<t>(0)>, then_, else_...> :
            if_<else_...>
        {};

        template<typename t, typename then_, typename else_>
        struct if_<number<t, static_cast<t>(0)>, then_, else_>
        {
            using type = else_;
        };

        template<typename t, t v, typename then_, typename... else_>
        struct if_<number<t, v>, then_, else_...>
        {
            using type = then_;
        };
    }
}

#endif
