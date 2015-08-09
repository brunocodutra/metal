// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_CONTAINS_HPP
#define METAL_SEQUENCE_CONTAINS_HPP

#include <metal/number/logical/or.hpp>
#include <metal/optional/extract.hpp>

#include <type_traits>

namespace metal
{
    /// \ingroup sequece
    /// \brief ...
    template<typename seq, typename val>
    struct contains;

    /// \ingroup sequece
    /// \brief Eager adaptor for \ref contains.
    template<typename seq, typename val>
    using contains_t = typename contains<seq, val>::type;

    template<
        template<typename...> class list,
        typename... vals,
        typename val
    >
    struct contains<list<vals...>, val> :
            or_<extract<std::is_same<vals, val>>...>
    {};
}

#endif
