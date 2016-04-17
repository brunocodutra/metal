// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_IF_HPP
#define METAL_NUMBER_LOGICAL_IF_HPP

namespace metal
{
    namespace detail
    {
        template<typename cond, typename true_, typename false_>
        struct if_;
    }

    /// \ingroup number
    /// ...
    ///
    template<typename cond, typename true_, typename false_>
    using if_ = detail::if_<cond, true_, false_>;

    /// \ingroup number
    /// Eager adaptor for metal::if_.
    template<typename cond, typename true_, typename false_>
    using if_t = typename metal::if_<cond, true_, false_>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename>
        struct if_
        {};

        template<typename t, t v, typename true_, typename false_>
        struct if_<number<t, v>, true_, false_>
        {
            using type = true_;
        };

        template<typename t, typename true_, typename false_>
        struct if_<number<t, static_cast<t>(0)>, true_, false_>
        {
            using type = false_;
        };
    }
}

#endif
