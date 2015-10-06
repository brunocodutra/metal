// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_ARG_HPP
#define METAL_LAMBDA_ARG_HPP

#include <cstddef>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<std::size_t n, typename...>
    struct arg;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref arg.
    template<std::size_t n, typename... args>
    using arg_t = typename metal::arg<n, args...>::type;

    /// \defgroup placeholders Placeholders
    /// \ingroup lambda
    /// \brief Default placeholders for arguments to \lambdas.

    /// \ingroup placeholders
    /// \brief Default placeholder.
    /// \{
    using _1  = metal::arg<1U>;
    using _2  = metal::arg<2U>;
    using _3  = metal::arg<3U>;
    using _4  = metal::arg<4U>;
    using _5  = metal::arg<5U>;
    using _6  = metal::arg<6U>;
    using _7  = metal::arg<7U>;
    using _8  = metal::arg<8U>;
    using _9  = metal::arg<9U>;
    using _10 = metal::arg<10U>;
    /// \}
}

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    template<std::size_t n, typename... args>
    struct arg :
        at<list<arg<n>, args...>, number<std::size_t, n>>
    {};

    template<typename x, typename y, typename z, typename... tail>
    struct arg<3U, x, y, z, tail...>
    {
        using type = z;
    };

    template<typename x, typename y, typename... tail>
    struct arg<2U, x, y, tail...>
    {
        using type = y;
    };

    template<typename x, typename... tail>
    struct arg<1U, x, tail...>
    {
        using type = x;
    };

    template<typename... args>
    struct arg<0U, args...>
    {};

    template<std::size_t n>
    struct arg<n>
    {};
}

#endif
