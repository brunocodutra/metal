// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MAX_HPP
#define METAL_NUMBER_MAX_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename... nums>
        struct _max;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the maximum of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::max<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `M` the maximum between all \numbers in `num_0, ..., num_n-1`,
    ///     then
    ///     \code
    ///         using result = M;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp max
    ///
    /// ### See Also
    /// \see number, greater, less, min
    template<typename... nums>
    using max = detail::call<detail::_max<nums...>::template type>;
}

#include "../number/if.hpp"
#include "../number/number.hpp"
#include "../number/greater.hpp"
#include "../lambda/lambda.hpp"
#include "../value/fold_left.hpp"

#include <initializer_list>

namespace metal {
    /// \cond
    namespace detail {
        template<typename... nums>
        struct _max
        {};

#if defined(METAL_WORKAROUND)
        template<typename x, typename y>
        using max_impl = if_<greater<x, y>, x, y>;

        template<int_... ns>
        struct _max<number<ns>...>
        {
            template<typename... _>
            using type = fold_left<lambda<max_impl>, number<ns>..., _...>;
        };
#else
        template<typename... _>
        constexpr int_ max_impl(int_ head, _... tail) {
            return void(std::initializer_list<int_>{
                (head = (tail > head) ? tail : head)...
            }), head;
        }

        template<int_... ns>
        struct _max<number<ns>...>
        {
            template<typename... _>
            using type = number<max_impl((void(sizeof...(_)), ns)...)>;
        };
#endif
    }
    /// \endcond
}

#endif
