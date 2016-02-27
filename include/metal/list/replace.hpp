// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REPLACE_HPP
#define METAL_LIST_REPLACE_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename from, typename to>
        struct replace;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename from, typename to>
    using replace = detail::replace<list, from, to>;

    /// \ingroup list
    /// Eager adaptor for \ref replace.
    template<typename list, typename from, typename to>
    using replace_t = typename metal::replace<list, from, to>::type;
}

#include <metal/list/replace_if.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename list, typename from, typename to>
        struct replace :
            replace_if<list, std::is_same<_1, quote_t<from>>, to>
        {};
    }
}

#endif
