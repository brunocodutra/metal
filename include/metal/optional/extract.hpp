// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_EXTRACT_HPP
#define METAL_OPTIONAL_EXTRACT_HPP

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename opt>
    using extract = typename opt::type;
}

#endif
