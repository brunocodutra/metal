// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_JUST_HPP
#define METAL_OPTIONAL_JUST_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename value>
    struct just
    {
        using type = value;
    };

    /// \ingroup optional
    /// \brief Checks whether an \optional represents some value.
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
    ///     if `opt::type` well defined and is a model of \value,
    ///     then equivalent to
    ///     \code
    ///         struct result :
    ///             boolean<true>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         struct result :
    ///             boolean<false>
    ///         {};
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet optional/just.cpp is_just
    ///
    /// See Also
    /// --------
    /// \see is_nothing
    template<typename opt>
    struct is_just;

    /// \ingroup optional
    /// \brief Eager adaptor for \ref is_just.
    template<typename opt>
    using is_just_t = typename metal::is_just<opt>::type;

    namespace detail
    {
        template<typename opt>
        struct is_just_impl
        {
        private:
            template<typename>
            struct wrapper;

            template<typename x, typename = wrapper<typename x::type>>
            static boolean<true> impl(int);
            template<typename>
            static boolean<false> impl(...);

        public:
            using type = decltype(impl<opt>(0));
        };
    }

    template<typename opt>
    struct is_just :
            detail::is_just_impl<opt>::type
    {};
}

#endif
