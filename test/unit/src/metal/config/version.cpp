// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#if EXPECTED_METAL_MAJOR != METAL_MAJOR
#error major version mismatch!
#endif

#if EXPECTED_METAL_MINOR != METAL_MINOR
#error minor version mismatch!
#endif

#if EXPECTED_METAL_PATCH != METAL_PATCH
#error patch version mismatch!
#endif

#define EXPECTED_METAL_VERSION METAL_SEMVER( \
    EXPECTED_METAL_MAJOR, \
    EXPECTED_METAL_MINOR, \
    EXPECTED_METAL_PATCH \
)

#if EXPECTED_METAL_VERSION != METAL_VERSION
#error semantic version mismatch!
#endif

int main() {
    return 0;
}
