// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_AT_HPP
#define METAL_SEQUENCE_AT_HPP

#include <metal/sequence/at_key.hpp>
#include <metal/sequence/list.hpp>
#include <metal/sequence/zip.hpp>
#include <metal/sequence/enumerate.hpp>
#include <metal/sequence/size.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup sequece
    /// \brief ...
    template<typename seq, typename val>
    struct at;

    /// \ingroup sequece
    /// \brief Eager adaptor for \ref at.
    template<typename seq, typename val>
    using at_t = typename at<seq, val>::type;

    template<
        template<typename...> class list,
        typename... vals,
        typename t, t v
    >
    struct at<list<vals...>, number<t, v>> :
            at_key<
                zip_t<
                    enumerate_t<size_t<list<vals...>>>,
                    metal::list<vals...>
                >,
                number<std::size_t, v>
            >
    {};
}

#endif
