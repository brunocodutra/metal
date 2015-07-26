// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_PROTECT_HPP
#define METAL_FUNCTIONAL_PROTECT_HPP

namespace metal
{
    namespace detail
    {
        template<typename, int = 0>
        struct lambda
        {
            using type = lambda;
        };
    }
    /// \ingroup functional
    /// \brief ...
    template<typename value>
    struct protect;

    /// \ingroup functional
    /// \brief Eager adaptor for \ref protect.
    template<typename value>
    using protect_t = typename metal::protect<value>::type;

    template<typename value>
    struct protect
    {
        using type = detail::lambda<value>;
    };
}
#endif
