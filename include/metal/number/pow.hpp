#ifndef METAL_NUMBER_POW_HPP
#define METAL_NUMBER_POW_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../number/number.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class base, class exp, class ret = number<1>>
        struct _pow;

        template<class base, class exp>
        using pow = typename _pow<base, exp>::type;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the arithmetic exponentiation of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::pow<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \pre: `metal::pow<num_0, ..., num_m-1> != metal::number<0>` for all
    /// negative `num_m`
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} ** ... ** num_n-1{}>;
    ///     \endcode
    ///     Where `x**y` stands for `x` raised to the power of `y`
    ///     \warning{
    ///         `x**y` is always null for `y < 0` and `|x| > 1`
    ///         due to inherent limitations of integer arithmetic.
    ///     }
    ///
    /// ### Example
    /// \snippet number.cpp pow
    ///
    /// ### See Also
    /// \see number, abs, inc, dec, neg, add, sub, mul, div, mod
    template<class... nums>
    using pow = fold_left<lambda<detail::pow>, nums..., number<1>>;

    /// \cond
    namespace detail {
        template<class base, class exp, class ret>
        struct _pow {};

        template<int_ b, int_ e, int_ r>
        struct _pow<number<b>, number<e>, number<r>>
            : _pow<number<b * b>, number<e / 2>, number<(e % 2 ? b * r : r)>> {
        };

        template<int_ b, int_ r>
        struct _pow<number<b>, number<0>, number<r>> : number<1> {};

        template<int_ b, int_ r>
        struct _pow<number<b>, number<1>, number<r>> : number<b * r> {};

        template<int_ b, int_ r>
        struct _pow<number<b>, number<-1>, number<r>> : number<1 / (b * r)> {};

        template<int_ r>
        struct _pow<number<0>, number<-1>, number<r>> {};
    }
    /// \endcond
}

#endif
