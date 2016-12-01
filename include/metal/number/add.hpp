// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_ADD_HPP
#define METAL_NUMBER_ADD_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename... nums>
        struct _add;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the arithmetic addition of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::add<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num_0{} + ... + num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp add
    ///
    /// ### See Also
    /// \see number, inc, dec, neg, sub, mul, div, mod, pow
    template<typename... nums>
    using add = typename detail::_add<nums...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/fold_left.hpp>
#include <metal/list/list.hpp>

#include <initializer_list>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename... nums>
        struct _add
        {};

        template<>
        struct _add<> :
            number<0>
        {};

        template<int_ x>
        struct _add<number<x>> :
            number<x>
        {};

        template<int_ x, int_ y>
        struct _add<number<x>, number<y>> :
            number<x + y>
        {};

#if defined(METAL_COMPAT_MODE)
        template<int_ x, int_ y, int_... tail>
        struct _add<number<x>, number<y>, number<tail>...> :
            _fold_left<numbers<y, tail...>, number<x>, lambda<add>>
        {};
#else
        template<typename... _>
        constexpr int_ iadd(int_ head, _... tail) {
            int_ ret = head;
            for(int_ x : {tail...})
                ret += x;

            return ret;
        }

        template<int_ x, int_ y, int_... tail>
        struct _add<number<x>, number<y>, number<tail>...> :
            number<iadd(x, y, tail...)>
        {};

#endif
    }
    /// \endcond
}

#endif
