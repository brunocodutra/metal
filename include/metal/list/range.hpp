// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_RANGE_HPP
#define METAL_LIST_RANGE_HPP

#include <metal/list/size.hpp>
#include <metal/number/if.hpp>
#include <metal/number/or.hpp>
#include <metal/number/not.hpp>
#include <metal/number/number.hpp>
#include <metal/number/greater.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq, typename beg, typename end>
        struct _range;
    }

    /// \ingroup list
    /// ...
    template<typename seq, typename beg, typename end>
    using range = typename detail::_range<
        seq,
        if_<not_<or_<greater<number<0>, beg>, greater<beg, size<seq>>>>, beg>,
        if_<not_<or_<greater<number<0>, end>, greater<end, size<seq>>>>, end>
    >::type;
}

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>
#include <metal/list/reverse.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/value/value.hpp>

#include <metal/detail/declptr.hpp>

namespace metal
{
    namespace detail
    {
        template<typename> using void_ = void;

        template<typename, typename>
        struct _drop_impl
        {};

        template<typename... vals, typename... _>
        struct _drop_impl<list<vals...>, list<_...>>
        {
            template<typename... vals_>
            static list<vals_...> impl(void_<_>*..., value<vals_>*...);

            using type = decltype(impl(declptr<value<vals>>()...));
        };

        template<typename seq, typename n>
        struct _drop :
            _drop_impl<seq, enumerate<number<0>, n>>
        {};

        template<typename seq, typename n>
        using drop = typename _drop<seq, n>::type;

        template<typename, typename>
        struct _take_impl
        {};

        template<typename... vals, typename... _>
        struct _take_impl<list<vals...>, list<_...>> :
            _join<if_<_, list<vals>, list<>>...>
        {};

        template<typename seq, typename n>
        struct _take
        {};

        template<typename... vals, int_ n>
        struct _take<list<vals...>, number<n>> :
            _take_impl<
                list<vals...>,
                join<
                    enumerate<number<1>, number<n>, number<0>>,
                    enumerate<number<0>, number<sizeof...(vals) - n>, number<0>>
                >
            >
        {};

        template<typename seq, typename n>
        using take = typename _take<seq, n>::type;

        template<typename seq, typename beg, typename end, typename = true_>
        struct _range_impl
        {
            using type = list<>;
        };

        template<typename seq, int_ b, int_ e>
        struct _range_impl<seq, number<b>, number<e>,
            number<(e > b)>
        >
        {
            using type = take<drop<seq, number<b>>, number<e - b>>;
        };

        template<typename seq, int_ b, int_ e>
        struct _range_impl<seq, number<b>, number<e>,
            number<(e < b)>
        >
        {
            using type = reverse<take<drop<seq, number<e>>, number<b - e>>>;
        };

        template<typename seq, typename beg, typename end>
        struct _range :
            _range_impl<seq, beg, end>
        {};
    }
}

#endif
