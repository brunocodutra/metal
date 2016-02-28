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
    template<typename list, typename begin, typename end = detail::nil>
    using erase = detail::erase<list, begin, end>;

    /// \ingroup list
    /// Eager adaptor for \ref erase.
    template<typename list, typename begin, typename end = detail::nil>
    using erase_t = typename metal::erase<list, begin, end>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/inc.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename = boolean<true>>
        struct erase_impl
        {};

        template<
            template<typename...> class expr, typename... vals,
            typename begin, begin b, typename end, end e
        >
        struct erase_impl<
            expr<vals...>, number<begin, b>, number<end, e>,
            boolean<(0 <= b && b < e && e <= sizeof...(vals))>
        > :
            copy<
                expr<vals...>,
                join_t<
                    copy_t<
                        list<>, expr<vals...>,
                        integer<0>, number<begin, b>
                    >,
                    copy_t<
                        list<>, expr<vals...>,
                        number<end, e>, size_t<expr<vals...>>
                    >
                >
            >
        {};

        template<typename list, typename begin, begin b, typename end, end e>
        struct erase_impl<
            list, number<begin, b>, number<end, e>,
            boolean<(e < b)>
        > :
            erase_impl<list, number<end, e>, number<begin, b>>
        {};

        template<typename list, typename begin, typename end>
        struct erase :
            erase_impl<list, begin, end>
        {};

        template<typename list, typename begin, begin b, typename end>
        struct erase<list, number<begin, b>, number<end, end(b)>>
        {
            using type = list;
        };

        template<typename list, typename begin, begin b>
        struct erase<list, number<begin, b>> :
            erase<list, number<begin, b>, inc_t<number<begin, b>>>
        {};
    }
}

#endif
