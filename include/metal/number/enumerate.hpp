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
    ///                 number<st::value_type, st::value + sd::value>,
    ///                 number<st::value_type, st::value + 2*sd::value>,
    ///                 ...,
    ///                 number<st::value_type, st::value + (sz::value - 1)*sd::value>,
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
    ///                 number<st::value_type, st::value - sd::value>,
    ///                 number<st::value_type, st::value - 2*sd::value>,
    ///                 ...,
    ///                 number<st::value_type, st::value - (sz::value - 1)*sd::value>,
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
    template<typename... _>
    using enumerate = detail::enumerate<_...>;

    /// \ingroup number
    /// Eager adaptor for \ref enumerate.
    template<typename... _>
    using enumerate_t = typename metal::enumerate<_...>::type;
}

#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/list/join.hpp>

#if defined(__has_builtin)
#   if __has_builtin(__make_integer_seq)
#       define NUMBERS(T, N) __make_integer_seq<numbers, T, (N)>
#   endif
#endif

namespace metal
{
    namespace detail
    {
        template<typename t, t... vs>
        struct numbers :
            list<number<t, vs>...>
        {};

        template<typename, typename, typename>
        struct stretch
        {};

        template<typename u, u a, typename v, v b>
        struct stretch<list<>, number<u, a>, number<v, b>> :
            list<>
        {};

        template<typename t, t... ns, typename u, u a, typename v, v b>
        struct stretch<list<number<t, ns>...>, number<u, a>, number<v, b>> :
            numbers<v, b + a*ns...>
        {};

#if defined(NUMBERS)
        template<typename t, t... ns, typename u, u a, typename v, v b>
        struct stretch<numbers<t, ns...>, number<u, a>, number<v, b>> :
            numbers<v, b + a*ns...>
        {};
#endif

        template<typename, typename, typename>
        struct enumerate
        {};

        template<typename t, t start, typename u, u size, typename v, v stride>
        struct enumerate<number<t, start>, number<u, size>, number<v, stride>> :
            stretch<
                enumerate_t<number<long long, size>>,
                number<long long, stride>,
                number<t, start>
            >
        {};

        template<typename t, t start, typename u, u size>
        struct enumerate<number<t, start>, number<u, size>> :
            enumerate<number<t, start>, number<u, size>, integer<1>>
        {};

#if defined(NUMBERS)
        template<typename t, t size>
        struct enumerate<number<t, size>> :
            stretch<
                NUMBERS(long long, size > 0 ? size : -size),
                number<long long, (size > 0 ? 1 : -1)>,
                number<t, 0>
            >
        {};
#else
        template<typename t, t size>
        struct enumerate<number<t, size>> :
            join<
                enumerate_t<number<t, size/2>>,
                enumerate_t<number<t, size/2>, number<t, size - size/2>>
            >
        {};

        template<typename t>
        struct enumerate<number<t, t(1)>> :
            list<number<t, 0>>
        {};

        template<typename t>
        struct enumerate<number<t, t(-1)>> :
            list<number<t, 0>>
        {};

        template<typename t>
        struct enumerate<number<t, t(0)>> :
            list<>
        {};
#endif
    }
}

#undef NUMBERS
#endif
