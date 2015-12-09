// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_AND_HPP
#define METAL_NUMBER_LOGICAL_AND_HPP

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct and_;
    }

    /// \ingroup logical
    /// ...
    template<typename... nums>
    using and_ = detail::and_<nums...>;

    /// \ingroup logical
    /// Eager adaptor for \ref and_.
    template<typename... nums>
    using and_t = typename metal::and_<nums...>::type;
}

#include <metal/number/number.hpp>
#include <metal/number/logical/not.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/list/list.hpp>
#include <metal/list/same.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        using nor = same_t<list<boolean<false>, nums...>>;

        template<typename... nums>
        struct and_ :
            invoke<lift_t<lambda<nor>>, not_<nums>...>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... tail>
        struct and_<number<tx, vx>, number<ty, vy>, number<tail, true>...> :
            boolean<vx && vy>
        {};

        template<typename tx, tx vx>
        struct and_<number<tx, vx>> :
            boolean<vx && true>
        {};

        template<>
        struct and_<> :
            boolean<true>
        {};
    }
}

#endif
