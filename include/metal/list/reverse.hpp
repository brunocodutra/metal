// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_REVERSE_HPP
#define METAL_LIST_REVERSE_HPP

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _reverse;
    }

    /// \ingroup list
    /// ...
    template<typename seq>
    using reverse = typename detail::_reverse<seq>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct _reverse_impl
        {};

        template<
            typename a, typename b, typename c, typename d,
            typename e, typename f, typename g, typename h,
            typename i, typename j, typename k, typename l,
            typename m, typename n, typename o, typename p, typename... tail
        >
        struct _reverse_impl<
            a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, tail...
        > :
            _join<
                typename _reverse_impl<tail...>::type,
                list<p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a>
            >
        {};

        template<typename head, typename... tail>
        struct _reverse_impl<head, tail...> :
            _join<typename _reverse_impl<tail...>::type, list<head>>
        {};

        template<>
        struct _reverse_impl<>
        {
            using type = list<>;
        };

        template<typename seq>
        struct _reverse
        {};

        template<typename... vals>
        struct _reverse<list<vals...>>:
            _reverse_impl<vals...>
        {};
    }
}

#endif
