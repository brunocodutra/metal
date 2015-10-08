// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_AND_HPP
#define METAL_NUMBER_LOGICAL_AND_HPP

namespace metal
{
    /// \ingroup logical
    /// \brief ...
    template<typename... nums>
    struct and_;

    /// \ingroup logical
    /// \brief Eager adaptor for \ref and_.
    template<typename... nums>
    using and_t = typename and_<nums...>::type;
}

#include <metal/number/number.hpp>
#include <metal/number/logical/or.hpp>
#include <metal/number/logical/not.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct and_impl :
            not_<or_t<not_t<nums>...>>
        {};
    }

    template<typename... nums>
    struct and_ :
        conditional<
            typename detail::and_impl<is_number_t<nums>...>::type,
            detail::and_impl<nums...>
        >
    {};

    template<typename tx, tx vx, typename ty, ty vy, typename... tail>
    struct and_<number<tx, vx>, number<ty, vy>, number<tail, true>...> :
        boolean<vx && vy>
    {};

    template<typename t, t v>
    struct and_<number<t, v>> :
        boolean<v && true>
    {};

    template<>
    struct and_<> :
        boolean<true>
    {};
}

#endif
