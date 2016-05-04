// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ERASE_HPP
#define METAL_LIST_ERASE_HPP

#include <metal/detail/nil.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename = nil>
        struct erase;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename beg, typename end = detail::nil>
    using erase = detail::erase<list, beg, end>;

    /// \ingroup list
    /// Eager adaptor for metal::erase.
    template<typename list, typename beg, typename end = detail::nil>
    using erase_t = typename metal::erase<list, beg, end>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename beg, typename end>
        struct erase
        {};

        template<typename list, typename t, t beg, t end>
        struct erase<list, number<t, beg>, number<t, end>> :
            invoke<
                copy<_1, join<copy<_2, _1, _3, _4>, copy<_2, _1, _5>>>,
                list,
                metal::list<>,
                integer<0>,
                number<t, (beg < end) ? beg : end>,
                number<t, (beg < end) ? end : beg>
            >
        {};

        template<typename list, typename beg, beg b, typename end, end e>
        struct erase<list, number<beg, b>, number<end, e>> :
            erase<list, number<decltype(b + e), b>, number<decltype(b + e), e>>
        {};

        template<typename list, typename beg, beg b>
        struct erase<list, number<beg, b>> :
            erase<list, number<beg, b>, number<beg, b + 1>>
        {};
    }
}

#endif
