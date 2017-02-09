// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_ARG_HPP
#define METAL_LAMBDA_ARG_HPP

#include <metal/config.hpp>

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>

#include <cstdint>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<std::uintmax_t n>
        struct arg_impl
        {
            template<typename... vals>
            using impl = at<list<vals...>, number<n - 1>>;

            using type = lambda<impl>;
        };

        template<>
        struct arg_impl<0U>
        {};
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// ...
    template<std::size_t n>
    using arg = typename detail::arg_impl<n>::type;

    /// \ingroup lambda
    ///
    /// ### Description
    /// Default placeholder.
    /// \{
    using _1 = metal::arg<1U>;
    using _2 = metal::arg<2U>;
    using _3 = metal::arg<3U>;
    using _4 = metal::arg<4U>;
    using _5 = metal::arg<5U>;
    using _6 = metal::arg<6U>;
    using _7 = metal::arg<7U>;
    using _8 = metal::arg<8U>;
    using _9 = metal::arg<9U>;
    /// \}
}

#endif
