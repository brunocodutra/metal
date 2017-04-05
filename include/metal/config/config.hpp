// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_CONFIG_CONFIG_HPP
#define METAL_CONFIG_CONFIG_HPP

#if !defined(METAL_WORKAROUND)
#   if (defined(__GNUC__) && !defined(__clang__) && (__GNUC__ < 5)) \
    || (defined(_MSC_VER) && !defined(__clang__))
#       define METAL_WORKAROUND
#   endif
#endif

#endif
