// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_ENUMERATE_HPP
#define METAL_NUMBER_ENUMERATE_HPP

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename>
        struct _enumerate;
    }

    /// \ingroup number
    /// Generates a \seq of \numbers.
    ///
    /// Usage
    /// -----
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
    template<typename start, typename size, typename stride = int_<1>>
    using enumerate = typename detail::_enumerate<start, size, stride>::type;
}

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
        using make_numbers = __make_integer_seq<numbers, t, n>;
#else
        template<typename t, t n>
        using make_numbers = std::make_integer_sequence<t, n>;
#endif

        template<typename t, t... vs>
        struct _as_list
        {
            using type = list<number<t, vs>...>;
        };

        template<typename, typename, typename>
        struct _stretch
        {};

        template<typename t, t... ns, typename u, u a, typename v, v b>
        struct _stretch<numbers<t, ns...>, number<u, a>, number<v, b>> :
            _as_list<v, (b + a*ns)...>
        {};

        template<typename, typename, typename>
        struct _enumerate
        {};

        template<typename t, t st, typename u, u sz, typename v, v sd>
        struct _enumerate<number<t, st>, number<u, sz>, number<v, sd>> :
            _stretch<
                make_numbers<
                    long long,
                    (sz > 0) ?
                        static_cast<long long>(sz) :
                            0 - static_cast<long long>(sz)
                >,
                number<
                    long long,
                    (sz > 0) ?
                        static_cast<long long>(sd) :
                            0 - static_cast<long long>(sd)
                >,
                number<t, st>
            >
        {};
    }
}

#endif
