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
