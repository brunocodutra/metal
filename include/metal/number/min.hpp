// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MIN_HPP
#define METAL_NUMBER_MIN_HPP

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _min;
    }

    /// \ingroup number
    /// Computes the minimum of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1, ..., num_n`
    /// \code
    ///     using result = metal::min<num_1, ..., num_n>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `m` the minimum value between all \numbers in
    ///     `num_1, ..., num_n`, then
    ///     \code
    ///         using result = metal::number<m>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp min
    ///
    /// See Also
    /// --------
    /// \see number, max
    template<typename head, typename... tail>
    using min = typename detail::_min<head, tail...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/fold.hpp>

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _min
        {};

        template<int_ x>
        struct _min<number<x>> :
            number<x>
        {};

        template<int_ x, int_ y>
        struct _min<number<x>, number<y>> :
            number<(x < y) ? x : y>
        {};

        template<int_ x, int_ y, int_... tail>
        struct _min<number<x>, number<y>, number<tail>...> :
            _fold<
                numbers<y, tail...>, number<x>, lambda<min>,
                number<0>, number<sizeof...(tail) + 1>
            >
        {};
    }
}

#endif
