// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_BACK_HPP
#define METAL_LIST_BACK_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct back;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using back = detail::back<list>;

    /// \ingroup list
    /// Eager adaptor for \ref back.
    template<typename list>
    using back_t = typename metal::back<list>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/size.hpp>
#include <metal/number/arithmetic/dec.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct back
        {};

        template<
            template<typename...> class expr,
            typename head, typename... tail
        >
        struct back<expr<head, tail...>> :
            at<expr<head, tail...>, dec_t<size_t<expr<head, tail...>>>>
        {};
    }
}

#endif
