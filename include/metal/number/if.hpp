// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_IF_HPP
#define METAL_NUMBER_IF_HPP

#include <metal/config.hpp>

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct _if_;
    }

    /// \ingroup number
    /// A multi-clause conditional expression.
    ///
    /// ### Usage
    /// For any \numbers `num_1, ..., num_n` and \values `val_1, ..., val_n+1`
    /// \code
    ///     using result = metal::if<num_1, val_1, ..., num_n, val_n, val_n+1>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `num_i{} != false` and `num_j{} == false` for all `j < i`, then
    ///     \code
    ///         using result = val_i;
    ///     \endcode
    ///     otherwise, if `num_i{} == false` for all `i` in `[1, ..., n]`, then
    ///     \code
    ///         using result = val_n+1;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp if_
    ///
    /// ### See Also
    /// \see number
    template<typename cond, typename then_, typename... else_>
    using if_ = typename detail::_if_<cond, then_, else_...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct _if_
        {};

        template<typename then_, typename... else_>
        struct _if_<false_, then_, else_...> :
            _if_<else_...>
        {};

        template<typename then_, typename else_>
        struct _if_<false_, then_, else_>
        {
            using type = else_;
        };

        template<int_ v, typename then_, typename... else_>
        struct _if_<number<v>, then_, else_...>
        {
            using type = then_;
        };
    }
}

#endif
