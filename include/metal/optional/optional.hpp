// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_OPTIONAL_HPP
#define METAL_OPTIONAL_OPTIONAL_HPP

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename opt>
    struct optional;
}

#include<metal/lambda/invoke.hpp>
#include<metal/lambda/lambda.hpp>

namespace metal
{
    namespace detail
    {
        template<typename opt>
        using identity = opt;
    }

    template<typename opt>
    struct optional :
        invoke<lambda<detail::identity>, opt>
    {};
}

#endif
