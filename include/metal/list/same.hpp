// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SAME_HPP
#define METAL_LIST_SAME_HPP

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _same;
    }

    /// \ingroup list
    /// ...
    template<typename seq>
    using same = typename detail::_same<seq>::type;
}

#include <metal/list/list.hpp>
#include <metal/number/number.hpp>
#include <metal/value/value.hpp>

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct _same_impl :
            false_
        {};

        template<template<typename> class... _, typename val>
        struct _same_impl<_<val>...> :
            true_
        {};

        template<typename seq>
        struct _same
        {};

        template<typename... vals>
        struct _same<list<vals...>> :
            _same_impl<value<vals>...>
        {};

        template<>
        struct _same<list<>> :
            true_
        {};
    }
}

#endif
