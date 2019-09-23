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
    /// For any nonzero positive integral value `n`
    /// \code
    ///     using result = metal::arg<n>;
    /// \endcode
    ///
    /// \returns: \lambda
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::lambda<expr>;
    ///     \endcode
    ///     where `expr` is an \expression such that
    ///     `expr<val_0, ..., val_n-1, ..., val_m-1>` yields `val_n-1`.
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
