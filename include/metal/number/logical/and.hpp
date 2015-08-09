// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_AND_HPP
#define METAL_NUMBER_LOGICAL_AND_HPP

#include <metal/number/number.hpp>
#include <metal/number/logical/not.hpp>

namespace metal
{
    /// \ingroup logical
    /// \brief ...
    template<typename head, typename... tail>
    struct and_;

    /// \ingroup logical
    /// \brief Eager adaptor for \ref and_.
    template<typename head, typename... tail>
    using and_t = typename and_<head, tail...>::type;

    namespace detail
    {
        template<typename...>
        struct and_impl :
                boolean<false>
        {};

        template<typename... types>
        struct and_impl<number<types, true>...> :
                boolean<true>
        {};
    }

    template<typename head, typename... tail>
    struct and_ :
            detail::and_impl<not_t<not_t<head>>, not_t<not_t<tail>>...>
    {};
}

#endif
