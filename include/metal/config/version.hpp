// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_CONFIG_VERSION_HPP
#define METAL_CONFIG_VERSION_HPP

/// \ingroup config
///
/// ### Description
/// Expands to the major version of Metal.
///
/// ### See Also
/// \see [Semantic Versioning](http://semver.org/)
#define METAL_MAJOR 0

/// \ingroup config
///
/// ### Description
/// Expands to the minor version of Metal.
///
/// ### See Also
/// \see [Semantic Versioning](http://semver.org/)
#define METAL_MINOR 7

/// \ingroup config
///
/// ### Description
/// Expands to the patch version of Metal.
///
/// ### See Also
/// \see [Semantic Versioning](http://semver.org/)
#define METAL_PATCH 0

/// \ingroup config
/// \hideinitializer
///
/// ### Description
/// Given a `{major, minor, patch}` triple, expands to an implementation defined
/// integral constant that is guaranteed to be comparable according to
/// [Semantic Versioning](http://semver.org/) rules.
///
/// ### See Also
/// \see [Semantic Versioning](http://semver.org/)
#define METAL_SEMVER(MAJOR, MINOR, PATCH) \
    (((MAJOR)*1000000) + ((MINOR)*10000) + (PATCH))

/// \ingroup config
/// Expands to the full version of Metal.
///
/// ### See Also
/// \see [Semantic Versioning](http://semver.org/)
#define METAL_VERSION METAL_SEMVER(METAL_MAJOR, METAL_MINOR, METAL_PATCH)

#endif
