// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_ARG_HPP
#define METAL_LAMBDA_ARG_HPP

#include "../config.hpp"
#include <cstddef>

namespace metal {
    /// \cond
    namespace detail {
        template<std::size_t n>
        struct _arg;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// A parametric \lambda that selects the n-th argument it is invoked with.
    ///
    /// ### Usage
    /// For any non negative integral value `m`
    /// \code
    ///     using result = metal::arg<m>;
    /// \endcode
    ///
    /// \returns: \lambda
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::lambda<expr>;
    ///     \endcode
    ///     where `expr` is an \expression such that
    ///     `expr<val_0, ..., val_m, ..., val_n-1>` yields `val_m`.
    ///
    /// ### Example
    /// \snippet lambda.cpp arg
    ///
    /// ### See Also
    /// \see lambda, invoke, bind, always
    template<std::size_t n>
    using arg = typename detail::_arg<n>::type;
}

#include "../lambda/lambda.hpp"
#include "../list/at.hpp"
#include "../list/list.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<std::size_t n>
        struct _arg {
            template<typename... vals>
            using impl = at<list<vals...>, number<n - 1>>;

            using type = lambda<impl>;
        };

        template<>
        struct _arg<0U> {};
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// Predefined placeholder.
    /// \{
    using _1 = metal::arg<1U>;
    using _2 = metal::arg<2U>;
    using _3 = metal::arg<3U>;
    using _4 = metal::arg<4U>;
    using _5 = metal::arg<5U>;
    using _6 = metal::arg<6U>;
    using _7 = metal::arg<7U>;
    using _8 = metal::arg<8U>;
    using _9 = metal::arg<9U>;
    /// \}
}

#endif
