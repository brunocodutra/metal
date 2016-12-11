// Copyright Bruno Dutra 2015-2016
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
#include <metal/list/iota.hpp>
#include <metal/list/rotate.hpp>
#include <metal/list/reverse.hpp>
#include <metal/number/sub.hpp>
#include <metal/number/max.hpp>
#include <metal/number/min.hpp>
#include <metal/value/value.hpp>

#include <metal/detail/declptr.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename> using void_ = void;

        template<typename, typename>
        struct _skip_impl
        {};

        template<typename... vals, typename... _>
        struct _skip_impl<list<vals...>, list<_...>>
        {
            template<typename... tail>
            static list<tail...> impl(void_<_>*..., value<tail>*...);

            using type = decltype(impl(declptr<value<vals>>()...));
        };

        template<typename seq, typename num>
        using skip = typename _skip_impl<seq, iota<number<0>, num>>::type;

        template<typename seq, typename beg, typename end>
        struct _range
        {
            using type = range<
                range<
                    range<seq, min<beg, end>, size<seq>>,
                    number<0>,
                    sub<max<beg, end>, min<beg, end>>
                >,
                sub<beg, min<beg, end>>,
                sub<end, min<beg, end>>
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
