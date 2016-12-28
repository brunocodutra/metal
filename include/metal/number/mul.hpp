// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MUL_HPP
#define METAL_NUMBER_MUL_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename... nums>
        struct _mul;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the arithmetic multiplication of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::mul<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num_0{} * ... * num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp mul
    ///
    /// ### See Also
    /// \see number, inc, dec, neg, add, sub, div, mod, pow
    template<typename... nums>
    using mul = typename detail::_mul<nums...>::type;
}

#include <metal/number/number.hpp>
#include <metal/number/numbers.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/accumulate.hpp>
#include <metal/list/list.hpp>

#include <initializer_list>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename... nums>
        struct _mul
        {};

        template<>
        struct _mul<> :
            number<1>
        {};

        template<int_ x>
        struct _mul<number<x>> :
            number<x>
        {};

        template<int_ x, int_ y>
        struct _mul<number<x>, number<y>> :
            number<x * y>
        {};

#if defined(METAL_COMPAT_MODE)
        template<int_ x, int_ y, int_... tail>
        struct _mul<number<x>, number<y>, number<tail>...> :
            _accumulate<lambda<mul>, number<x>, numbers<y, tail...>>
        {};
#else
        template<typename... _>
        constexpr int_ imul(int_ head, _... tail) {
            int_ ret = head;
            for(int_ x : {tail...})
                ret *= x;

            return ret;
        }

        template<int_ x, int_ y, int_... tail>
        struct _mul<number<x>, number<y>, number<tail>...> :
            number<imul(x, y, tail...)>
        {};
#endif
    }
    /// \endcond
}

#endif
