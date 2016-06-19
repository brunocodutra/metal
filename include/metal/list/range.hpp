// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_RANGE_HPP
#define METAL_LIST_RANGE_HPP

#include <metal/list/size.hpp>
#include <metal/number/if.hpp>
#include <metal/number/not.hpp>
#include <metal/number/less.hpp>
#include <metal/number/cast.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq, typename beg, typename end, typename = true_>
        struct _range;
    }

    /// \ingroup list
    /// ...
    template<typename seq, typename beg, typename end>
    using range = typename detail::_range<
        seq,
        if_<not_<less<size<seq>, beg>>, cast<beg, std::size_t>>,
        if_<not_<less<size<seq>, end>>, cast<end, std::size_t>>
    >::type;
}

#include <metal/list/list.hpp>
#include <metal/list/slice.hpp>
#include <metal/number/dec.hpp>
#include <metal/number/sub.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/value/value.hpp>

#include <metal/detail/declptr.hpp>

#include <cstddef>

namespace metal
{
    namespace detail
    {
        template<typename> using void_ = void;

        template<typename, typename>
        struct _drop
        {};

        template<typename... _, typename... vals>
        struct _drop<list<_...>, list<vals...>>
        {
            template<typename... vs>
            static list<vs...> impl(void_<_>*..., value<vs>*...);

            using type = decltype(impl(declptr<value<vals>>()...));
        };

        template<typename seq, typename beg, typename end, typename>
        struct _range
        {
            using type = slice<seq, beg, sub<end, beg>>;
        };

        template<typename seq, typename beg, typename end>
        struct _range<seq, beg, end,
            less<end, beg>
        >
        {
            using type = slice<seq, dec<beg>, sub<beg, end>, int_<-1>>;
        };

        template<typename seq, std::size_t beg>
        struct _range<seq, size_t<beg>, size<seq>>
        {
            using type =
                typename _drop<enumerate<size_t<0>, size_t<beg>>, seq>::type;
        };

        template<typename seq>
        struct _range<seq, size_t<0>, size<seq>>
        {
            using type = seq;
        };
    }
}

#endif
