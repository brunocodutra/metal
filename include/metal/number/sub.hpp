// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_SUB_HPP
#define METAL_NUMBER_SUB_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename head, typename... tail>
        struct _sub;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the arithmetic subtraction of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::sub<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num_0{} - ... - num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp sub
    ///
    /// ### See Also
    /// \see number, inc, dec, neg, add, mul, div, mod, pow
    template<typename head, typename... tail>
    using sub = typename detail::_sub<head, tail...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/accumulate.hpp>
#include <metal/list/list.hpp>

#include <initializer_list>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename head, typename... tail>
        struct _sub
        {};

        template<int_ x>
        struct _sub<number<x>> :
            number<x>
        {};

        template<int_ x, int_ y>
        struct _sub<number<x>, number<y>> :
            number<x - y>
        {};

#if defined(METAL_COMPAT_MODE)
        template<int_ x, int_ y, int_... tail>
        struct _sub<number<x>, number<y>, number<tail>...> :
            _accumulate<numbers<y, tail...>, number<x>, lambda<sub>>
        {};
#else
        template<typename... _>
        constexpr int_ isub(int_ head, _... tail) {
            int_ ret = head;
            for(int_ x : {tail...})
                ret -= x;

            return ret;
        }

        template<int_ x, int_ y, int_... tail>
        struct _sub<number<x>, number<y>, number<tail>...> :
            number<isub(x, y, tail...)>
        {};
#endif
    }
    /// \endcond
}

#endif
