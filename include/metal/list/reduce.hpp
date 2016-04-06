// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REDUCE_HPP
#define METAL_LIST_REDUCE_HPP

#include <metal/detail/nil.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename = nil, typename = nil>
        struct reduce;
    }

    /// \ingroup list
    /// ...
    template<
        typename list,
        typename lbd,
        typename begin = detail::nil,
        typename end = detail::nil
    >
    using reduce = detail::reduce<list, lbd, begin, end>;

    /// \ingroup list
    /// Eager adaptor for metal::reduce.
    template<
        typename list,
        typename lbd,
        typename begin = detail::nil,
        typename end = detail::nil
    >
    using reduce_t = typename metal::reduce<list, lbd, begin, end>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/number/number.hpp>
#include <metal/list/at.hpp>

#include <cstddef>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename>
        struct reduce
        {};

        template<typename list, typename lbd, typename t, t l, t r>
        struct reduce<list, lbd, number<t, l>, number<t, r>> :
            invoke<
                lift_t<lbd>,
                reduce<list, lbd, number<t, l>, number<t, (l + r)/2>>,
                reduce<list, lbd, number<t, (l + r)/2>, number<t, r>>
            >
        {};

        template<typename list, typename lbd, typename t, t l>
        struct reduce<list, lbd, number<t, l>, number<t, l + 2>> :
            invoke<
                lift_t<lbd>,
                at<list, number<t, l>>,
                at<list, number<t, l + 1>>
            >
        {};

        template<typename list, typename lbd, typename t, t l>
        struct reduce<list, lbd, number<t, l>, number<t, l + 1>> :
            at<list, number<t, l>>
        {};

        template<typename list, typename lbd, typename t, t l>
        struct reduce<list, lbd, number<t, l>, number<t, l - 2>> :
            invoke<
                lift_t<lbd>,
                at<list, number<t, l - 1>>,
                at<list, number<t, l - 2>>
            >
        {};

        template<typename list, typename lbd, typename t, t l>
        struct reduce<list, lbd, number<t, l>, number<t, l - 1>> :
            at<list, number<t, l - 1>>
        {};

        template<typename list, typename lbd, typename t, t l>
        struct reduce<list, lbd, number<t, l>, number<t, l>>
        {};

        template<typename list, typename lbd, typename t, t l, typename u, u r>
        struct reduce<list, lbd, number<t, l>, number<u, r>> :
            reduce<
                list,
                lbd,
                number<decltype(l + r), l>,
                number<decltype(l + r), r>
            >
        {};

        template<typename list, typename lbd, typename t, t l>
        struct reduce<list, lbd, number<t, l>> :
            invoke<reduce<_1, _2, number<t, l>, size<_1>>, list, lbd>
        {};

        template<typename list, typename lbd>
        struct reduce<list, lbd> :
            reduce<list, lbd, number<std::size_t, 0>>
        {};
    }
}

#endif
