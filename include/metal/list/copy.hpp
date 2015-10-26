// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_COPY_HPP
#define METAL_LIST_COPY_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename...>
    struct copy
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref copy.
    template<typename... args>
    using copy_t = typename copy<args...>::type;
}

#include <metal/lambda/apply.hpp>
#include <metal/lambda/defer.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/slice.hpp>
#include <metal/list/size.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    template<
        typename to,
        template<typename...> class from, typename... vals,
        typename b, b begin, typename e, e end
    >
    struct copy<to, from<vals...>, number<b, begin>, number<e, end>> :
        conditional<
            boolean<0 <= begin && begin <= end && end <= sizeof...(vals)>,
            copy<
                to,
                slice_t<
                    list<vals...>,
                    number<std::size_t, static_cast<std::size_t>(begin)>,
                    number<decltype(end - begin), end - begin>
                >
            >
        >
    {};

    template<
        typename to,
        template<typename...> class from, typename... vals,
        typename t, t n
    >
    struct copy<to, from<vals...>, number<t, n>, number<t, n>> :
        copy<to, list<>>
    {};

    template<
        typename to,
        template<typename...> class from, typename... vals,
        typename b, b begin
    >
    struct copy<to, from<vals...>, number<b, begin>> :
        copy<to, from<vals...>, number<b, begin>, size_t<from<vals...>>>
    {};

    template<template<typename...> class to, typename... vals, typename from>
    struct copy<to<vals...>, from> :
        apply<defer_t<lambda<to>>, from>
    {};
}

#endif
