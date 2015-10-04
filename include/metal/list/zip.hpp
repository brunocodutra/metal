// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ZIP_HPP
#define METAL_LIST_ZIP_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename... lists>
    struct zip
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref zip.
    template<typename... lists>
    using zip_t = typename zip<lists...>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/same.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>
#include <metal/optional/eval.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/conditional.hpp>


namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct zip_impl :
            transform<
                enumerate_t<size_t<head>>,
                list<at<quote_t<head>, _1>, at<quote_t<tail>, _1>...>
            >
        {};

        template<
            template<typename...> class xl, typename... xs,
            template<typename...> class yl, typename... ys
        >
        struct zip_impl<xl<xs...>, yl<ys...>> :
            list<list<xs, ys>...>
        {};
    }

    template<
        template<typename...> class xl, typename... xs,
        template<typename...> class yl, typename... ys,
        typename... tail
    >
    struct zip<xl<xs...>, yl<ys...>, tail...> :
        conditional<
            same_t<
                list<
                    size_t<xl<xs...>>,
                    size_t<yl<ys...>>,
                    conditional_t<is_list_t<tail>, size<tail>, just<void>>...
                >
            >,
            detail::zip_impl<xl<xs...>, yl<ys...>, tail...>
        >
    {};

    template<template<typename...> class xl, typename... xs>
    struct zip<xl<xs...>> :
        list<list<xs>...>
    {};
}

#endif
