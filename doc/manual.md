# Introduction {#mainpage}

\tableofcontents

Metal is a [portable](#portability) header-only [C++14] library
designed to make [template metaprogramming][tmp] enjoyable.
It provides a powerful high-level [abstraction](#concepts) for compile-time
algorithms that mimic the [standard algorithms library][algorithm],
hence **Metal** - <b>Meta</b>programming <b>Al</b>gorithms.

Motivation {#motivation}
================================================================================

Metaprogramming is far from a novelty in the C family,
in fact it has been part of everyday C programming since the early days
through the [preprocessor].
In C++, it was taken to a whole new level with the development of
[template metaprogramming][tmp], a technique that exploits the
template system to perform computations during compilation time.
Contrary to the C preprocessor, it has long been noticed that
[C++ templates are indeed Turing complete][tmp.turing],
thus consolidating template metaprogramming as the standard idiom for
compile time computations in C++.

In March of 2003 the [Boost Metaprogramming Library (MPL)][Boost.MPL],
by Aleksey Gurtovoy and David Abrahams,
is officially shipped with Boost version 1.30.0.
A masterpiece of template metaprogramming,
it went to great lengths to support the
widest variety of poorly conforming compilers,
abstracting away the nastiest compiler hackery to present a uniform
framework that finally could be relied upon,
thus playing a crucial role in the dissemination of metaprogramming in C++.
The Boost.MPL remained undisputed for almost a decade, but
eventually, it started showing its age when [C++11] introduced,
among various others,
[variadic templates][variadics], [alias templates], [type inference][decltype]
and [constant expressions][constexpr] to the core language.
The powerful C++11 machinery enabled the development of whole new
metaprogramming [styles][tmp.simple] and [techniques][tmp.modern] with
potential to outperform Boost.MPL by orders of magnitude in many instances.
Moreover, the need for endless automatically generated boilerplate code could
finally be overcome using variadic templates,
whereas syntax clutter could be mitigated using alias templates,
vastly improving readability.

Eventually, [motivation][mpl.lite] to modernize Boost.MPL emerged from the Boost
community, even though opinions diverged widely on the matter.
As diverse has been the development of new metaprogramming libraries
with varying degrees of success,
most notably [Meta], [Brigand] and [Boost.Hana],
the latter formally accepted into the Boost distribution in July 2015.

Metal is yet another approach to modern metaprogramming.
Its ultimate goal is to be regarded as the natural successor of Boost.MPL in
every use case where C++14 is available,
delivering greater performance and expressiveness without
cluttering the codebase.
Although not a perfect drop in replacement for Boost.MPL,
Metal follows very similar design principles,
except that they have been fine tuned to take advantage of C++14,
so migration is meant to be the smoothest possible.

Getting Started {#getting_started}
================================================================================

Downloading {#downloading}
--------------------------------------------------------------------------------

There are a few ways to get a copy of Metal,
the easiest might be to simply
<a class="download" href="">download the latest release</a>
as a compressed package.

If you have git installed and would rather have the latest stable Metal,
you may consider cloning branch `master` from GitHub.

    git clone https://github.com/brunocodutra/metal

Likewise, the bleeding edge development version can be obtained by cloning
branch `develop` instead.

    git clone https://github.com/brunocodutra/metal --branch=develop

\note{
    During development it is possible that branch `develop` breaks temporarily.
    Be sure to check current compilation [status](#status) prior to cloning.
}

Installing {#installing}
--------------------------------------------------------------------------------

Metal may optionally be installed system-wide to ease integration with external
projects. If you'd rather use Metal locally, you may skip to the
[next section](#using_metal).

Make sure to have [CMake] v3.0 or newer installed on your system, then,
from within an empty directory, issue the following commands.

    cmake /path/to/Metal
    cmake --build . --target install

At this point Metal's include tree will be copied into
`/usr/local/include` on Unix[-like] systems and `C:\Program Files\Metal\include`
on Windows.


Using Metal {#using_metal}
--------------------------------------------------------------------------------

To start enjoying metaprogramming, all you need is your compiler to find Metal's
include tree.

If you chose to [install Metal system-wide](#installing),
make sure the installation prefix is looked up by your compiler.
In case you use [CMake] to automate building your projects, it should suffice to
add the following to the `CMakeLists.txt`.

    find_package(Metal REQUIRED)
    include_directories(${METAL_INCLUDE_DIRS})

Otherwise, to use your local copy of Metal, make sure to add its `include/`
sub-directory to the include search paths of your project.

\note{
    Some compilers require special flags in order to enable support for C++14,
    please refer to your compiler's documentation for specific instructions.
}

\tip{
    If you use CMake 3.1 or newer, support for C++14 may be conveniently enabled
    by simply issuing `set(CMAKE_CXX_STANDARD 14)` prior to adding any targets.
}

Documentation {#documentation}
--------------------------------------------------------------------------------

An offline copy of this documentation may be obtained by cloning branch
`gh-pages`.

    git clone https://github.com/brunocodutra/metal --branch=gh-pages

Alternatively, if you have [CMake] and [Doxygen] installed,
the documentation may also be built locally.
From within an empty directory issue the following commands.

    cmake /path/to/Metal
    cmake --build . --target doc

The documentation will be generated into `doc/html/`.

To browse the documentation offline,
simply load `index.html` on any web browser that supports [JavaScript].

Project Organization {#project_organization}
--------------------------------------------------------------------------------

Metal is designed to be fine grained and intuitive. Header files define a single
algorithm each, after which they are named, and are semantically organized
within directories that represent modules. For convenience, along each directory
one also finds a homonimous header file that includes everything therein, that
is, every header file pertaining to that module. The complete hierarchy of
modules and their header files is available on
[Metal's GitHub repository][Metal.headers].

Each module is named after a [concept](#concepts) and contains algorithms that
operate on models of that concept. The complete reference documentation for the
modules and their algorithms is available in section [Reference](modules.html).

\warning{
    Header files within `detail/` are undocumented and should be expected to
    undergo breaking changes without prior notice. Directly depending on these
    header files or, likewise, on any name that is defined within
    `namespace metal::detail` is strongly discouraged.
}

Portability {#portability}
================================================================================

Great effort is undertaken to keep Metal strictly in conformance with the C++14
standard and compatible with the widest possible variety of compilers.
To this end, some of the most popular freely available C++ compilers are
actively supported through [Continuous Integration (CI)][ci] premisses.
GCC and Clang are tested with help of [Travis CI][travis.metal],
while Microsoft Visual Studio is tested using [Appveyor CI][appveyor.metal].

Current Status {#status}
--------------------------------------------------------------------------------

Current compilation status is summarized in the table bellow,
if your favorite compiler is not included, please [let us know][Metal.issues].

<table>
    <tr>
        <th rowspan="2">Compiler</th>
        <th rowspan="2" class="hidden-xs">Minimum Version</th>
        <th colspan="2">Branch</th>
    </tr>
    <tr>
        <th>Master</th>
        <th>Develop</th>
    </tr>

    <tr>
        <th>GCC</th>
        <td class="hidden-xs">5</td>
        <td rowspan="2">![travis.master]</td>
        <td rowspan="2">![travis.develop]</td>
    </tr>
    <tr>
        <th>Clang</th>
        <td class="hidden-xs">3.4</td>
    </tr>
    <tr>
        <th>MSVC</th>
        <td class="hidden-xs">14 (2015)</td>
        <td>![appveyor.master]</td>
        <td>![appveyor.develop]</td>
    </tr>
</table>

\note{
    Status badges are updated live to reflect current status as reported by the
    continuous integration tools. If they don't load correctly that
    might be due to a temporary network downtime.
}

Benchmarks {#benchmarks}
================================================================================

To make sure Metal does not slow compilation times even when manipulating
hundreds or even thousands of types at a time, a comprehensive set of benchmarks
has been set up at [Metabench] to help keeping track of Metal's performance
against some of the most popular metaprogramming libraries available out there.
Benchmark results are updated nightly for various supported compilers and should
reflect the performance delivered by Metal at branch `master`.

Concepts {#concepts}
================================================================================

Template metaprogramming can be seen as a language of its own right,
sharing the same syntax with C++, but having different semantics.
Because constructs assume different meanings during template metaprogramming
from what they usually mean in an actual C++ context, some key concepts must be
defined.

Value {#value}
--------------------------------------------------------------------------------

[Values] are the objects of metaprogramming.

### Requirements

Any type is a [Value].

### Examples

\snippet value.cpp val1
\snippet value.cpp val2
\snippet value.cpp val3

### Counterexamples

\snippet value.cpp not_a_val1
\snippet value.cpp not_a_val2
\snippet value.cpp not_a_val3

Number {#number}
--------------------------------------------------------------------------------

A [Number] is a compile-time representation of a numerical value.

### Requirements

`num` is a model of [Number] if and only if `num` is a specialization of
`metal::number`.

\note{
    `metal::number<n>` is guaranteed to be an alias template to
    `std::integral_constant<metal::int_, n>`.
}

### Examples

\snippet number.cpp num1
\snippet number.cpp num2
\snippet number.cpp num3

### Counterexamples

\snippet number.cpp not_a_num1

### See Also

metal::number, metal::int_

Expression {#expression}
--------------------------------------------------------------------------------

[Expressions], also called *metafunctions*, are mappings over the set of
[Values].

### Requirements

`expr` is a model of [Expression] if and only if `expr` is a
class, union or alias template that only expects [Values] as arguments.

### Examples

\snippet expression.cpp  expr1
\snippet expression.cpp  expr2

### Counterexamples

\snippet expression.cpp not_an_expr1
\snippet expression.cpp not_an_expr2

Lambda {#lambda}
--------------------------------------------------------------------------------

[Lambdas], short for *Lambda Expressions*, are [first-class][first-class]
[Expressions]. As [Values] themselves, [Lambdas] can serve both as argument as
well as return value to other [Expressions] and [Lambdas],
thus enabling [higher-order] composition.

### Requirements

`lbd` is a model of [Lambda] if and only if `lbd` is a specialization of
`metal::lambda`.

### Examples

\snippet lambda.cpp lbd1

### See Also

metal::lambda, metal::is_lambda

List {#list}
--------------------------------------------------------------------------------

A [List] is a sequence of [Values].

### Requirements

`list` is a model of [List] if and only if `list` is a specialization of
`metal::list`.

### Examples

\snippet list.cpp  list1
\snippet list.cpp  list2

### See Also

metal::list, metal::is_list

Pair {#pair}
--------------------------------------------------------------------------------

A [Pair] is a couple of [Values].

### Requirements

A [Pair] is any [List] whose size is 2.

### Examples

\snippet pair.cpp  pair1

### See Also

metal::pair, metal::is_pair, metal::first, metal::second

Map {#map}
--------------------------------------------------------------------------------

A [Map] is a collection of unique [Values], each of which associated with
another [Value].

### Requirements

A [Map] is a [List] of [Pairs], whose first elements are all distinct, that is

    [[k0, v0], ..., [kn, vn]]; ki != kj for all i, j in {0, n} and i != j

### Examples

\snippet map.cpp  map1
\snippet map.cpp  map2

### Counterexamples

\snippet map.cpp not_a_map1
\snippet map.cpp not_a_map2

### See Also

metal::map, metal::is_map, metal::keys, metal::values

A Word on SFINAE-Friendliness {#SFINAE}
================================================================================

An [Expression] is said to be SFINAE-friendly when it is carefully designed so
as never to prevent the [SFINAE] rule to be triggered. In general, such
[Expressions] may only trigger template substitution errors at the point of
instantiation of the *signature* of a type, which includes the instantiation of
alias templates and default template arguments.

SFINAE-friendly [Expressions] are exceedingly powerful, because they may be used
to drive overload resolution, much like [`std::enable_if`][enable_if] does.
For that reason all [Expressions] within `namespace metal` are guaranteed to be
themselves SFINAE-friendly.

\snippet sfinae.cpp SFINAE

Conversely, an SFINAE-unfriendly [Expression] produces so called *hard errors*,
which require the compilation to halt immediately. Examples of *hard errors*
are failed `static_assert`'ions or template substitution errors at the point of
instantiation of the nested members of a type.

SFINAE-unfriendly [Expressions] are very inconvenient, because they force
compilation to halt when they are not selected by overload resolution, thereby
hindering the usage of the entire overloaded set. For that reason
SFINAE-unfriendly [Expressions] should always be avoided.


Metal in Action {#metal_in_action}
================================================================================

Enough theory, let's get our hands dirty.

Parsing Raw Literals {#parsing_raw_literals}
--------------------------------------------------------------------------------

If you ever considered augmenting [`std::tuple`][tuple],
so that instead of the rather clunky [`std::get<N>()`][get]

\snippet literal.cpp teaser_1

one could just use the more intuitive subscript operator `[N]`

\strike{
\snippet literal.cpp teaser_2
}

you might have come up with something that looks pretty much like this

\strike{
\snippet literal.cpp naive_1
}

only to realize the hard way that this is simply not valid C++14.

> error: non-type template argument is not a constant expression

While the keyword `constexpr` tells the compiler the value returned by
`operator ""_c` *might* be a compile time constant, it tells no such thing
about its arguments, which may very well be unknown at compile-time.

So how can we convince the compiler that indices are always known at
compile-time? We refactor the subscript operator to take an instance of
`metal::number` instead.

\snippet literal.cpp augmented_tuple

Using template patern matching, we can extract the underlying value `i`, which
in this context is already a template argument and thus guaranteed to be known
at compile-time, so compilers have no reason to object to passing it on as
an argument to other template instantiations.

\snippet literal.cpp teaser_3

That looks promising, but then again isn't `metal::number<1>{}` just as clunky
as `std::get<1>()`? Yes. Absolutely.

That's where [literal operators][literal] shine.

\snippet literal.cpp teaser_4

We're are getting there, but how is `_c` implemented?

At a first glance it might be tempting to try something like this

\strike{
\snippet literal.cpp naive_2
}

but let us not forget why we're here to begin with, that is, recall we can't
instantiate a template using a non-`constexpr` variable as argument!

At this point, a watchful reader might argue that in theory there is no real
reason for this to be rejected, since the literal value must always be known at
compile-time and that makes a lot of sense indeed, but unfortunately that's just
not how it works. All is not lost however, because we can still parse raw
literals, which means we are in for some fun!

### The Raw Literal Operator Template

Raw literal operator templates in C++ are defined as a nullary constexpr
function templated over `char...`

\snippet literal.cpp _raw

where `cs...` are mapped to the exact characters that make up the literal,
including the prefixes `0x` and `0b`

\snippet literal.cpp _raw_ex1

as well as digit separators

\snippet literal.cpp _raw_ex2

### The `operator ""_c`

We start by defining the literal operator `_c` as a function that forwards the
raw literal characters as a [List] of [Numbers] to `parse_number` and returns a
default constructed object of whatever type it aliases to, which in this case
is guaranteed to be a [Number].

\snippet literal.cpp _c

### Resolving the Radix

In its turn `parse_number` strips the prefix, if any, thus resolving the radix,
then forwards the remaining characters to `parse_digits`, which is in charge of
translating the raw characters to the numerical values they represent.
The radix and digits are then forwarded to `assemble_number`, which adds up the
individual digits according to the radix.

\snippet literal.cpp parse_number

### Parsing Digits

To parse characters into their corresponding numerical value, we must first
remove all digit separators.
That can be easily accomplished using `metal::remove`, which takes a [List] `l`
and a [Value] `val` and returns another [List] that contains every element from
`l` and in the same order, except for those that are identical to `val`.

\snippet literal.cpp remove

The remaining characters can then be individually parsed with the help of
`metal::transform`, which takes a [Lambda] `lbd` and a [List] `l` and returns
another [List] containing the results of invoking `lbd` for each element in `l`.

    [lbd(l[0]), lbd(l[1]), ..., lbd(l[n-2]), lbd(l[n-1])]

\snippet literal.cpp parse_digit

\snippet literal.cpp transform

Notice how characters are translated into their actual numerical representation.

So there it is

\snippet literal.cpp parse_digits

### Assembling Numbers

We now turn our attention to `assemble_number`.
It takes the radix and a [List] of digits and is in charge of adding them up
according to the radix, that is

    D0*radix^(n-1) + D1*radix^(n-2) + ... + D{n-2}*radix + D{n-1}

The first thing we notice is that the *ith* digit actually corresponds to the
<em>(n-1-i)th</em> power of the radix.
To make things simpler, we really want to `metal::reverse` the order of digits.

\snippet literal.cpp reverse

so that it becomes

    D0 + D1*radix + ... + D{n-2}*radix^(n-2) + D{n-1}*radix^(n-1)

Next we need to `metal::enumerate` the exponents that correspond to each digit.

\snippet literal.cpp enumerate

This version of `metal::enumerate` takes two [Numbers], `start` and `size`,
and returns a [List] containing a sequence of [Numbers] beginning with `start`
and ending in `size - 1`.

    [start, start + 1, ..., size - 2, size - 1]

To compute each term of the sum, we'll be using `metal::transform` again,
but this time it takes a binary [Lambda] `lbd` and two [Lists] `l1` and `l2`
and returns a new [List] formed by invoking `lbd` for the elements of `l1` and
`l2` pairwise.

    [lbd(l1[0], l2[0]), lbd(l1[1], l2[1]), ..., lbd(l1[n-2], l2[n-2]), lbd(l1[n-1], l2[n-1])]

Here we need an [Lambda] that takes a digit and the corresponding radix exponent
and computes a term of the sum. Again we could define an [Expression] for that
specific purpose and construct a [Lambda] from it, much like we did for
`parse_digit`, but instead we'll be using *bind expressions* here.

\snippet literal.cpp zip

If *bind expressions* look scary to you, don't panic, we will cover [Expression]
composition in detail in our [next practical example](#church_booleans).
Here it suffices to know that *bind expressions* are themselves [Lambdas] and
that `metal::_1` and `metal::_2` are *placeholders* that get substituted by the
first and second arguments with which the *bind expression* is invoked prior to
the recursive evaluation of the [Expressions] that compose the
*bind expression*.

The final step is to sum up the terms, that is we need to invoke
`metal::add` for the elements contained in a [List].
That's where `metal::apply` comes into play.

\snippet literal.cpp sum

And there we have it

\snippet literal.cpp assemble_number

### Fun With `operator ""_c`

\snippet literal.cpp _c_ex1

It also works for very long binary literals.

\snippet literal.cpp _c_ex2

And ignores digit separators too.

\snippet literal.cpp _c_ex3

Church Booleans {#church_booleans}
--------------------------------------------------------------------------------

[TODO]

[Value]:            #value
[Values]:           #value
[Optional]:         #optional
[Optionals]:        #optional
[Number]:           #number
[Numbers]:          #number
[Boolean]:          #number
[Booleans]:         #number
[Expression]:       #expression
[Expressions]:      #expression
[Lambda]:           #lambda
[Lambdas]:          #lambda
[List]:             #list
[Lists]:            #list
[Pair]:             #pair
[Pairs]:            #pair
[Map]:              #map
[Maps]:             #map

[C++11]:            http://en.wikipedia.org/wiki/C%2B%2B11
[C++14]:            http://en.wikipedia.org/wiki/C%2B%2B14
[JavaScript]:       http://en.wikipedia.org/wiki/JavaScript
[higher-order]:     http://en.wikipedia.org/wiki/Higher-order_function
[first-class]:      http://en.wikipedia.org/wiki/First-class_citizen
[ci]:               http://en.wikipedia.org/wiki/Continuous_integration

[tmp]:              http://en.wikipedia.org/wiki/Template_metaprogramming
[tmp.turing]:       http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.14.3670
[tmp.simple]:       http://pdimov.com/cpp2/simple_cxx11_metaprogramming.html
[tmp.modern]:       http://pdimov.com/cpp2/simple_cxx11_metaprogramming_2.html

[algorithm]:        http://en.cppreference.com/w/cpp/algorithm
[preprocessor]:     http://en.wikipedia.org/wiki/C_preprocessor
[variadics]:        http://en.cppreference.com/w/cpp/language/parameter_pack
[alias templates]:  http://en.cppreference.com/w/cpp/language/type_alias
[decltype]:         http://en.cppreference.com/w/cpp/language/decltype
[constexpr]:        http://en.cppreference.com/w/cpp/language/constexpr
[tuple]:            http://en.cppreference.com/w/cpp/utility/tuple
[get]:              http://en.cppreference.com/w/cpp/utility/tuple/get
[enable_if]:        http://en.cppreference.com/w/cpp/types/enable_if
[literal]:          http://en.cppreference.com/w/cpp/language/user_literal
[SFINAE]:           http://en.cppreference.com/w/cpp/language/sfinae

[CMake]:            http://cmake.org/
[Doxygen]:          http://doxygen.org/

[Lisp]:             http://en.wikipedia.org/wiki/Lisp_%28programming_language%29
[SML]:              http://en.wikipedia.org/wiki/Standard_ML
[Haskell]:          http://en.wikipedia.org/wiki/Haskell_%28programming_language%29

[Boost.MPL]:        http://boost.org/doc/libs/1_60_0/libs/mpl/doc
[Boost.Hana]:       http://boostorg.github.io/hana
[Meta]:             http://github.com/ericniebler/meta
[Brigand]:          http://github.com/edouarda/brigand

[mpl.lite]:         http://rrsd.com/blincubator.com/bi_suggestion/mpl-lite-or-mpl2/

[travis.metal]:     http://travis-ci.org/brunocodutra/metal
[travis.master]:    http://travis-ci.org/brunocodutra/metal.svg?branch=master
[travis.develop]:   http://travis-ci.org/brunocodutra/metal.svg?branch=develop

[appveyor.metal]:   http://ci.appveyor.com/project/brunocodutra/metal
[appveyor.master]:  http://ci.appveyor.com/api/projects/status/85pk8n05n4r5x103/branch/master?svg=true
[appveyor.develop]: http://ci.appveyor.com/api/projects/status/85pk8n05n4r5x103/branch/develop?svg=true

[Metal.issues]:     http://github.com/brunocodutra/metal/issues
[Metal.latest]:     http://github.com/brunocodutra/metal/archive/master.zip
[Metal.headers]:    http://github.com/brunocodutra/metal/tree/master/include

[Metabench]:        http://brunocodutra.github.io/metabench/
