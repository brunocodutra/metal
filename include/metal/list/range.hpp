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
        template<typename seq, typename beg, typename end, typename = true_>
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
#include <metal/list/slice.hpp>
#include <metal/number/dec.hpp>
#include <metal/number/sub.hpp>
#include <metal/number/less.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/value/value.hpp>

#include <metal/detail/declptr.hpp>

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
            template<typename... vals_>
            static list<vals_...> impl(void_<_>*..., value<vals_>*...);

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
            using type = slice<seq, dec<beg>, sub<beg, end>, number<-1>>;
        };

        template<typename seq, int_ beg>
        struct _range<seq, number<beg>, size<seq>> :
            _drop<enumerate<number<0>, number<beg>>, seq>
        {};

        template<typename seq>
        struct _range<seq, number<0>, size<seq>>
        {
            using type = seq;
        };
    }
}

#endif
