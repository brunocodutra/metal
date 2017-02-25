// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_EXTERNAL_MPL_HPP
#define METAL_EXTERNAL_MPL_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _from_mpl;
    }
    /// \endcond

    /// \ingroup external
    ///
    /// ### Description
    /// Converts Boost.MPL concepts to their Metal equivalents.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::from_mpl<val>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `val` is an MPL Integral Constant, then
    ///     \code
    ///         using result = metal::number<val::value>;
    ///     \endcode
    ///     otherwise, if `val` is an MPL Pair, then
    ///     \code
    ///         using result = metal::pair<
    ///             metal::from_mpl<val::first>,
    ///             metal::from_mpl<val::second>
    ///         >;
    ///     \endcode
    ///     otherwise, if `val` is an MPL Sequence that contains
    ///     `val_0, ..., val_n-1`, then
    ///     \code
    ///         using result = metal::list<
    ///             metal::from_mpl<val_0>,
    ///             metal::from_mpl<>...,
    ///             metal::from_mpl<val_n-1>
    ///         >;
    ///     \endcode
    ///     otherwise, if `val` is an MPL Metafunction Class, then
    ///     \code
    ///         using result = metal::lambda<expr>;
    ///     \endcode
    ///     where `expr` is an \expression such that
    ///     \code
    ///         template<typename... args>
    ///         using expr = metal::from_mpl<
    ///             typename val::template apply<args...>::type
    ///         >;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = val;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet mpl.cpp number
    /// \snippet mpl.cpp list
    /// \snippet mpl.cpp vector
    /// \snippet mpl.cpp map
    /// \snippet mpl.cpp lambda
    template<typename val>
    using from_mpl = typename detail::_from_mpl<val>::type;
}

#include <metal/lambda/lambda.hpp>
#include <metal/list/append.hpp>
#include <metal/list/list.hpp>
#include <metal/map/map.hpp>
#include <metal/number/number.hpp>
#include <metal/pair/pair.hpp>
#include <metal/value/value.hpp>

#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/fold.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        same<typename val::tag, boost::mpl::integral_c_tag>
            number_like_impl(number<val::value>*);

        template<typename>
        false_ number_like_impl(...);

        template<typename val>
        using number_like = decltype(number_like_impl<val>(0));

        template<typename val>
        true_ pair_like_impl(pair<typename val::first, typename val::second>*);

        template<typename>
        false_ pair_like_impl(...);

        template<typename val>
        using pair_like = decltype(pair_like_impl<val>(0));

        template<typename val>
        using list_like = number<boost::mpl::is_sequence<val>::value>;

        template<typename val>
        true_ lambda_like_impl(lambda<val::template apply>*);

        template<typename>
        false_ lambda_like_impl(...);

        template<typename val>
        using lambda_like = decltype(lambda_like_impl<val>(0));

        template<typename val>
        true_ nullary_impl(value<typename val::apply>*);

        template<typename>
        false_ nullary_impl(...);

        template<typename val>
        using nullary = decltype(nullary_impl<val>(0));

        struct back_inserter
        {
            template<typename seq, typename val>
            struct apply
            {
                using type = append<seq, from_mpl<val>>;
            };
        };

        template<typename val, typename, typename, typename, typename, typename>
        struct _from_mpl_impl
        {
            using type = val;
        };

        template<typename val>
        struct _from_mpl_impl<val, true_, false_, false_, false_, false_>
        {
            using type = as_number<val>;
        };

        template<typename val>
        struct _from_mpl_impl<val, false_, true_, false_, false_, false_>
        {
            using type = pair<
                from_mpl<typename val::first>,
                from_mpl<typename val::second>
            >;
        };

        template<typename val>
        struct _from_mpl_impl<val, false_, false_, true_, false_, false_> :
            boost::mpl::fold<val, list<>, back_inserter>
        {};

        template<typename val>
        struct _from_mpl_impl<val, false_, false_, false_, true_, false_>
        {
            template<typename... args>
            using impl = from_mpl<typename val::template apply<args...>::type>;

            using type = lambda<impl>;
        };

        template<typename val>
        struct _from_mpl_impl<val, false_, false_, false_, false_, true_>
        {
            template<typename...>
            using impl = from_mpl<typename val::apply::type>;

            using type = lambda<impl>;
        };

        template<typename val>
        struct _from_mpl :
            _from_mpl_impl<val,
                number_like<val>,
                pair_like<val>,
                list_like<val>,
                lambda_like<val>,
                nullary<val>
            >
        {};
    }
    /// \endcond
}

#endif
