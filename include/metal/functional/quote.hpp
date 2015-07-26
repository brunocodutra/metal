// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_QUOTE_HPP
#define METAL_FUNCTIONAL_QUOTE_HPP

namespace metal
{
    /// \ingroup functional
    /// \brief ...
    template<typename value>
    struct quote;

    /// \ingroup functional
    /// \brief Eager adaptor for \ref quote.
    template<typename value>
    using quote_t = typename metal::quote<value>::type;

    template<typename value>
    struct quote
    {
        template<typename...>
        struct _
        {
            using type = value;
        };

        using type = _<>;
    };
}

#endif
