// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ENUMERATE_HPP
#define METAL_NUMBER_ENUMERATE_HPP

#include <metal/detail/nil.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename = nil, typename = nil>
        struct enumerate;
    }

    /// \ingroup number
    /// Generates a \list of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \value `sz`
    /// \code
    ///     metal::enumerate<sz>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `sz` is a \number, then equivalent to
    ///     \code
    ///         template<>
    ///         struct enumerate<sz> :
    ///             enumerate<number<sz::value_type, 0>, sz>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// ________________________________________________________________________
    ///
    /// For any \values `st` and `sz`
    /// \code
    ///     metal::enumerate<st, sz>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         template<>
    ///         struct enumerate<st, sz> :
    ///             enumerate<st, sz, integer<1>>
    ///         {};
    ///     \endcode
    ///
    /// ________________________________________________________________________
    ///
    /// For any \values `st`, `sz` and `sd`
    /// \code
    ///     metal::enumerate<st, sz, sd>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `st`, `sz` and `sd` are \numbers and
    ///     `sz` is equal to zero, then equivalent to
    ///     \code
    ///         template<>
    ///         struct enumerate<st, sz, sd> :
    ///             list<>
    ///         {};
    ///     \endcode
    ///     otherwise, if `st`, `sz` and `sd` are \numbers and
    ///     `sz` is positive, then equivalent to
    ///     \code
    ///         template<>
    ///         struct enumerate<st, sz, sd> :
    ///             list<
    ///                 st,
    ///                 number<st::value_type, st{} + sd{}>,
    ///                 number<st::value_type, st{} + 2*sd{}>,
    ///                 ...,
    ///                 number<st::value_type, st{} + (sz{} - 1)*sd{}>,
    ///             >
    ///         {};
    ///     \endcode
    ///     otherwise, if `st`, `sz` and `sd` are \numbers and
    ///     `sz` is negative, then equivalent to
    ///     \code
    ///         template<>
    ///         struct enumerate<st, sz, sd> :
    ///             list<
    ///                 st,
    ///                 number<st::value_type, st{} - sd{}>,
    ///                 number<st::value_type, st{} - 2*sd{}>,
    ///                 ...,
    ///                 number<st::value_type, st{} - (1 - sz{})*sd{}>,
    ///             >
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/enumerate.cpp enumerate
    ///
    /// See Also
    /// --------
    /// \see number
    template<
        typename start,
        typename size = detail::nil,
        typename stride = detail::nil
    >
    using enumerate = detail::enumerate<start, size, stride>;

    /// \ingroup number
    /// Eager adaptor for metal::enumerate.
    template<
        typename start,
        typename size = detail::nil,
        typename stride = detail::nil
    >
    using enumerate_t = typename metal::enumerate<start, size, stride>::type;
}

#include <metal/number/number.hpp>
#include <metal/list/list.hpp>

#include <utility>

#if defined(__has_builtin)
#   if __has_builtin(__make_integer_seq)
#       define METAL_HAS_MAKE_INTEGER_SEQ
#   endif
#endif

namespace metal
{
    namespace detail
    {
        template<typename t, t... v>
        using numbers = std::integer_sequence<t, v...>;

#if defined(METAL_HAS_MAKE_INTEGER_SEQ)
        template<typename t, t n>
        using make_numbers_t = __make_integer_seq<numbers, t, n>;
#else
        template<typename t, t n>
        using make_numbers_t = std::make_integer_sequence<t, n>;
#endif

        template<typename, typename, typename>
        struct stretch
        {};

        template<typename t, t... ns, typename u, u a, typename v, v b>
        struct stretch<numbers<t, ns...>, number<u, a>, number<v, b>> :
            list<number<v, b + a*ns>...>
        {};

        template<typename, typename = nil, typename = nil, typename = boolean<true>>
        struct enumerate_impl
        {};

        template<typename t, t st, typename u, u sz, typename v, v sd>
        struct enumerate_impl<number<t, st>, number<u, sz>, number<v, sd>,
            boolean<(sz >= 0)>
        > :
            stretch<
                make_numbers_t<long long, sz>,
                number<long long, sd>,
                number<t, st>
            >
        {};

        template<typename t, t st, typename u, u sz, typename v, v sd>
        struct enumerate_impl<number<t, st>, number<u, sz>, number<v, sd>,
            boolean<(sz < 0)>
        > :
            stretch<
                make_numbers_t<long long, 0 - static_cast<long long>(sz)>,
                number<long long, 0 - static_cast<long long>(sd)>,
                number<t, st>
            >
        {};

        template<typename start, typename size, typename stride>
        struct enumerate :
            enumerate_impl<start, size, stride>
        {};

        template<typename t, t start, typename u, u size>
        struct enumerate<number<t, start>, number<u, size>> :
            enumerate_impl<number<t, start>, number<u, size>, integer<1>>
        {};

        template<typename t, t size>
        struct enumerate<number<t, size>> :
            enumerate_impl<number<t, 0>, number<t, size>, integer<1>>
        {};
    }
}

#endif
