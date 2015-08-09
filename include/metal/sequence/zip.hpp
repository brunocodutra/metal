// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_ZIP_HPP
#define METAL_SEQUENCE_ZIP_HPP

namespace metal
{
    /// \ingroup sequence
    /// \brief ...
    template<typename seq1, typename seq2>
    struct zip;

    /// \ingroup optional
    /// \brief Eager adaptor for \ref zip.
    template<typename seq1, typename seq2>
    using zip_t = typename zip<seq1, seq2>::type;

    template<template<typename...> class list, typename... xs, typename... ys>
    struct zip<list<xs...>, list<ys...>>
    {
        using type = list<list<xs, ys>...>;
    };
}

#endif
