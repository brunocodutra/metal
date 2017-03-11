// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SORT_HPP
#define METAL_LIST_SORT_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename seq, typename lbd>
        struct _sort;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Sorts the elements of a \list according to an ordering relation.
    ///
    /// \tip{The sorting is [stable] if the ordering relation is [strict].}
    /// [stable]: https://en.wikipedia.org/wiki/Sorting_algorithm#Stability
    /// [strict]: https://en.wikipedia.org/wiki/Weak_ordering#Strict_weak_orderings
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::sort<l, lbd>;
    /// \endcode
    ///
    /// \pre: For any two \values `val_i` and `val_j` contained in `l`
    /// `metal::invoke<lbd, val_i, val_j>` returns a \number
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<val_0, ..., val_m-1>;
    ///     \endcode
    ///     where `val_0, ..., val_m-1` is a permutation of the elements in `l`
    ///     such that `metal::invoke<lbd, val_i, val_i+1>{} != false` for all
    ///     `i` in `[0, m-2]`.
    ///
    /// ### Example
    /// \snippet list.cpp sort
    ///
    /// ### See Also
    /// \see list, reverse, rotate
    template<typename seq, typename lbd>
    using sort = typename detail::_sort<seq, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>
#include <metal/list/size.hpp>
#include <metal/list/range.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>
#include <metal/number/div.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename, typename, typename, typename, typename = true_>
        struct _merge
        {};

        template<
            typename ret,
            typename xh, typename... xt,
            typename yh, typename... yt,
            template<typename...> class expr
        >
        struct _merge<ret, list<xh, xt...>, list<yh, yt...>, lambda<expr>,
            if_<expr<yh, xh>, false_, true_>
        > :
            _merge<
                join<ret, list<xh>>, list<xt...>, list<yh, yt...>, lambda<expr>
            >
        {};

        template<
            typename ret,
            typename xh, typename... xt,
            typename yh, typename... yt,
            template<typename...> class expr
        >
        struct _merge<ret, list<xh, xt...>, list<yh, yt...>, lambda<expr>,
            if_<expr<yh, xh>, true_, false_>
        > :
            _merge<
                join<ret, list<yh>>, list<xh, xt...>, list<yt...>, lambda<expr>
            >
        {};

        template<typename ret, typename seq, typename lbd>
        struct _merge<ret, seq, list<>, lbd>
        {
            using type = join<ret, seq>;
        };

        template<typename ret, typename seq, typename lbd>
        struct _merge<ret, list<>, seq, lbd>
        {
            using type = join<ret, seq>;
        };

        template<typename ret, typename lbd>
        struct _merge<ret, list<>, list<>, lbd>
        {
            using type = ret;
        };

        template<typename seq, typename lbd>
        using sort_impl = typename _merge<
            list<>,
            sort<range<seq, number<0>, div<size<seq>, number<2>>>, lbd>,
            sort<range<seq, div<size<seq>, number<2>>, size<seq>>, lbd>,
            lbd
        >::type;

        template<typename seq, typename lbd>
        struct _sort :
            _invoke<lambda<sort_impl>, seq, lbd>
        {};

        template<typename x, typename y, typename lbd>
        struct _sort<list<x, y>, lbd> :
            _merge<list<>, list<x>, list<y>, lbd>
        {};

        template<typename x, typename lbd>
        struct _sort<list<x>, lbd> :
            _if_<is_lambda<lbd>, list<x>>
        {};

        template<typename lbd>
        struct _sort<list<>, lbd> :
            _if_<is_lambda<lbd>, list<>>
        {};
    }
    /// \endcond
}

#endif
