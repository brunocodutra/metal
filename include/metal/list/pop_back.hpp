// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_POP_BACK_HPP
#define METAL_LIST_POP_BACK_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct pop_back;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using pop_back = detail::pop_back<list>;

    /// \ingroup list
    /// Eager adaptor for metal::pop_back.
    template<typename list>
    using pop_back_t = typename metal::pop_back<list>::type;
}

#include <metal/list/erase.hpp>
#include <metal/list/size.hpp>
#include <metal/number/arithmetic/dec.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct pop_back
        {};

        template<
            template<typename...> class expr,
            typename head, typename... tail
        >
        struct pop_back<expr<head, tail...>> :
            erase<expr<head, tail...>, dec_t<size_t<expr<head, tail...>>>>
        {};
    }
}

#endif
