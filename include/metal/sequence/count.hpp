// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_COUNT_HPP
#define METAL_SEQUENCE_COUNT_HPP

#include <metal/number/arithmetic/add.hpp>
#include <metal/optional/extract.hpp>

#include <type_traits>

namespace metal
{
    /// \ingroup sequece
    /// \brief ...
    template<typename seq, typename val>
    struct count
    {};

    /// \ingroup sequece
    /// \brief Eager adaptor for \ref count.
    template<typename seq, typename val>
    using count_t = typename count<seq, val>::type;

    template<
        template<typename...> class list,
        typename... vals,
        typename val
    >
    struct count<list<vals...>, val> :
            add<extract<std::is_same<vals, val>>...>
    {};
}

#endif
