// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ZIP_HPP
#define METAL_LIST_ZIP_HPP

#include <metal/list/list.hpp>

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename xl, typename yl>
    struct zip
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref zip.
    template<typename list1, typename list2>
    using zip_t = typename zip<list1, list2>::type;

    template<
        template<typename...> class xl, typename... xs,
        template<typename...> class yl, typename... ys
    >
    struct zip<xl<xs...>, yl<ys...>> :
        list<list<xs, ys>...>
    {};
}

#endif
