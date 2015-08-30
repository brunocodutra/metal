// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ZIP_HPP
#define METAL_LIST_ZIP_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list1, typename list2>
    struct zip
    {};

    /// \ingroup optional
    /// \brief Eager adaptor for \ref zip.
    template<typename list1, typename list2>
    using zip_t = typename zip<list1, list2>::type;

    template<template<typename...> class list, typename... xs, typename... ys>
    struct zip<list<xs...>, list<ys...>>
    {
        using type = list<list<xs, ys>...>;
    };
}

#endif
