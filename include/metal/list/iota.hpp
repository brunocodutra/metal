#ifndef METAL_NUMBER_IOTA_HPP
#define METAL_NUMBER_IOTA_HPP

#include "../config.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class, class, class>
        struct _iota;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Generates a sequence of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `st`, `sz` and `sd`
    /// \code
    ///     using result = metal::iota<st, sz, sd>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `sz` is positive, then
    ///     \code
    ///         using result = metal::numbers<
    ///             st{}, st{} + sd{}, ..., st{} + (sz{} - 1)*sd{}
    ///         >;
    ///     \endcode
    ///     otherwise, if `sz` is negative, then
    ///     \code
    ///         using result = metal::numbers<
    ///             st{}, st{} - sd{}, ..., st{} - (1 - sz{})*sd{}
    ///         >;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::numbers<>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp iota
    ///
    /// ### See Also
    /// \see list, repeat, numbers
    template<class start, class size, class stride = number<1>>
    using iota = typename detail::_iota<start, size, stride>::type;
}

#include "../list/list.hpp"
#include "../number/if.hpp"
#include "../number/numbers.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<int_... ns>
        struct enumeration {};

        template<class ns>
        struct _even {};

        template<int_... ns>
        struct _even<enumeration<ns...>> {
            using type = enumeration<ns..., (sizeof...(ns) + ns)...>;
        };

        template<class ns>
        struct _odd {};

        template<int_... ns>
        struct _odd<enumeration<ns...>> {
            using type =
                enumeration<ns..., (sizeof...(ns) + ns)..., 2 * sizeof...(ns)>;
        };

        template<int_ n>
        struct _enumerate;

        template<int_ n>
        using enumerate = typename _enumerate<n>::type;

        template<int_ n>
        struct _enumerate
            : if_<number<n % 2>, _odd<enumerate<n / 2>>,
                  _even<enumerate<n / 2>>> {};

        template<>
        struct _enumerate<0> {
            using type = enumeration<>;
        };

        template<class, int_ a, int_ b>
        struct _iota_impl {};

        template<int_... vs, int_ a, int_ b>
        struct _iota_impl<enumeration<vs...>, a, b> {
            using type = numbers<(b + a * vs)...>;
        };

        template<class, class, class>
        struct _iota {};

        template<int_ st, int_ sz, int_ sd>
        struct _iota<number<st>, number<sz>, number<sd>>
            : _iota_impl<
                  enumerate<(sz < 0) ? (0 - sz) : sz>, (sz < 0) ? (0 - sd) : sd,
                  st> {};
    }
    /// \endcond
}

#endif
