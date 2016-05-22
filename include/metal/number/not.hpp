// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_NOT_HPP
#define METAL_NUMBER_NOT_HPP

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct _not_;
    }

    /// \ingroup number
    /// Computes the logical negation of a \number.
    ///
    /// Usage
    /// -----
    /// For any \number `num`
    /// \code
    ///     using result = metal::not_<num>;
    /// \endcode
    ///
    /// \returns: \boolean
    /// \semantics:
    ///     \code
    ///         using result = metal::bool_<!val{}>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp not_
    ///
    /// See Also
    /// --------
    /// \see and_, or_
    template<typename num>
    using not_ = typename detail::_not_<num>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct _not_
        {};

        template<typename t, t v>
        struct _not_<number<t, v>> :
            bool_<v ? false : true>
        {};
    }
}

#endif
