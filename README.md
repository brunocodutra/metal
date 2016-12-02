# Metal - Metaprogramming Algorithms

[![version]][semver]
[![travis.badge]][travis.metal]
[![appveyor.badge]][appveyor.metal]

Metal is a portable header-only C++14 library designed to make template
metaprogramming enjoyable.

## TL;DR

For a quick get going, be sure to check out
[Metal in Action](http://brunocodutra.github.io/metal/#metal_in_action).

## Benchmarks

See Metal in comparison with other modern metaprogramming libraries at
[Metabench].

## Supported Compilers

The following compilers are currently tested in continuous integration at
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
| Visual Studio     | 14 2015   | Windows Server 2012 R2

## Documentation

The complete up to date documentation is available
[online](http://brunocodutra.github.io/metal).

Alternatively, an offline copy may be obtained by either cloning the branch
`gh-pages`

    git clone https://github.com/brunocodutra/metal.git --branch=gh-pages doc/html

or locally building the target `doc` ([CMake] and [Doxygen] required)

    cmake /path/to/Metal
    cmake --build . --target doc

In both cases, the same documentation website that is available online will be
placed into `doc/html/`.

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
[Metabench]:        http://brunocodutra.github.io/metabench
