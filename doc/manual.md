# Documentation {#mainpage}

\tableofcontents

Metal is a [portable](#portability) header-only [C++11] library
designed to make [template metaprogramming][tmp] enjoyable.
To that end, it provides a powerful high-level [abstraction](#concepts) for
compile-time algorithms that mimic the [standard algorithms library][algorithm],
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

In March of 2003 the [Boost Metaprogramming Library][Boost.MPL],
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
most notably [meta] by Eric Niebler, [turbo] by Manu Sánchez and [Boost.Hana] by
Louis Dionne, the latter formally accepted into the Boost distribution in July
2015.

Metal is yet another approach to modern C++11 metaprogramming.
Its ultimate goal is to be regarded as the natural successor of Boost.MPL in
every use case where C++11 is available,
delivering greater performance and expressiveness without
cluttering the codebase.
Although not a perfect drop in replacement for Boost.MPL,
Metal follows very similar design principles,
except that they have been fine tuned to take advantage of C++11,
so migration is meant to be the smoothest possible.

Getting Started {#getting_started}
================================================================================

It's very easy to start enjoying metaprogramming with Metal,
being header-only with no external dependencies,
all you have to do is download it.

Downloading {#downloading}
--------------------------------------------------------------------------------

There are a few ways to get a copy of Metal,
the easiest might be to simply
<a class="download" href="#">download the latest release</a>
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
projects.
It relies on [CMake] v2.8 or newer to automate the installation process,
so you need to have it installed on your system before proceeding.

From within an empty directory issue the following commands.

    cmake /path/to/Metal
    cmake --build . --target install

Unless otherwise specified,
Metal's include tree will be copied into the default prefix
for locally installed libraries in your platform,
that is `/usr/local/include` on Unix[-like] systems and
`C:\Program Files\Metal\include` on Windows.
Simply add the installation prefix to the include search path of your
compiler/project if it isn't by default, and you're good to go.

Using Metal {#using_metal}
--------------------------------------------------------------------------------

Metal may be used as is immediately after downloading,
simply add its `include/` sub-directory to the include search paths of
your compiler/project and you're all set.

If your project uses [CMake],
Metal may easily be integrated into your project via `find_package`,
whereupon `METAL_INCLUDE_DIRS` is set to contain all necessary include prefixes.
If you have installed Metal system-wide,
it should suffice to add the following to the `CMakeLists.txt` of your project.

    find_package(Metal REQUIRED)
    include_directories(${METAL_INCLUDE_DIRS})

\note{Please remember to enable at least C++11 support in order to use Metal.}

\tip{
If your project is using CMake 3.1 or newer,
[`CMAKE_CXX_STANDARD`][CMake.doc.std] may be used to globally enable
specific C++ standards. Simply set it to `11` or later before adding any target
that depends on Metal.
}

For more information, please refer to the [CMake documentation][CMake.doc].

Documentation {#documentation}
--------------------------------------------------------------------------------

An offline copy of this very documentation may be obtained by cloning
branch `gh-pages`.

    git clone https://github.com/brunocodutra/metal --branch=gh-pages

Alternatively, if you have [CMake] and [Doxygen] installed,
the documentation may also be built locally.
From within an empty directory issue the following commands.

    cmake /path/to/Metal
    cmake --build . --target doc

The documentation will be generated into `doc/html/`.

To browse the documentation offline,
simply load `index.html` on any web browser that supports [JavaScript].

Header Organization {#header_organization}
--------------------------------------------------------------------------------

Each header in Metal is named after the construct it defines,
so for instance distinct.hpp defines metal::distinct,
while invoke.hpp defines metal::invoke and so on.

Headers are semantically organized within modules,
which are named after each [concept](#concepts).
Each module corresponds to a directory in the filesystem and may
naturally contain sub-modules, that is, sub-directories.
Along each directory, on the same level in the filesystem,
there is a also header file with the same name of that directory that includes
every header therein.

The complete hierarchy of modules and headers that comprise Metal is available
in section [Headers](files.html).

Finaly, headers within `detail/` are undocumented and should be expected to
undergo breaking changes without prior notice,
so directly depending on these headers or,likewise,
anything within `namespace metal::detail`,
is strongly discouraged.


Portability {#portability}
================================================================================

Great effort is undertaken to keep Metal strictly in conformance with the C++11
standard and compatible with the widest possible variety of compilers.
To this end, some of the most popular freely available C++ compilers are
actively supported through [Continuous Integration (CI)][ci] premisses.
GCC and Clang are tested with help of [Travis CI][travis.metal],
while Microsoft Visual Studio is tested using [Appveyor CI][appveyor.metal].

Current Status {#status}
--------------------------------------------------------------------------------

Current compilation status is summarized in the table bellow,
if your favorite compiler is not listed, please [let us know][Metal.issues].

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
        <td class="hidden-xs">4.8</td>
        <td rowspan="2">![travis.master]</td>
        <td rowspan="2">![travis.develop]</td>
    </tr>
    <tr>
        <th>Clang</th>
        <td class="hidden-xs">3.5</td>
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

\snippet concepts/value.cpp ex1
\snippet concepts/value.cpp ex2
\snippet concepts/value.cpp ex3

### Counterexamples

\snippet concepts/value.cpp nex1
\snippet concepts/value.cpp nex2
\snippet concepts/value.cpp nex3

Number {#number}
--------------------------------------------------------------------------------

A [Number] is a compile-time representation of a numerical value.

### Requirements

`num` is a model of [Number] if and only if `num` is an alias to a
specialization of [std::integral_constant][integral].

### Examples

\snippet concepts/number.cpp ex1
\snippet concepts/number.cpp ex2

### Counterexamples

\snippet concepts/number.cpp nex1

### See Also

metal::number, metal::boolean, metal::integer, metal::character

Optional {#optional}
--------------------------------------------------------------------------------

[Optionals] are [Values] that
represent either *just* some other [Value] or *nothing*.

In order to *evaluate* an [Optional]
one must explicitly name its nested `::type`.
An [Optional] is said to be empty,
whenever a nested [Value] called `::type` is undefined or ambiguously defined,
thus attempting to *evaluate* an empty [Optional] leads to a compile-time error.

\tip{
`metal::eval<opt>` is equivalent to `typename opt::type`
for any [Optional] `opt`.
}

### Requirements

Any [Value] is also an [Optional].

### Examples

\snippet concepts/optional.cpp ex1
\snippet concepts/optional.cpp ex2
\snippet concepts/optional.cpp ex3
\snippet concepts/optional.cpp ex4

### See Also

metal::optional, metal::just, metal::nothing, metal::eval

Expression {#expression}
--------------------------------------------------------------------------------

[Expressions], also called *metafunctions*,
are functions that operate on [Values].

Unlike run-time functions, [Expressions] are lazy, that is,
an [Expression] bound to some set of arguments is itself a model of [Optional],
that means one must explicitly name its nested `::type`
in order to actually *evaluate* an [Expression].
In general, however, an [Expression] may be *empty* for some set of arguments,
thus attempting to *evaluate* such an [Expression] for such set of arguments
leads to a compile-time error.

\tip{
To save typing, most [Expressions] in Metal have an associated eager adaptor
suffixed by `_t`, that is,
given an expression `metal::expr`,
`metal::expr_t<...>` is equivalent to `typename metal::expr<...>::type`.
}

### Requirements

`expr` is a model of [Expression] if and only if `expr` is a
template class, union or alias that only expects types as arguments.

### Examples

\snippet concepts/expression.cpp  ex1
\snippet concepts/expression.cpp  ex2
\snippet concepts/expression.cpp  ex3

### Counterexamples

\snippet concepts/expression.cpp nex1
\snippet concepts/expression.cpp nex2
\snippet concepts/expression.cpp nex3



Lambda {#lambda}
--------------------------------------------------------------------------------

[Lambdas], short for *Lambda Expressions*,
are [first-class expressions][first-class] that operate on [Values].
As [Values] themselves,
[Lambdas] can serve both as argument as well as return type to other [Lambdas],
thus enabling [higher-order] metaprogramming.

[Lambdas] are named after formal system for computability,
the [Lambda Calculus].

### Requirements

Any [Value] is also a [Lambda].

### Semantics

Let `expr` be an [Expression], `[a1, ..., ai, ..., an]` atomic [Values],
`[_1, ..., _i, ..., _n]` [Placeholders] and `[l1, ..., li, ..., ln]` [Lambdas].

* Invoking `ai` with any (possibly empty) set of [Values] yields `ai`
* Invoking `_i` with `[a1, ..., ai, ..., an]` yields `ai`
* Invoking `metal::lambda<expr>` with `[a1, ..., an]` yields
`expr<a1, ..., an>::type`
* Invoking `expr<l1, ..., li, ..., ln>` with `[a1, ..., an]`
invokes `metal::lambda<expr>` with the [Values] yielded by
recursively invoking each `li` with `[a1, ..., an]`.

\tip{
`metal::lambda<expr>` can be used to adapt any [Expression] `expr`
into a [Lambda].
}

### Examples

\snippet concepts/lambda.cpp ex1
\snippet concepts/lambda.cpp ex2
\snippet concepts/lambda.cpp ex3
\snippet concepts/lambda.cpp ex4
\snippet concepts/lambda.cpp ex5

### See Also

metal::invoke, metal::arg, metal::lambda

List {#list}
--------------------------------------------------------------------------------

A [List] is a sequence of [Values].

### Requirements

A [List] is any specialization of any template class or union
that only expects types as arguments.

### Examples

\snippet concepts/list.cpp  ex1
\snippet concepts/list.cpp  ex2

### Counterexamples

\snippet concepts/list.cpp nex1
\snippet concepts/list.cpp nex2

### See Also

metal::list, metal::is_list

Pair {#pair}
--------------------------------------------------------------------------------

A [Pair] is a couple of [Values].

### Requirements

A [Pair] is any [List] whose size is 2.

### Examples

\snippet concepts/pair.cpp  ex1

### Counterexamples

\snippet concepts/pair.cpp nex1

### See Also

metal::pair, metal::is_pair, metal::first, metal::second

Map {#map}
--------------------------------------------------------------------------------

A [Map] is a collection of unique [Values],
each of which is associated with another [Value].

### Requirements

A [Map] is a [List] of [Pairs], whose first elements are all distinct, that is

    [[k0, v0], ..., [kn, vn]]; ki != kj for all i, j in {0, n} and i != j

### Examples

\snippet concepts/map.cpp  ex1
\snippet concepts/map.cpp  ex2

### Counterexamples

\snippet concepts/map.cpp nex1
\snippet concepts/map.cpp nex2

### See Also

metal::map, metal::is_map, metal::keys, metal::values

Data-Code Duality {#duality}
================================================================================

Markedly influenced by various functional programming languages,
such as [Haskell] and [SML],
Metal owes much of its design particularly to [Lisp].
From it, Metal borrowed [s-expressions] and
the notion that data structures and algorithms are nothing
but [two sides of the same coin][homoiconicity], that is,
Metal makes no difference between lists and unevaluated expressions.

Take for instance the following definition.

\snippet homoiconicity.cpp 1

Here `sum` could be understood as an unevaluated addition of three numbers, thus

\snippet homoiconicity.cpp 2

Alternativelly, `sum` could also be seen as a [List] that contains three values

\snippet homoiconicity.cpp 3

Now, just like any [List], `sum` may be transformed into a new [List]

\snippet homoiconicity.cpp 4

... which in turn may be seen as the sum of the squares of the same three numbers.

\snippet homoiconicity.cpp 5

Metal in Action {#metal_in_action}
================================================================================

Enough theory, lets see some action!

Parsing Raw Literals {#parsing_raw_literals}
--------------------------------------------------------------------------------

If you ever considered augmenting [`std::tuple`][tuple],
so that instead of the rather odd [`std::get<N>()`][get]

\snippet literal.cpp teaser_1

one could just use the more intuitive subscript operator `[N]`,

\strike{
\snippet literal.cpp teaser_2
}

chances are you realized the hard way that there is simply no way of
overloading such an operator!

All is not lost however if you can live with the subscript operator taking an
object of type `std::integral_constant`, or in Metal's parlance [Number],
instead of an usual integral value.

\snippet literal.cpp super_tuple

\snippet literal.cpp teaser_3

Neat isn't it?
Now we need a [literal operator][literal] `_c` that encodes an integral value
as a [Number]. Sounds simple enough, right?

\strike{
\snippet literal.cpp naive
}

Not really. While `constexpr` tells the compiler the value returned by
`operator ""_c` might be a compile time constant,
it tells no such thing about its argument.
We are thus left no other option but to parse raw literals ourselves,
in other words, we are in for some fun!

### The Raw Literal Operator Template

Raw literal operator templates are defined as a nullary function templated over
`char...`, such as

\snippet literal.cpp raw

where `tokens...` are mapped to the exact characters that make up the literal,
including the prefixes `0x` and `0b`

\snippet literal.cpp raw_examples_1

as well as the digit separator `'` introduced in [C++14]

\snippet literal.cpp raw_examples_2

### The `operator ""_c`

We start by defining our very own literal operator `_c`.
It simply wraps each token into a `metal::character` and forwards them to an
[Expression] that effectively parses the [Number], we'll call it,
suggestively, `make_number`.

\snippet literal.cpp _c

### Resolving the Radix

In its turn `make_number` strips the prefix, if any, thus resolving the radix,
then forwards the remaining tokens to `parse_digits`,
which is in charge of translating the raw characters to a [List] of
integral [Numbers].
The radix and digits are then forwarded to `compute`, which adds up the digits
according to the radix.

\snippet literal.cpp make_number

Notice that we followed the notation used by Metal and defined `make_number_t`
as an alias to `typename make_number<>::type` to save typing.

### Parsing the Digits

To parse the characters into the corresponding integral, we need first to remove
all digit separators.
That can be easily accomplished using `metal::remove`, which takes a [List] `l`
and a [Value] `v` and returns another [List] that contains every element from
`l` and in the same order, except for those that are identical to `v`.

\snippet literal.cpp remove

The remaining digits can then be transformed into the corresponding
[Numbers] using `metal::transform`, which takes a [Lambda] `lbd` and a
[List] `l` and returns another [List] containing the results of *invoking* `lbd`
for each element in `l`.

    [lbd(l[0]), lbd(l[1]), ..., lbd(l[n-2]), lbd(l[n-1])]

First we need an [Expression] that maps characters to
[Numbers] from which we can construct our `lbd`.
We'll call it `to_number` and it is rather trivial.

\snippet literal.cpp to_number

Now we can transform characters to [Numbers].

\snippet literal.cpp transform_1

That peculiar `metal::_1` is a [Placeholder] and it works like this:
when `to_number<metal::_1>` is invoked with some argument,
`metal::_1` will be substituted for that argument and only then `to_number`
is *evaluated*.

Putting it all together we have

\snippet literal.cpp parse_digits

### Computing the Number

Now we turn our attention to `compute`.
It takes the radix and a list of [Numbers] representing the digits and is in
charge of adding up the digits according to the radix, that is

    D0*radix^(n-1) + D1*radix^(n-2) + ... + D{n-2}*radix + D{n-1}

The first thing we notice is that the *ith* digit actually corresponds to the
<em>(n-1-i)th</em> power of the radix, so, to make things simpler,
we need to `metal::reverse` the order of digits.

\snippet literal.cpp reverse

Then we have

    D0 + D1*radix + ... + D{n-2}*radix^(n-2) + D{n-1}*radix^(n-1)

Now we need to `metal::enumerate` the exponents that correspond to each digit.

\snippet literal.cpp enumerate

This version of `metal::enumerate` takes two [Numbers], `start` and `size`,
and returns a [List] containing a sequence of [Numbers] beginning with `start`
and ending in `size - 1`.

    [start, start + 1, ..., size - 2, size - 1]

\note{
All [Numbers] in the sequence have the same type as `start`
regardless of the type of `size`.
}

The next step is to compute each term of the sum.
We'll be using `metal::transform` again, but this time it takes a *binary*
[Lambda] `lbd` and two [Lists] `l1` and `l2` and returns a new [List] formed by
*invoking* `lbd` for the elements of `l1` and `l2` pairwise.

    [lbd(l1[0], l2[0]), lbd(l1[1], l2[1]), ..., lbd(l1[n-2], l2[n-2]), lbd(l1[n-1], l2[n-1])]

\snippet literal.cpp transform_2

Here again `metal::_1` and `metal::_2` are [Placeholders] that get substituted
for the first and second arguments with which `lbd` is invoked,
prior to the recursive *evaluation* of the [Expressions] that form the [Lambda].

Finally we need to sum up the terms, so basically we need to invoke `metal::add`
for the elements contained in a [List].
That's exactly what `metal::apply` is for.

\snippet literal.cpp sum

Here we used `metal::lambda<metal::add>` which is basically a synonym for

    metal::add<metal::_1, metal::_2, ..., metal::arg<n-2>, metal::arg<n-1>>

where `n` is the number of arguments with which `metal::lambda<metal::add>` is
invoked, that is the size of the [List] in this particular case.
This way we don't need to care about the actual number of arguments.

We now have all the pieces needed to define `compute`.

\snippet literal.cpp compute

And we are done.

\snippet literal.cpp test_1

It also works for very long binary literals.

\snippet literal.cpp test_2

And ignores digit separators too.

\snippet literal.cpp test_3

[Value]:            #value
[Values]:           #value
[Optional]:         #optional
[Optionals]:        #optional
[Number]:           #number
[Numbers]:          #number
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
[Placeholder]:      \ref placeholders
[Placeholders]:     \ref placeholders

[C++11]:            http://en.wikipedia.org/wiki/C%2B%2B11
[C++14]:            http://en.wikipedia.org/wiki/C%2B%2B14
[JavaScript]:       http://en.wikipedia.org/wiki/JavaScript
[higher-order]:     http://en.wikipedia.org/wiki/Higher-order_lambda
[first-class]:      http://en.wikipedia.org/wiki/First-class_citizen
[Lambda Calculus]:  http://en.wikipedia.org/wiki/Lambda_calculus
[s-expressions]:    http://en.wikipedia.org/wiki/S-expression
[homoiconicity]:    http://en.wikipedia.org/wiki/Homoiconicity
[ci]:               http://en.wikipedia.org/wiki/Continuous_integration

[tmp]:              http://en.wikipedia.org/wiki/Template_metaprogramming
[tmp.turing]:       http://ubietylab.net/ubigraph/content/Papers/pdf/CppTuring.pdf
[tmp.simple]:       http://pdimov.com/cpp2/simple_cxx11_metaprogramming.html
[tmp.modern]:       http://pdimov.com/cpp2/simple_cxx11_metaprogramming_2.html

[algorithm]:        http://en.cppreference.com/w/cpp/algorithm
[preprocessor]:     http://en.wikipedia.org/wiki/C_preprocessor
[variadics]:        http://en.cppreference.com/w/cpp/language/parameter_pack
[alias templates]:  http://en.cppreference.com/w/cpp/language/type_alias
[decltype]:         http://en.cppreference.com/w/cpp/language/decltype
[constexpr]:        http://en.cppreference.com/w/cpp/language/constexpr
[integral]:         http://en.cppreference.com/w/cpp/types/integral_constant
[tuple]:            http://en.cppreference.com/w/cpp/utility/tuple
[get]:              http://en.cppreference.com/w/cpp/utility/tuple/get
[literal]:          http://en.cppreference.com/w/cpp/language/user_literal

[CMake]:            http://cmake.org/
[CMake.doc]:        http://cmake.org/documentation/
[CMake.doc.std]:    https://cmake.org/cmake/help/v3.1/variable/CMAKE_CXX_STANDARD.html

[Doxygen]:          http://doxygen.org/

[Lisp]:             http://en.wikipedia.org/wiki/Lisp_%28programming_language%29
[SML]:              http://en.wikipedia.org/wiki/Standard_ML
[Haskell]:          http://en.wikipedia.org/wiki/Haskell_%28programming_language%29

[Boost.MPL]:        http://boost.org/doc/libs/1_60_0/libs/mpl/doc
[Boost.Hana]:       http://boostorg.github.io/hana
[meta]:             http://github.com/ericniebler/meta
[turbo]:            http://github.com/Manu343726/Turbo

[mpl.lite]:         http://rrsd.com/blincubator.com/bi_suggestion/mpl-lite-or-mpl2/

[travis.metal]:     http://travis-ci.org/brunocodutra/metal
[travis.master]:    http://travis-ci.org/brunocodutra/metal.svg?branch=master
[travis.develop]:   http://travis-ci.org/brunocodutra/metal.svg?branch=develop

[appveyor.metal]:   http://ci.appveyor.com/project/brunocodutra/metal
[appveyor.master]:  http://ci.appveyor.com/api/projects/status/85pk8n05n4r5x103/branch/master?svg=true
[appveyor.develop]: http://ci.appveyor.com/api/projects/status/85pk8n05n4r5x103/branch/develop?svg=true

[Metal.issues]:     http://github.com/brunocodutra/metal/issues
[Metal.latest]:     http://github.com/brunocodutra/metal/archive/master.zip
