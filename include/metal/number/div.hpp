// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_DIV_HPP
#define METAL_NUMBER_DIV_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename head, typename... tail>
        struct _div;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the quotient of the arithmetic division of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::div<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \pre: All \numbers in `num_1, ..., num_n-1` are nonzero
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} / ... / num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp div
    ///
    /// ### See Also
    /// \see number, inc, dec, neg, add, sub, mul, mod, pow
    template<typename head, typename... tail>
    using div = typename detail::_div<head, tail...>::type;
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
        template<typename head, typename... tail>
        struct _div
        {};

        template<int_ x>
        struct _div<number<x>> :
            number<x>
        {};

        template<int_ x, int_ y>
        struct _div<number<x>, number<y>> :
            number<x / y>
        {};

        template<int_ x>
        struct _div<number<x>, number<0>>
        {};

#if defined(METAL_COMPAT_MODE)
        template<int_ x, int_ y, int_... tail>
        struct _div<number<x>, number<y>, number<tail>...> :
            _fold_left<numbers<y, tail...>, number<x>, lambda<div>>
        {};
#else
        template<typename... _>
        constexpr int_ idiv(int_ head, _... tail) {
            int_ ret = head;
            for(int_ x : {tail...})
                ret /= x;

            return ret;
        }

        template<typename, typename = true_>
        struct _div_impl
        {};

        template<int_... vs>
        struct _div_impl<list<number<vs>...>,
            is_number<number<idiv(vs...)>>
        >:
            number<idiv(vs...)>
        {};

        template<int_ x, int_ y, int_... tail>
        struct _div<number<x>, number<y>, number<tail>...> :
            _div_impl<numbers<x, y, tail...>>
        {};
#endif
    }
    /// \endcond
}

#endif
