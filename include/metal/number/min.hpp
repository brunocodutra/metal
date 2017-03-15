// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MIN_HPP
#define METAL_NUMBER_MIN_HPP

#include <metal/config.hpp>

#include <metal/detail/sfinae.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename... nums>
        struct _min;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the minimum of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::min<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `m` the minimum between all \numbers in `num_0, ..., num_n-1`,
    ///     then
    ///     \code
    ///         using result = m;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp min
    ///
    /// ### See Also
    /// \see number, greater, less, max
    template<typename... nums>
    using min = detail::call<detail::_min<nums...>::template type>;
}

#include <metal/number/if.hpp>
#include <metal/number/number.hpp>
#include <metal/number/less.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/value/fold_left.hpp>

#include <initializer_list>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename... nums>
        struct _min
        {};

#if defined(METAL_COMPAT_MODE)
        template<typename x, typename y>
        using min_impl = if_<less<x, y>, x, y>;

        template<int_... ns>
        struct _min<number<ns>...>
        {
            template<typename... _>
            using type = fold_left<lambda<min_impl>, number<ns>..., _...>;
        };
#else
        template<typename... _>
        constexpr int_ min_impl(int_ head, _... tail) {
            return void(std::initializer_list<int_>{
                (head = (tail < head) ? tail : head)...
            }), head;
        }

        template<int_... ns>
        struct _min<number<ns>...>
        {
            template<typename... _>
            using type = number<min_impl((void(sizeof...(_)), ns)...)>;
        };
#endif
    }
    /// \endcond
}

#endif
