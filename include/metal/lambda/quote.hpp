// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_QUOTE_HPP
#define METAL_LAMBDA_QUOTE_HPP

#include <metal/config.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _quote;
    }

    /// \ingroup lambda
    ///
    /// ### Description
    /// ...
    template<typename val>
    using quote = typename detail::_quote<val>::type;
}

#include <metal/lambda/lambda.hpp>

namespace metal
{
    namespace detail
    {
        template<typename val>
        struct _quote
        {
            template<typename...>
            using impl = val;

            using type = lambda<impl>;
        };
    }
}

#endif
