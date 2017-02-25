// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_CONFIG_CONFIG_HPP
#define METAL_CONFIG_CONFIG_HPP

/// \ingroup config
///
/// ### Description
/// When this preprocessor switch is defined, certain language features that
/// are known to cause problems to some compilers are avoided.
///
/// \warning{
///     Defining this preprocessor switch may lead to longer compilation times.
/// }
///
/// \note{
///     This preprocessor switch is currently defined by default for all
///     versions of Microsoft Visual Studio and GCC < 5.
/// }
#if !defined(METAL_COMPAT_MODE)
#   if defined(METAL_DOXYGENATING) \
        || (__GNUC__ < 5) \
        || (defined(_MSC_VER) && !defined(__clang__))
#       define METAL_COMPAT_MODE
#   endif
#endif

#endif
