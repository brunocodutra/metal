# Metal [![version]][semver] [![travis.badge]][travis.metal] [![appveyor.badge]][appveyor.metal] [![gitter.badge]][gitter.metal] [![godbolt.badge]][godbolt.metal]

Metal is a single-header C++11 library designed to make you love template
metaprogramming.

## Overview

```.cpp
#include <metal.hpp>

// First we need some Values
union x { char payload[10]; };
class y { public: char c; };
struct z { char c; int i; };

// ... from which we construct some Lists
using l0 = metal::list<>;
using l1 = metal::prepend<l0, x>;
using l2 = metal::append<l1, z>;
using l3 = metal::insert<l2, metal::number<1>, y>;

static_assert(metal::same<l1, metal::list<x>>::value, "");
static_assert(metal::same<l2, metal::list<x, z>>::value, "");
static_assert(metal::same<l3, metal::list<x, y, z>>::value, "");

// Lists are versatile, we can check their sizes...
static_assert(metal::size<l0>::value == 0, "");
static_assert(metal::size<l1>::value == 1, "");
static_assert(metal::size<l2>::value == 2, "");
static_assert(metal::size<l3>::value == 3, "");

// retrieve their elements...
static_assert(metal::same<metal::front<l3>, x>::value, "");
static_assert(metal::same<metal::back<l3>, z>::value, "");
static_assert(metal::same<metal::at<l3, metal::number<1>>, y>::value, "");

// count those that satisfy a predicate...
static_assert(metal::count_if<l3, metal::trait<std::is_class>>::value == 2, "");
static_assert(metal::count_if<l3, metal::trait<std::is_union>>::value == 1, "");

// We can create new Lists by removing elements...
using l0_ = metal::drop<l3, metal::number<3>>;
using l1_ = metal::take<l3, metal::number<1>>;
using l2_ = metal::erase<l3, metal::number<1>>;

static_assert(metal::same<l0, l0_>::value, "");
static_assert(metal::same<l1, l1_>::value, "");
static_assert(metal::same<l2, l2_>::value, "");

// by reversing the order of elements...
static_assert(metal::same<metal::reverse<l0>, metal::list<>>::value, "");
static_assert(metal::same<metal::reverse<l1>, metal::list<x>>::value, "");
static_assert(metal::same<metal::reverse<l2>, metal::list<z, x>>::value, "");
static_assert(metal::same<metal::reverse<l3>, metal::list<z, y, x>>::value, "");

// by transforming the elements...
using l2ptrs = metal::transform<metal::lazy<std::add_pointer>, l2>;
using l3refs = metal::transform<metal::lazy<std::add_lvalue_reference>, l3>;

static_assert(metal::same<l2ptrs, metal::list<x*, z*>>::value, "");
static_assert(metal::same<l3refs, metal::list<x&, y&, z&>>::value, "");

// even by sorting them...
template<class x, class y>
using smaller = metal::number<(sizeof(x) < sizeof(y))>;

using sorted = metal::sort<l3, metal::lambda<smaller>>;

static_assert(metal::same<sorted, metal::list<y, z, x>>::value, "");

// that and much more!
```

## Quick Start

1. Download [metal.hpp][releases]
2. `#include </path/to/metal.hpp>`
3. Love template metaprogramming

## Blazingly Fast

You don't need to just take my word for it, see for yourself at [metaben.ch].

## Portable

Metal is continuously tested on [Travis CI][travis.metal] and [Appveyor CI][appveyor.metal].
It is known to work on GCC 4.7+, Clang 3.8+ and on the latest releases of Visual Studio and Xcode.

## Documentation

The complete up-to-date documentation is available [online][documentation].


## License

This project is licensed under the [MIT][license].

[version]:          http://badge.fury.io/gh/brunocodutra%2Fmetal.svg
[semver]:           http://semver.org

[godbolt.metal]:    https://godbolt.org/g/JN13FQ

[travis.metal]:     http://travis-ci.org/brunocodutra/metal
[travis.badge]:     http://travis-ci.org/brunocodutra/metal.svg?branch=master

[appveyor.metal]:   http://ci.appveyor.com/project/brunocodutra/metal
[appveyor.badge]:   http://ci.appveyor.com/api/projects/status/85pk8n05n4r5x103/branch/master?svg=true

[gitter.metal]:     http://gitter.im/brunocodutra/metal?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge
[gitter.badge]:     http://badges.gitter.im/brunocodutra/metal.svg

[godbolt.metal]:    http://godbolt.org/g/RFwvic
[godbolt.badge]:    http://img.shields.io/badge/try%20it-on%20godbolt-222266.svg

[CMake]:            http://cmake.org/
[Doxygen]:          http://doxygen.org/
[metaben.ch]:       http://metaben.ch/

[license]:          https://github.com/brunocodutra/metal/blob/master/LICENSE
[releases]:         http://github.com/brunocodutra/metal/releases
[documentation]:    http://brunocodutra.github.io/metal
[examples]:         http://brunocodutra.github.io/metal/#examples
[SFINAE]:           http://brunocodutra.github.io/metal/#SFINAE
