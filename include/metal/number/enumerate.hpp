// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ENUMERATE_HPP
#define METAL_NUMBER_ENUMERATE_HPP

#include <metal/number/number.hpp>
#include <metal/list/list.hpp>

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

    namespace detail
    {
        template<typename t, t... vs>
        struct numbers :
                list<number<t, vs>...>
        {};

        template<typename, typename, typename, typename>
        struct merge;

        template<
            template<typename...> class list, typename t,
            t ox, t... xs, t oy, t... ys
        >
        struct merge<
            number<t, ox>, list<number<t, xs>...>,
            number<t, oy>, list<number<t, ys>...>
        > :
                numbers<t, (ox + xs)..., (oy + ys)...>
        {};
    }

    template<typename f, f fv, typename l, l lv>
    struct enumerate<number<f, fv>, number<l, lv>> :
            enumerate<
                number<decltype(true ? fv : lv), fv>,
                number<decltype(true ? fv : lv), lv>
            >
    {};

    template<typename t, t f, t l>
    struct enumerate<number<t, f>, number<t, l>> :
            detail::merge<
                number<t, f>,
                enumerate_t<number<t, (l - f)/2>>,
                number<t, f + (l - f)/2>,
                enumerate_t<number<t, l - f - (l - f)/2>>
            >
    {};

    template<typename t, t f>
    struct enumerate<number<t, f>, number<t, f + 1>> :
            list<number<t, f>>
    {};

    template<typename t, t f>
    struct enumerate<number<t, f>, number<t, f - 1>> :
            list<number<t, f>>
    {};

    template<typename t, t f>
    struct enumerate<number<t, f>, number<t, f>> :
            list<>
    {};

    template<typename t, t v>
    struct enumerate<number<t, v>> :
            enumerate<number<t, 0>, number<t, v>>
    {};
}

#endif
