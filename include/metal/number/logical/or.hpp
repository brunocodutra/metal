// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_OR_HPP
#define METAL_NUMBER_LOGICAL_OR_HPP

#include <metal/number/number.hpp>
#include <metal/number/logical/not.hpp>

namespace metal
{
    /// \ingroup logical
    /// \brief ...
    template<typename head, typename... tail>
    struct or_;

    /// \ingroup logical
    /// \brief Eager adaptor for \ref or_.
    template<typename head, typename... tail>
    using or_t = typename or_<head, tail...>::type;

    namespace detail
    {
        template<typename...>
        struct or_impl :
                boolean<true>
        {};

        template<typename... types>
        struct or_impl<number<types, false>...> :
                boolean<false>
        {};
    }

    template<typename head, typename... tail>
    struct or_ :
            detail::or_impl<not_t<not_t<head>>, not_t<not_t<tail>>...>
    {};
}

#endif
