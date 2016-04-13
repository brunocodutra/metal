# Metal - Metaprogramming Algorithms

[![version]][semver]
[![travis.badge]][travis.metal]
[![appveyor.badge]][appveyor.metal]

Metal is a general-purpose C++14 template metaprogramming library
designed to make metaprogramming enjoyable.

## Documentation

Documentation is available online at http://brunocodutra.github.io/metal.
Alternatively, an offline copy may be obtained by either
cloning the branch `gh-pages`

    git clone https://github.com/brunocodutra/metal.git --branch=gh-pages doc/html

or locally building the target `doc` ([CMake] and [Doxygen] required)

    cmake /path/to/Metal
    cmake --build . --target doc

In both cases, the same documentation website that is available online will be
placed into `doc/html/`.

## Portability

Metal has no dependencies other than the standard C++ library,
so any compiler that supports C++14 should be able to handle it just fine.
Nevertheless, Metal is continuously and automatically tested upon every commit
against some of the most popular freely available compilers.
Please visit http://brunocodutra.github.io/metal/index.html#portability for
more information.

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
