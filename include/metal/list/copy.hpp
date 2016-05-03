// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_COPY_HPP
#define METAL_LIST_COPY_HPP

#include <metal/detail/nil.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename, typename, typename = nil, typename = nil,
            typename = void
        >
        struct copy;
    }

    /// \ingroup list
    /// ...
    template<
        typename to,
        typename from,
        typename beg = detail::nil,
        typename end = detail::nil
    >
    using copy = detail::copy<to, from, beg, end>;

    /// \ingroup list
    /// Eager adaptor for metal::copy.
    template<
        typename to,
        typename from,
        typename beg = detail::nil,
        typename end = detail::nil
    >
    using copy_t = typename metal::copy<to, from, beg, end>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/slice.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include <metal/detail/void.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename to, typename from, typename beg, typename end,
            typename = boolean<true>
        >
        struct copy_impl
        {};

        template<
            typename to, typename from,
            typename beg, beg b, typename end, end e
        >
        struct copy_impl<to, from, number<beg, b>, number<end, e>,
            boolean<(0 <= b && b < e && e <= size_t<from>::value)>
        > :
            invoke<
                copy<_1, slice<copy<list<>, _2>, _3, _4>>,
                to, from, number<std::size_t, b>, number<std::size_t, e - b>
            >
        {};

        template<
            typename to, typename from,
            typename beg, beg b, typename end, end e
        >
        struct copy_impl<to, from, number<beg, b>, number<end, e>,
            boolean<(0 <= e && e < b && b <= size_t<from>::value)>
        > :
            invoke<
                copy<_1, slice<copy<list<>, _2>, _3, _4, _5>>,
                to,
                from,
                number<std::size_t, b - 1>,
                number<std::size_t, b - e>,
                integer<-1>
            >
        {};

        template<
            typename to, typename from,
            typename beg, beg b, typename end, end e
        >
        struct copy_impl<to, from, number<beg, b>, number<end, e>,
            boolean<(0 <= e && e == b && b <= size_t<from>::value)>
        > :
            copy<to, list<>>
        {};

        template<
            typename to, typename from, typename beg, typename end,
            typename
        >
        struct copy :
            copy_impl<to, from, beg, end>
        {};

        template<typename to, typename from, typename beg, typename end>
        struct copy<
            to, from,
            number<beg, static_cast<beg>(0)>,
            number<end, size_t<from>::value>
        > :
            copy<to, from>
        {};

        template<typename to, typename from, typename beg, beg b>
        struct copy<to, from, number<beg, b>, nil,
            void_t<size_t<from>>
        > :
            copy<to, from, number<std::size_t, b>, size_t<from>>
        {};

        template<
            template<typename...> class to, typename... ts,
            template<typename...> class from, typename... fs
        >
        struct copy<to<ts...>, from<fs...>, nil, nil,
            void_t<to<fs...>>
        >
        {
            using type = to<fs...>;
        };
    }
}

#endif
