// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_IOTA_HPP
#define METAL_NUMBER_IOTA_HPP

#include <metal/config.hpp>

#include <metal/number/number.hpp>

namespace metal {
    /// \cond
    namespace detail {
        template<typename, typename, typename>
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
    /// \see numbers
    template<typename start, typename size, typename stride = number<1>>
    using iota = typename detail::_iota<start, size, stride>::type;
}

#include <metal/list/list.hpp>
#include <metal/number/if.hpp>
#include <metal/number/numbers.hpp>

#if defined(__has_builtin)
#   if __has_builtin(__make_integer_seq)
#       define METAL_USE_BUILTIN_MAKE_INTEGER_SEQ
#   endif
#endif

namespace metal {
    /// \cond
    namespace detail {
        template<int_... ns>
        struct enumeration
        {};

#if defined(METAL_USE_BUILTIN_MAKE_INTEGER_SEQ)
        template<typename int_, int_... ns>
        using enumerator = enumeration<ns...>;

        template<int_ n>
        using enumerate = __make_integer_seq<enumerator, int_, n>;
#else
        template<typename ns>
        struct _even
        {};

        template<int_... ns>
        struct _even<enumeration<ns...>>
        {
            using type = enumeration<ns..., (sizeof...(ns) + ns)...>;
        };

        template<typename ns>
        struct _odd
        {};

        template<int_... ns>
        struct _odd<enumeration<ns...>>
        {
            using type =
                enumeration<ns..., (sizeof...(ns) + ns)..., 2*sizeof...(ns)>;
        };

        template<int_ n>
        struct _enumerate;

        template<int_ n>
        using enumerate = typename _enumerate<n>::type;

        template<int_ n>
        struct _enumerate :
            if_<number<n%2>, _odd<enumerate<n/2>>, _even<enumerate<n/2>>>
        {};

        template<>
        struct _enumerate<0>
        {
            using type = enumeration<>;
        };
#endif
        template<typename, int_ a, int_ b>
        struct _iota_impl
        {};

        template<int_... vs, int_ a, int_ b>
        struct _iota_impl<enumeration<vs...>, a, b>
        {
            using type = numbers<(b + a*vs)...>;
        };

        template<typename, typename, typename>
        struct _iota
        {};

        template<int_ st, int_ sz, int_ sd>
        struct _iota<number<st>, number<sz>, number<sd>> :
            _iota_impl<
                enumerate<(sz < 0) ? (0 - sz) : sz>,
                (sz < 0) ? (0 - sd) : sd,
                st
            >
        {};
    }
    /// \endcond
}

#endif
