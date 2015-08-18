// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_AT_KEY_HPP
#define METAL_SEQUENCE_AT_KEY_HPP

#include <metal/sequence/list.hpp>
#include <metal/core/inherit.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>
#include <metal/optional/extract.hpp>

namespace metal
{
    /// \ingroup sequece
    /// \brief ...
    template<typename seq, typename val>
    struct at_key
    {};

    /// \ingroup sequece
    /// \brief Eager adaptor for \ref at_key.
    template<typename seq, typename val>
    using at_key_t = extract<at_key<seq, val>>;

    namespace detail
    {
        template<typename key, typename val>
        just<val> at_key_impl(list<key, val>&&);
        template<typename>
        nothing at_key_impl(...);
    }

    template<template<typename...> class seq, typename key>
    struct at_key<seq<>, key>
    {};

    template<
        template<typename...> class map,
        template<typename...> class... pairs,
        typename... keys,
        typename... vals,
        typename key
    >
    struct at_key<map<pairs<keys, vals>...>, key> :
            decltype(detail::at_key_impl<key>(std::declval<inherit<list<keys, vals>...>>()))
    {};
}

#endif
