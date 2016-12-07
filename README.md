# Metal - Metaprogramming Algorithms

[![version]][semver]
[![travis.badge]][travis.metal]
[![appveyor.badge]][appveyor.metal]

Metal is a header-only C++14 library designed to make metaprogramming easy.

* **Portable** - compatible with the [most popular compilers][portability].
* **Blazing fast** - browse up to date benchmarks at [metaben.ch].
* **Trivial integration** - `#include <metal.hpp>` and start enjoying
metaprogramming right away.
* **Metaprogramming made easy** - it doesn't have to be hard, check out
[the examples][examples].
* **SFINAE-Friendly** - [control overload resolution][SFINAE] and unleash the
power of function templates.

## Documentation

The complete up to date documentation is available [online][documentation].

Alternatively, an offline copy may be obtained by either cloning the branch
`gh-pages`

    git clone https://github.com/brunocodutra/metal.git --branch=gh-pages doc/html

or locally building the target `doc` ([CMake] and [Doxygen] required)

    cmake /path/to/Metal
    cmake --build . --target doc

Then open `doc/html/index.html` on your favourite web browser.

## License

Metal is distributed under the
[Boost Software License, Version 1.0][boost.license].

[version]:          http://badge.fury.io/gh/brunocodutra%2Fmetal.svg
[semver]:           http://semver.org

[travis.metal]:     http://travis-ci.org/brunocodutra/metal
[travis.badge]:     http://travis-ci.org/brunocodutra/metal.svg?branch=master

[appveyor.metal]:   http://ci.appveyor.com/project/brunocodutra/metal
[appveyor.badge]:   http://ci.appveyor.com/api/projects/status/85pk8n05n4r5x103/branch/master?svg=true

[boost.license]:    http://boost.org/LICENSE_1_0.txt

[CMake]:            http://cmake.org/
[Doxygen]:          http://doxygen.org/
[metaben.ch]:       http://metaben.ch/

[documentation]:    http://brunocodutra.github.io/metal
[portability]:      http://brunocodutra.github.io/metal/#supported_compilers
[examples]:         http://brunocodutra.github.io/metal/#examples
[SFINAE]:           http://brunocodutra.github.io/metal/#SFINAE
