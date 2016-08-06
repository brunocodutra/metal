// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MOD_HPP
#define METAL_NUMBER_MOD_HPP

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _mod;
    }

    /// \ingroup number
    /// Computes the remainder of the arithmetic division of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1, ..., num_n`
    /// \code
    ///     using result = metal::mod<num_1, ..., num_n>;
    /// \endcode
    ///
    /// \pre: all \numbers in `[num_2, ..., num_n]` are nonzero
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num_1{} % ... % num_n{}>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp mod
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, neg, add, sub, mul, div, pow
    template<typename head, typename... tail>
    using mod = typename detail::_mod<head, tail...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/fold.hpp>

#include <utility>
#include <initializer_list>

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _mod
        {};

        template<int_ x>
        struct _mod<number<x>> :
            number<x>
        {};

        template<int_ x, int_ y>
        struct _mod<number<x>, number<y>> :
            number<x % y>
        {};

        template<int_ x>
        struct _mod<number<x>, number<0>>
        {};

#if __cpp_constexpr >= 201304
        template<typename... _>
        constexpr int_ imod(int_ head, _... tail) {
            int_ ret = head;
            for(int_ x : {tail...})
                ret %= x;

            return ret;
        }

        template<typename, typename = true_>
        struct _mod_impl
        {};

        template<int_... vs>
        struct _mod_impl<std::integer_sequence<int_, vs...>,
            is_number<number<imod(vs...)>>
        >:
            number<imod(vs...)>
        {};

        template<int_ x, int_ y, int_... tail>
        struct _mod<number<x>, number<y>, number<tail>...> :
            _mod_impl<std::integer_sequence<int_, x, y, tail...>>
        {};
#else
        template<int_ x, int_ y, int_... tail>
        struct _mod<number<x>, number<y>, number<tail>...> :
            _fold<
                numbers<y, tail...>, number<x>, lambda<mod>,
                number<0>, number<sizeof...(tail) + 1>
            >
        {};
#endif
    }
}

#endif
