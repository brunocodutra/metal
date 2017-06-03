// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_IF_HPP
#define METAL_NUMBER_IF_HPP

#include "../config.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename...>
        struct _if_;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// A multi-clause conditional expression.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1` and \values `val_0, ..., val_n`
    /// \code
    ///     using result = metal::if<
    ///         num_0, val_0,
    ///         ...,
    ///         num_n-1, val_n-1,
    ///         val_n
    ///     >;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `num_i{} != false` and `num_j{} == false` for all `j < i`, then
    ///     \code
    ///         using result = val_i;
    ///     \endcode
    ///     otherwise, if `num_i{} == false` for all `i` in `[0, n-1]`, then
    ///     \code
    ///         using result = val_n;
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

#include "../number/number.hpp"

namespace metal {
    /// \cond
    namespace detail {
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
    /// \endcond
}

#endif
