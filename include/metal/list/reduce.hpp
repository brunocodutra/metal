// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REDUCE_HPP
#define METAL_LIST_REDUCE_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename...>
    struct reduce;

    /// \ingroup list
    /// \brief Eager adaptor for \ref reduce.
    template<typename... _>
    using reduce_t = typename reduce<_...>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/number.hpp>

#include <cstddef>

namespace metal
{
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
        invoke<lift_t<lbd>, at<list, number<t, l>>, at<list, number<t, l + 1>>>
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
            number<decltype(l + r), static_cast<decltype(l + r)>(l)>,
            number<decltype(l + r), static_cast<decltype(l + r)>(r)>
        >
    {};

    template<typename list, typename lbd, typename t, t l>
    struct reduce<list, lbd, number<t, l>> :
        invoke<
            reduce<
                quote_t<list>,
                quote_t<lbd>,
                number<t, l>,
                size<quote_t<list>>
            >
        >
    {};

    template<typename list, typename lbd>
    struct reduce<list, lbd> :
        reduce<list, lbd, number<std::size_t, 0>>
    {};
}

#endif
