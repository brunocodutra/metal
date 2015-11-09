// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_CORE_INHERIT_HPP
#define METAL_CORE_INHERIT_HPP

namespace metal
{
    /// \ingroup core
    /// ...
    template<typename... bases>
    struct inherit;
}

#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>

#include <cstddef>

namespace metal
{
    namespace detail
    {
        template<typename, typename base>
        struct inherit_second :
            base
        {};

        template<typename, typename...>
        struct inherit_impl;

        template<
            template<typename...> class list,
            typename... _,
            typename... bases
        >
        struct inherit_impl<list<_...>, bases...> :
            inherit_second<_, bases>...
        {};
    }

    template<typename... bases>
    struct inherit :
        detail::inherit_impl<
            enumerate_t<number<std::size_t, sizeof...(bases)>>,
            bases...
        >
    {};
}

#endif

