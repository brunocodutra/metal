// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_RANGE_HPP
#define METAL_LIST_RANGE_HPP

#include <metal/config.hpp>

#include <metal/list/size.hpp>
#include <metal/number/if.hpp>
#include <metal/number/max.hpp>
#include <metal/number/min.hpp>
#include <metal/number/number.hpp>
#include <metal/value/same.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq, typename beg, typename end>
        struct _range;

        template<typename seq, typename beg, typename end>
        using range = typename detail::_range<seq, beg, end>::type;
    }

    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq, typename beg, typename end>
    using range = detail::range<
        seq,
        if_<same<min<max<number<0>, beg>, size<seq>>, beg>, beg>,
        if_<same<min<max<number<0>, end>, size<seq>>, end>, end>
    >;
}

#include <metal/list/list.hpp>
#include <metal/list/rotate.hpp>
#include <metal/list/reverse.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/number/sub.hpp>
#include <metal/value/value.hpp>

#include <metal/detail/declptr.hpp>

namespace metal
{
    namespace detail
    {
        template<typename> using void_ = void;

        template<typename, typename>
        struct _skip
        {};

        template<typename seq, typename _>
        using skip = typename _skip<seq, _>::type;

        template<typename... vals, typename... _>
        struct _skip<list<vals...>, list<_...>>
        {
            template<typename... tail>
            static list<tail...> impl(void_<_>*..., value<tail>*...);

            using type = decltype(impl(declptr<value<vals>>()...));
        };

        template<typename seq, typename beg, typename end>
        struct _range
        {
            using type = range<
                range<
                    range<seq, min<beg, end>, size<seq>>,
                    number<0>,
                    sub<max<beg, end>, min<beg, end>>
                >,
                sub<beg, min<beg, end>>,
                sub<end, min<beg, end>>
            >;
        };

        template<typename seq, typename n>
        struct _range<seq, number<0>, n>
        {
            using type =
                skip<rotate<seq, n>, enumerate<number<0>, sub<size<seq>, n>>>;
        };

        template<typename seq, typename n>
        struct _range<seq, n, size<seq>>
        {
            using type = skip<seq, enumerate<number<0>, n>>;
        };

        template<typename seq>
        struct _range<seq, number<0>, size<seq>>
        {
            using type = seq;
        };

        template<typename seq>
        struct _range<seq, size<seq>, number<0>>
        {
            using type = reverse<seq>;
        };

        template<>
        struct _range<list<>, number<0>, number<0>>
        {
            using type = list<>;
        };
    }
}

#endif
