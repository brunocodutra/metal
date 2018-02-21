// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_NUMBERS_HPP
#define METAL_NUMBER_NUMBERS_HPP

#include "../config.hpp"
#include "../list/list.hpp"
#include "../number/number.hpp"

#include <type_traits>

namespace metal {
    /// \cond
    namespace detail {
#if defined(METAL_WORKAROUND)
        template<int_... vs>
        struct _numbers;
#endif
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Constructs a \list of \numbers out of a sequence of integral values.
    ///
    /// ### Example
    /// \snippet number.cpp numbers
    ///
    /// ### See Also
    /// \see int_, number, list
    template<int_... vs>
    using numbers =
#if defined(METAL_WORKAROUND)
        typename detail::_numbers<vs...>::type;
#else
        metal::list<metal::number<vs>...>;
#endif

    /// \cond
    namespace detail {
#if defined(METAL_WORKAROUND)
        template<int_... vs>
        struct _numbers {
            using type = list<std::integral_constant<int_, vs>...>;
        };
#endif
    }
    /// \endcond
}

#endif
