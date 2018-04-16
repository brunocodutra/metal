#ifndef METAL_NUMBER_IF_HPP
#define METAL_NUMBER_IF_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename cond>
        struct _if_;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// A conditional expression.
    ///
    /// ### Usage
    /// For any \number `num` and \values `x, y`
    /// \code
    ///     using result = metal::if<num, x, y>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `num{} != false`, then
    ///     \code
    ///         using result = x;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = y;
    ///     \endcode
    ///
    /// \tip{If `num{} != false`, `y` may be omitted.}
    ///
    /// ### Example
    /// \snippet number.cpp if_
    ///
    /// ### See Also
    /// \see number
    template<typename cond, typename... then>
    using if_ = detail::call<detail::_if_<cond>::template type, then...>;
}

#include "../number/number.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename>
        struct _if_ {};

        template<int_ v>
        struct _if_<number<v>> {
            template<typename val, typename = void>
            using type = val;
        };

        template<>
        struct _if_<false_> {
            template<typename, typename val>
            using type = val;
        };
    }
    /// \endcond
}

#endif
