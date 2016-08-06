// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_REDUCE_HPP
#define METAL_LIST_REDUCE_HPP

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
        template<typename, typename, typename, typename>
        struct _reduce;
    }

    /// \ingroup list
    /// ...
    template<
        typename seq, typename lbd,
        typename beg = number<0>,
        typename end = size<seq>
    >
    using reduce = typename detail::_reduce<
        seq, lbd,
        if_<not_<or_<greater<number<0>, beg>, greater<beg, size<seq>>>>, beg>,
        if_<not_<or_<greater<number<0>, end>, greater<end, size<seq>>>>, end>
    >::type;
}

#include <metal/list/at.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename seq, typename lbd,
            typename beg, typename mid, typename end
        >
        using reduce_recurse = invoke<lbd,
            typename _reduce<seq, lbd, beg, mid>::type,
            typename _reduce<seq, lbd, mid, end>::type
        >;

        template<typename seq, typename lbd, typename beg, typename end>
        struct _reduce
        {};

        template<typename seq, typename lbd, int_ b, int_ e>
        struct _reduce<seq, lbd, number<b>, number<e>> :
            _invoke<
                lambda<reduce_recurse>,
                seq, lbd, number<b>, number<(b + e)/2>, number<e>
            >
        {};

        template<typename seq, typename lbd, int_ b>
        struct _reduce<seq, lbd, number<b>, number<b + 1>> :
            _if_<is_lambda<lbd>, at<seq, number<b>>>
        {};

        template<typename seq, typename lbd, int_ b>
        struct _reduce<seq, lbd, number<b>, number<b - 1>> :
            _if_<is_lambda<lbd>, at<seq, number<b - 1>>>
        {};

        template<typename seq, typename lbd, int_ n>
        struct _reduce<seq, lbd, number<n>, number<n>>
        {};
    }
}

#endif
