// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ENUMERATE_HPP
#define METAL_NUMBER_ENUMERATE_HPP

namespace metal
{
    /// \ingroup number
    /// \brief ...
    template<typename...>
    struct enumerate;

    /// \ingroup number
    /// \brief Eager adaptor for \ref enumerate.
    template<typename... args>
    using enumerate_t = typename metal::enumerate<args...>::type;
}

#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/list/join.hpp>

namespace metal
{
    namespace detail
    {
        template<typename t, t... vs>
        struct numbers :
            list<number<t, vs>...>
        {};

        template<typename, typename, typename>
        struct affine;

        template<
            template<typename...> class list, typename t, t... ns,
            typename u, u a,
            typename v, v b>
        struct affine<list<number<t, ns>...>, number<u, a>, number<v, b>> :
            numbers<v, static_cast<v>(b + a*ns)...>
        {};
    }

    template<typename t, t start, typename u, u size, typename v, v stride>
    struct enumerate<number<t, start>, number<u, size>, number<v, stride>> :
        detail::affine<
            enumerate_t<number<u, size>>,
            number<v, stride>,
            number<t, start>
        >
    {};

    template<typename t, t start, typename u, u size>
    struct enumerate<number<t, start>, number<u, size>> :
        enumerate<number<t, start>, number<u, size>, integer<1>>
    {};

    template<typename t, t size>
    struct enumerate<number<t, size>> :
        join<
            enumerate_t<number<t, size/2>>,
            enumerate_t<number<t, size/2>, number<t, size - size/2>>
        >
    {};

    template<typename t>
    struct enumerate<number<t, t(1)>> :
        list<number<t, 0>>
    {};

    template<typename t>
    struct enumerate<number<t, t(-1)>> :
        list<number<t, 0>>
    {};

    template<typename t>
    struct enumerate<number<t, t(0)>> :
        list<>
    {};
}

#endif
