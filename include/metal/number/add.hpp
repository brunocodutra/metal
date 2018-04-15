#ifndef METAL_NUMBER_ADD_HPP
#define METAL_NUMBER_ADD_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../number/number.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename x, typename y>
        struct _add;

        template<typename x, typename y>
        using add = typename _add<x, y>::type;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the arithmetic addition of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::add<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} + ... + num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp add
    ///
    /// ### See Also
    /// \see number, abs, inc, dec, neg, sub, mul, div, mod, pow
    template<typename... nums>
    using add = fold_left<lambda<detail::add>, nums..., number<0>>;

    /// \cond
    namespace detail {
        template<typename x, typename y>
        struct _add {};

        template<int_ x, int_ y>
        struct _add<number<x>, number<y>> {
            using type = number<x + y>;
        };
    }
    /// \endcond
}

#endif
