// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_RANGE_HPP
#define METAL_LIST_RANGE_HPP

#include <metal/config.hpp>

#include <metal/list/size.hpp>
#include <metal/number/if.hpp>
#include <metal/number/or.hpp>
#include <metal/number/not.hpp>
#include <metal/number/number.hpp>
#include <metal/number/greater.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename seq, typename beg, typename end>
        struct _range;

        template<typename seq, typename beg, typename end>
        using range = typename detail::_range<seq, beg, end>::type;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Returns a contiguous subsequence of a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \numbers `beg` and `end`
    /// \code
    ///     using result = metal::range<l, beg, end>;
    /// \endcode
    ///
    /// \pre: `metal::number<0>{} &le; beg{} &le; metal::size<l>{}` and
    /// `metal::number<0>{} &le; end{} &le; metal::size<l>{}`
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[i], ..., l[j], ..., l[m-1]`,
    ///     `beg{} == i` and `end{} == j`, then
    ///     \code
    ///         using result = metal::list<l[i], ..., l[j-1]>;
    ///     \endcode
    ///     otherwise, if `beg{} == j` and `end{} == i`, then
    ///     \code
    ///         using result = metal::list<l[j-1], ..., l[i]>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp range
    ///
    /// ### See Also
    /// \see list, erase, take, drop
    template<typename seq, typename beg, typename end>
    using range = detail::range<
        seq,
        if_<not_<or_<greater<number<0>, beg>, greater<beg, size<seq>>>>, beg>,
        if_<not_<or_<greater<number<0>, end>, greater<end, size<seq>>>>, end>
    >;
}

#include <metal/list/list.hpp>
#include <metal/list/rotate.hpp>
#include <metal/list/reverse.hpp>
#include <metal/number/sub.hpp>
#include <metal/number/max.hpp>
#include <metal/number/min.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<std::size_t n>
        struct skipper :
            skipper<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)>
        {};

        template<>
        struct skipper<100>
        {
            template<
                std::size_t n,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename... tail
            >
            using type = typename skipper<(n - 100)>::template type<
                (n - 100), tail...
            >;
        };

        template<>
        struct skipper<10>
        {
            template<
                std::size_t n,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename... tail
            >
            using type = typename skipper<(n - 10)>::template type<
                (n - 10), tail...
            >;
        };

        template<>
        struct skipper<1>
        {
            template<std::size_t n, typename, typename... tail>
            using type = typename skipper<(n - 1)>::template type<
                (n - 1), tail...
            >;
        };

        template<>
        struct skipper<0>
        {
            template<std::size_t, typename... vals>
            using type = list<vals...>;
        };

        template<typename seq, typename num>
        struct _skip
        {};

        template<typename... vals, int_ n>
        struct _skip<list<vals...>, number<n>>
        {
            using type = typename skipper<n>::template type<n, vals...>;
        };

        template<typename seq, typename num>
        using skip = typename _skip<seq, num>::type;

        template<typename seq, typename beg, typename end>
        struct _range
        {
            using b = min<beg, end>;
            using e = max<beg, end>;

            using type = range<
                range<range<seq, number<0>, e>, b, e>,
                sub<beg, b>,
                sub<end, b>
            >;
        };

        template<typename seq, typename num>
        struct _range<seq, number<0>, num>
        {
            using type = skip<rotate<seq, num>, sub<size<seq>, num>>;
        };

        template<typename seq, typename num>
        struct _range<seq, num, size<seq>>
        {
            using type = skip<seq, num>;
        };

        template<typename seq>
        struct _range<seq, number<0>, size<seq>>
        {
            using type = seq;
        };

        template<typename seq>
        struct _range<seq, size<seq>, number<0>>
        {
            using type = reverse<seq>;
        };

        template<>
        struct _range<list<>, number<0>, number<0>>
        {
            using type = list<>;
        };
    }
    /// \endcond
}

#endif
