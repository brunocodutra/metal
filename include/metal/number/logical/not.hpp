// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_NOT_HPP
#define METAL_NUMBER_LOGICAL_NOT_HPP

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct not_;
    }

    /// \ingroup logical
    /// Computes the logical negation of a \number.
    ///
    /// Usage
    /// -----
    /// For any \value `val`
    /// \code
    ///     metal::not_<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \number, then equivalent to
    ///     \code
    ///         template<>
    ///         struct not_<val> :
    ///             boolean<!val::value>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/logical.cpp not_
    ///
    /// See Also
    /// --------
    /// \see boolean, and_, or_
    template<typename num>
    using not_ = detail::not_<num>;

    /// \ingroup arithmetic
    /// Eager adaptor for metal::not_.
    template<typename num>
    using not_t = typename metal::not_<num>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct not_
        {};

        template<typename t, t v>
        struct not_<number<t, v>> :
            boolean<v ? false : true>
        {};
    }
}

#endif
