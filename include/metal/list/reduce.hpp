// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_REDUCE_HPP
#define METAL_LIST_REDUCE_HPP

#include <metal/list/size.hpp>
#include <metal/number/if.hpp>
#include <metal/number/not.hpp>
#include <metal/number/less.hpp>
#include <metal/number/cast.hpp>
#include <metal/number/number.hpp>

#include <cstddef>

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
        typename beg = metal::size_t<0>,
        typename end = metal::size<seq>
    >
    using reduce = typename detail::_reduce<
        seq, lbd,
        if_<not_<less<size<seq>, beg>>, cast<beg, std::size_t>>,
        if_<not_<less<size<seq>, end>>, cast<end, std::size_t>>
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

        template<typename seq, typename lbd, std::size_t b, std::size_t e>
        struct _reduce<seq, lbd, size_t<b>, size_t<e>> :
            _invoke<
                lambda<reduce_recurse>,
                seq, lbd, size_t<b>, size_t<(b + e)/2>, size_t<e>
            >
        {};

        template<typename seq, typename lbd, std::size_t b>
        struct _reduce<seq, lbd, size_t<b>, size_t<b + 1>> :
            _if_<is_lambda<lbd>, at<seq, size_t<b>>>
        {};

        template<typename seq, typename lbd, std::size_t b>
        struct _reduce<seq, lbd, size_t<b>, size_t<b - 1>> :
            _if_<is_lambda<lbd>, at<seq, size_t<b - 1>>>
        {};

        template<typename seq, typename lbd, std::size_t n>
        struct _reduce<seq, lbd, size_t<n>, size_t<n>>
        {};
    }
}

#endif
