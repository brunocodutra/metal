// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_CORE_INHERIT_HPP
#define METAL_CORE_INHERIT_HPP

namespace metal
{
    /// \ingroup core
    /// \brief ...
    template<typename... all>
    struct inherit :
            all...
    {};
}

#endif

