// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_CONFIG_CONFIG_HPP
#define METAL_CONFIG_CONFIG_HPP

/// \ingroup config
/// When this preprocessor switch is defined, certain language features that
/// are known to cause problems to some compilers are avoided.
///
/// \warning{
///     Defining this preprocessor switch may lead to longer compilation times.
/// }
///
/// \note{
///     This preprocessor switch is currently defined by default for all
///     versions of Microsoft Visual Studio.
/// }
#if defined(METAL_DOXYGENATING) || \
    (!defined(METAL_COMPAT_MODE) && defined(_MSC_VER) && !defined(__clang__))
#   define METAL_COMPAT_MODE
#endif

#if defined(_MSC_VER) && !defined(__clang__)
#   define METAL_WARNING(MSG) __pragma(message("warning: "MSG))
#else
#   define METAL_WARNING_IMPL(MSG) _Pragma(#MSG)
#   define METAL_WARNING(MSG) METAL_WARNING_IMPL(GCC warning MSG)
#endif

#if (defined(_MSC_VER) && (_MSC_VER < 1900) && !defined(__clang__)) || \
    (!defined(_MSC_VER) && (__cplusplus < 201402L))
    METAL_WARNING("your compiler does not appear to support C++14 properly")
#endif

#endif
