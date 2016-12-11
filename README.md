# Metal - Metaprogramming Algorithms

[![version]][semver]
[![travis.badge]][travis.metal]
[![appveyor.badge]][appveyor.metal]

Metal is a header-only C++14 library designed to make metaprogramming easy.

* **Portable** - compatible with the
[most popular compilers](#supported-compilers).
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

## Supported Compilers

The following compilers are tested in continuous integration using
[Travis CI][travis.metal] and [Appveyor CI][appveyor.metal].

| Compiler          | Version   | Operating System
|-------------------|-----------|-----------------------
| GCC               | 5         | Ubuntu 14.04 LTS
| GCC               | 6         | Ubuntu 14.04 LTS
| Clang             | 3.4       | Ubuntu 14.04 LTS
| Clang             | 3.5       | Ubuntu 14.04 LTS
| Clang             | 3.6       | Ubuntu 14.04 LTS
| Clang             | 3.7       | Ubuntu 14.04 LTS
| Clang             | 3.8       | Ubuntu 14.04 LTS
| Clang             | 3.9       | Ubuntu 14.04 LTS
| Clang             | 4.0       | Ubuntu 14.04 LTS
| Xcode             | 6.4       | OS X 10.10
| Xcode             | 7.3       | OS X 10.11
| Xcode             | 8.0       | OS X 10.11
| Xcode             | 8.1       | OS X 10.12
| Xcode             | 8.2       | OS X 10.12
| Visual Studio     | 14 (2015) | Windows Server 2012 R2

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
[examples]:         http://brunocodutra.github.io/metal/#examples
[SFINAE]:           http://brunocodutra.github.io/metal/#SFINAE
