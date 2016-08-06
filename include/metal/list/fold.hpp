// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FOLD_HPP
#define METAL_LIST_FOLD_HPP

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
        template<typename, typename, typename, typename, typename>
        struct _fold;
    }

    /// \ingroup list
    /// ...
    template<
        typename seq, typename state, typename lbd,
        typename beg = number<0>,
        typename end = size<seq>
    >
    using fold = typename detail::_fold<
        seq, state, lbd,
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
            typename seq, typename state, typename lbd,
            typename beg, typename mid, typename end
        >
        using fold_recurse = typename _fold<
            seq, typename _fold<seq, state, lbd, beg, mid>::type, lbd,
            mid, end
        >::type;

        template<typename, typename, typename, typename, typename>
        struct _fold
        {};

        template<typename seq, typename state, typename lbd, int_ b, int_ e>
        struct _fold<seq, state, lbd, number<b>, number<e>> :
            _invoke<
                lambda<fold_recurse>,
                seq, state, lbd, number<b>, number<(b + e)/2>, number<e>
            >
        {};

        template<typename seq, typename state, typename lbd, int_ b>
        struct _fold<seq, state, lbd, number<b>, number<b + 1>> :
            _invoke<lbd, state, at<seq, number<b>>>
        {};

        template<typename seq, typename state, typename lbd, int_ b>
        struct _fold<seq, state, lbd, number<b>, number<b - 1>> :
            _invoke<lbd, state, at<seq, number<b - 1>>>
        {};

        template<typename seq, typename state, typename lbd, int_ n>
        struct _fold<seq, state, lbd, number<n>, number<n>> :
            _if_<is_lambda<lbd>, state>
        {};
    }
}

#endif
