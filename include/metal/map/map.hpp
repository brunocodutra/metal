// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_MAP_HPP
#define METAL_MAP_MAP_HPP

#include <metal/config.hpp>

#include <metal/list/list.hpp>
#include <metal/list/transform.hpp>
#include <metal/pair/pair.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_map;
    }
    /// \endcond

    /// \ingroup map
    ///
    /// ### Description
    /// Checks whether some \value is a \map.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::is_map<val>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `val` is a \map, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet map.cpp is_map
    ///
    /// ### See Also
    /// \see map, is_value, is_number, is_lambda, is_pair, is_list
    template<typename val>
    using is_map = typename detail::_is_map<val>::type;

    /// \ingroup map
    ///
    /// ### Description
    /// Constructs a \map out of a sequence of \pairs.
    ///
    /// ### Usage
    /// For any \pairs `pair_0, ..., pair_n-1`
    /// \code
    ///     using result = metal::map<pair_0, ..., pair_n-1>;
    /// \endcode
    ///
    /// \pre: No two \pairs have the same key
    /// \returns: \map
    ///
    /// ### See Also
    /// \see is_map
    template<typename... pairs>
    using map = metal::if_<
        metal::is_map<metal::list<pairs...>>,
        metal::list<pairs...>
    >;

    /// \ingroup map
    ///
    /// ### Description
    /// Constructs a \map out of any \value that is a specialization of a
    /// template class or union whose template parameters are all themselves
    /// specializations of template classes or unions that take exactly two
    /// template parameters, the first \values of which are all distinct.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::as_map<val>;
    /// \endcode
    ///
    /// \returns: \map
    ///
    /// ### Example
    /// \snippet map.cpp as_map
    ///
    /// ### See Also
    /// \see map
    template<typename val>
    using as_map = metal::apply<
        metal::lambda<metal::map>,
        metal::transform<metal::lambda<metal::as_pair>, metal::as_list<val>>
    >;
}

#include <metal/number/number.hpp>
#include <metal/value/distinct.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_map :
            false_
        {};

        template<>
        struct _is_map<list<>> :
            true_
        {};

        template<typename... keys, typename... vals>
        struct _is_map<list<list<keys, vals>...>> :
            distinct<keys...>
        {};
    }
    /// \endcond
}

#endif
