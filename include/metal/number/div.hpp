#ifndef METAL_NUMBER_DIV_HPP
#define METAL_NUMBER_DIV_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../number/number.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class x, class y>
        struct _div;

        template<class x, class y>
        using div = typename _div<x, y>::type;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the quotient of the arithmetic division of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::div<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \pre: All \numbers in `num_1, ..., num_n-1` are nonzero
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} / ... / num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp div
    ///
    /// ### See Also
    /// \see number, abs, inc, dec, neg, add, sub, mul, mod, pow
    template<class... nums>
    using div = fold_left<lambda<detail::div>, nums..., number<1>>;

    /// \cond
    namespace detail {
        template<class x, class y>
        struct _div {};

        template<int_ x>
        struct _div<number<x>, number<0>> {};

        template<int_ x, int_ y>
        struct _div<number<x>, number<y>> {
            using type = number<x / y>;
        };
    }
    /// \endcond
}

#endif
