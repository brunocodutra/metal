// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SPLICE_HPP
#define METAL_LIST_SPLICE_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename begin, typename end>
    struct splice
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref splice.
    template<typename list, typename begin, typename end>
    using splice_t = typename splice<list, begin, end>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/number/arithmetic/mod.hpp>

namespace metal
{
    template<
        template<typename...> class list, typename... vals,
        typename tf, tf vf, typename tl, tl vl
    >
    struct splice<list<vals...>, number<tf, vf>, number<tl, vl>> :
        transform<
            enumerate_t<number<tf, vf>, number<tl, vl>>,
            at<quote_t<list<vals...>>, mod<_1, size_t<list<vals...>>>>
        >
    {};
}

#endif
