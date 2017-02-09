// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MAX_HPP
#define METAL_NUMBER_MAX_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename head, typename... tail>
        struct _max;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the maximum of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::max<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `M` the maximum between all \numbers in `num_0, ..., num_n-1`,
    ///     then
    ///     \code
    ///         using result = M;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp max
    ///
    /// ### See Also
    /// \see number, greater, less, min
    template<typename head, typename... tail>
    using max = typename detail::_max<head, tail...>::type;
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
        template<typename head, typename... tail>
        struct _max
        {};

        template<int_ x>
        struct _max<number<x>> :
            number<x>
        {};

        template<int_ x, int_ y>
        struct _max<number<x>, number<y>> :
            number<(x > y) ? x : y>
        {};

#if defined(METAL_COMPAT_MODE)
        template<int_ x, int_ y, int_... tail>
        struct _max<number<x>, number<y>, number<tail>...> :
            _accumulate<lambda<max>, number<x>, numbers<y, tail...>>
        {};
#else
        template<typename... _>
        constexpr int_ imax(int_ head, _... tail) {
            int_ ret = head;
            void(std::initializer_list<int_>{
                (ret = (tail > ret) ? tail : ret)...
            });
            return ret;
        }

        template<int_ x, int_ y, int_... tail>
        struct _max<number<x>, number<y>, number<tail>...> :
            number<imax(x, y, tail...)>
        {};
#endif
    }
    /// \endcond
}

#endif
