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
        template<typename, typename, typename = nil, typename = nil>
        struct copy;
    }

    /// \ingroup list
    /// ...
    template<
        typename to,
        typename from,
        typename begin = detail::nil,
        typename end = detail::nil
    >
    using copy = detail::copy<to, from, begin, end>;

    /// \ingroup list
    /// Eager adaptor for \ref copy.
    template<
        typename to,
        typename from,
        typename begin = detail::nil,
        typename end = detail::nil
    >
    using copy_t = typename metal::copy<to, from, begin, end>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/defer.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/slice.hpp>
#include <metal/list/size.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename, typename, typename, typename,
            typename = boolean<true>
        >
        struct copy_impl
        {};

        template<
            typename to,
            template<typename...> class from, typename... vals,
            typename begin, begin b, typename end, end e
        >
        struct copy_impl<
            to, from<vals...>, number<begin, b>, number<end, e>,
            boolean<(0 <= b && b < e && e <= sizeof...(vals))>
        > :
            copy<
                to,
                slice_t<
                    list<vals...>,
                    number<begin, b>,
                    number<decltype(e - b), e - b>
                >
            >
        {};

        template<
            typename to,
            template<typename...> class from, typename... vals,
            typename begin, begin b, typename end, end e
        >
        struct copy_impl<
            to, from<vals...>, number<begin, b>, number<end, e>,
            boolean<(0 <= e && e < b && b <= sizeof...(vals))>
        > :
            copy<
                to,
                slice_t<
                    list<vals...>,
                    number<begin, b - 1>,
                    number<decltype(e - b), b - e>,
                    integer<-1>
                >
            >
        {};

        template<typename to, typename from, typename begin, typename end>
        struct copy :
            copy_impl<to, from, begin, end>
        {};

        template<
            typename to,
            template<typename...> class from, typename... vals,
            typename begin, begin b, typename end
        >
        struct copy<to, from<vals...>, number<begin, b>, number<end, end(b)>> :
            copy<to, list<>>
        {};

        template<
            typename to,
            template<typename...> class from, typename... vals,
            typename begin, begin b
        >
        struct copy<to, from<vals...>, number<begin, b>> :
            copy<to, from<vals...>, number<begin, b>, size_t<from<vals...>>>
        {};

        template<
            typename to,
            template<typename...> class from, typename... vals,
            typename begin
        >
        struct copy<to, from<vals...>, number<begin, begin(0)>> :
            copy<to, from<vals...>>
        {};

        template<
            template<typename...> class to, typename... ts,
            template<typename...> class from, typename... fs
        >
        struct copy<to<ts...>, from<fs...>> :
            invoke<defer_t<lambda<to>>, fs...>
        {};

        template<
            template<typename...> class expr,
            typename... ts, typename... fs
        >
        struct copy<expr<ts...>, expr<fs...>>
        {
            using type = expr<fs...>;
        };
    }
}

#endif
