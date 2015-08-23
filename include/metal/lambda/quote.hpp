// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_QUOTE_HPP
#define METAL_LAMBDA_QUOTE_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename val>
    struct quote;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref quote.
    template<typename val>
    using quote_t = typename metal::quote<val>::type;

    template<typename val>
    struct quote
    {
        template<typename...>
        struct _
        {
            using type = val;
        };

        using type = _<>;
    };
}

#endif
