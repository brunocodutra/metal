#ifndef METAL_NUMBER_MOD_HPP
#define METAL_NUMBER_MOD_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../number/if.hpp"
#include "../number/number.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename x, typename y>
        struct _mod;

        template<typename x, typename y>
        using mod = typename _mod<x, y>::type;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the remainder of the arithmetic division of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::mod<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \pre: All \numbers in `num_1, ..., num_n-1` are nonzero
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} % ... % num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp mod
    ///
    /// ### See Also
    /// \see number, abs, inc, dec, neg, add, sub, mul, div, pow
    template<typename... nums>
    using mod = fold_left<lambda<detail::mod>, if_<is_number<nums>, nums>...>;

    /// \cond
    namespace detail {
        template<typename x, typename y>
        struct _mod {};

        template<int_ x>
        struct _mod<number<x>, number<0>> {};

        template<int_ x, int_ y>
        struct _mod<number<x>, number<y>> {
            using type = number<x % y>;
        };
    }
    /// \endcond
}

#endif
