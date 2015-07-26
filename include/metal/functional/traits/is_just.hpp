// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_JUST_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_JUST_HPP

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename>
        struct type;

        template<typename x, typename = type<typename x::type>>
        std::true_type has_type(int);
        template<typename>
        std::false_type has_type(...);
    }

    /// \ingroup functional_traits
    /// \brief Checks whether an \optional has some value.
    ///
    /// Usage
    /// -----
    /// For any \optional `opt`,
    /// \code
    ///     using result = metal::is_just<opt>;
    /// \endcode
    ///
    /// \par Model:
    ///     \number
    ///
    /// \par Semantics:
    ///     if `opt::type` well defined defined and is a model of \value,
    ///     then equivalent to
    ///     \code
    ///         struct result :
    ///             std::true_type
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         struct result :
    ///             std::false_type
    ///         {};
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet functional/traits/is_just.cpp main
    ///
    /// See Also
    /// --------
    /// \see is_nothing
    template<typename opt>
    struct is_just :
            decltype(detail::has_type<opt>(0))
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for \ref is_just.
    template<typename opt>
    using is_just_t = typename metal::is_just<opt>::type;
}

#endif
