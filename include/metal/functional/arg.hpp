// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_ARG_HPP
#define METAL_FUNCTIONAL_ARG_HPP

#include <cstddef>

namespace metal
{
    /// \ingroup functional
    /// \brief ...
    template<std::size_t n>
    struct arg
    {};

    /// \defgroup placeholders Placeholders
    /// \ingroup functional
    /// \brief Default placeholders for arguments to lambdas.

    /// \ingroup placeholders
    /// \brief Default placeholder.
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
