# Documentation {#mainpage}

\tableofcontents

Metal is a general-purpose, header-only [C++11][C++11]
[template metaprogramming][tmp] library designed to make
metaprogramming enjoyable.
It provides a powerful high-level abstraction for compile-time algorithms,
grounded on a concise yet solid [conceptual foundation](\ref concepts).

With focus on [simplicity] and [expressiveness],
Metal explores the full potential of modern features, without,
on the other hand,
allowing its [portability](\ref portability) to be compromised.
Metal does its best to follow the
[principle of least astonishment][pola],
mimicking well established concepts used by the [STL], much like its ancestor
and main source of inspiration, the [Boost.MPL].
In fact, Metal was born *MPL2*, an independent attempt to modernize Boost.MPL,
but soon it became clear that it was something more than just a remake,
so thus became **Metal** - <b>Meta</b>programming <b>Al</b>gorithms.

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
widest variety of poorly conforming if not utterly defective compilers,
abstracting away the nastiest compiler hackery to present a uniform
framework that finally could be relied upon.
It played a crucial role in the dissemination of metaprogramming in C++ and
remained undisputed for almost a decade,
but, eventually, it started showing its age when [C++11] introduced,
among various others,
[variadic templates][variadics], [alias templates], [type inference][decltype]
and [constant expressions][constexpr] to the core language.
This powerful C++11 machinery enabled the development of whole new
metaprogramming [styles][tmp.simple] and [techniques][tmp.modern] with
potential to outperform Boost.MPL by orders of magnitude in many instances.
Moreover, the need for endless automatically generated boilerplate code could
finally be overcome using variadic templates,
whereas syntax clutter could be mitigated using alias templates,
vastly improving readability.

Eventually, [motivation][mpl.lite] to modernize Boost.MPL emerged from the
community, even though opinions diverged widely on the matter.
As diverse has been the development of new metaprogramming libraries
with varying degrees of success,
most notably [meta] by Eric Niebler, [turbo] by Manu Sánchez and [Boost.Hana] by
Louis Dionne, the latter formally accepted into the Boost distribution in July
2015.

Metal is yet another approach to modern C++11 metaprogramming.
Its ultimate goal is to be regarded as the best alternative to Boost.MPL in
every use case where support for C++11 is desired,
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
all you have to do is download and optionally install it system-wide.

Downloading {#downloading}
--------------------------------------------------------------------------------

There are a few ways to get a copy of Metal,
the easiest might be to simply [download the latest release][Metal.latest]
as a compressed package.

Alternatively, if you have git installed,
you can clone current stable branch `master` from GitHub.

    git clone https://github.com/brunocodutra/metal

Likewise, the [bleeding edge] development version can be obtained by cloning
branch `develop` instead.

    git clone https://github.com/brunocodutra/metal --branch=develop

\note{
During development it is possible that branch `develop` breaks temporarily.
Be sure to check current compilation [status](\ref status) prior to cloning.
}

Metal may be used as is immediately after downloading,
simply add its `include/` sub-directory to the include search paths of
your compiler/project and you're all set.
To ease integration, however, specially if your project uses [CMake],
you might consider [installing](\ref installing) Metal system-wide.

Installing {#installing}
--------------------------------------------------------------------------------

Metal may optionally be installed system-wide to ease integration with external
projects. It relies on [CMake] to automate the installation process,
so you need to have it installed on your system before proceeding.

From within an empty directory issue the following commands.

    cmake /path/to/Metal
    cmake --build . --target install

Unless otherwise specified,
Metal's include tree will be copied into the default prefix
for locally installed libraries in your platform,
that is `/usr/local/include` on [Unix[-like]][unix-like] systems and
`C:\Program Files\Metal\include` on Windows.
Simply add the installation prefix to the include search path of your
compiler/project if it hasn't been already, and you're good to go.

If your project uses [CMake],
Metal may also be integrated into your project via `find_package`,
whereupon `METAL_INCLUDE_DIRS` will be set to contain
all necessary include prefixes.
In short, simply add the following to the `CMakeLists.txt` of your project.

    find_package(Metal REQUIRED)
    include_directories(${METAL_INCLUDE_DIRS})

For more information, please refer to [CMake documentation][CMake.doc].

Documentation {#documentation}
--------------------------------------------------------------------------------

An offline copy of this documentation website may be obtained by cloning
branch `gh-pages`.

    git clone https://github.com/brunocodutra/metal --branch=gh-pages

Alternatively, if you have [CMake] and [Doxygen] installed,
the documentation may also be built locally.
From within an empty directory issue the following commands.

    cmake /path/to/Metal
    cmake --build . --target doc

The documentation will be generated into `doc/html/`.

To browse the documentation offline,
simply load `index.html` on your favorite web browser.

Portability {#portability}
================================================================================

Great effort is undertaken to keep Metal strictly in conformance with the C++11
standard and compatible with the widest possible variety of compilers.
To this end, some of the most popular freely available C++ compilers are
officially and actively supported through [Continuous Integration (CI)][ci]
premisses.
GCC and Clang are tested with help of [Travis CI][travis.metal],
while Microsoft Visual Studio is tested using [Appveyor CI][appveyor.metal].

Current Status {#status}
--------------------------------------------------------------------------------

Current compilation status is summarized in the table bellow,
if your favorite compiler is not listed, please [let us know][Metal.issues].

<center>
    <table>
        <tr>
            <th rowspan="2">Compiler</th>
            <th rowspan="2" class="hidden-xs">Minimum Version</th>
            <th colspan="2">Branch</th>
        </tr>
        <tr>
            <th align="center">Master</th>
            <th align="center">Develop</th>
        </tr>
        <tr>
            <td align="left">GCC</td>
            <td align="center" class="hidden-xs">4.8</td>
            <td align="center" rowspan="2">![travis.master]</td>
            <td align="center" rowspan="2">![travis.develop]</td>
        </tr>
        <tr>
            <td align="left">Clang</td>
            <td align="center" class="hidden-xs">3.5</td>
        </tr>
        <tr>
            <td align="left">MSVC</td>
            <td align="center" class="hidden-xs">14 (2015)</td>
            <td align="center">![appveyor.master]</td>
            <td align="center">![appveyor.develop]</td>
        </tr>
    </table>
</center>


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

Value {#concepts_value}
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

Number {#concepts_number}
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

metal::number, metal::boolean, metal::integer

Optional {#concepts_optional}
--------------------------------------------------------------------------------

[Optionals] are [Values] that
represent either *just* some other [Value] or *nothing*.

In order to *evaluate* an [Optional]
one must explicitly name its nested `::type`.
An [Optional] is said to be empty,
whenever a nested `::type` is undefined or ambiguously defined,
thus attempting to *evaluate* an empty [Optional] leads to a compile-time error.

\tip{
`metal::eval<opt>` is equivalent to `typename opt::type`
for any [Optional] `opt`.
}

### Requirements

Any type is an [Optional].

### Examples

\snippet concepts/optional.cpp ex1
\snippet concepts/optional.cpp ex2
\snippet concepts/optional.cpp ex3
\snippet concepts/optional.cpp ex4

### See Also

metal::optional, metal::just, metal::nothing, metal::eval

Expression {#concepts_expression}
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

\note{
Because [Expressions] are not themselves [Values],
it is not possible to write [higher-order] expressions.
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

Lambda {#concepts_lambda}
--------------------------------------------------------------------------------

[Lambdas], short for *Lambda Expressions*,
are [first-class expressions][first-class] that operate on [Values].
As [Values] themselves,
[Lambdas] can serve both as argument as well as return type to other [Lambdas],
thus enabling [higher-order] metaprogramming.

[Lambdas] are named after formal system for computability,
the [Lambda Calculus].

### Requirements

Any type is a [Lambda].

### Semantics

Let `expr` be an [Expression], `[a1, ..., ai, ..., an]` atomic [Values],
`[_1, ..., _i, ..., _n]` [Placeholders] and `[l1, ..., li, ..., ln]` [Lambdas].

* Invoking `ai` for any (possibly empty) set of [Values] yields `ai`
* Invoking `_i` for `[a1, ..., ai, ..., an]` yields `ai`
* Invoking `metal::lambda<expr>` for `[a1, ..., an]` yields
`expr<a1, ..., an>::type`
* Invoking `expr<l1, ..., li, ..., ln>` for `[a1, ..., an]`
invokes `metal::lambda<expr>` for the set of [Values] yielded by
invoking each `li` for `[l1, ..., ln]`.

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

List {#concepts_list}
--------------------------------------------------------------------------------

A [List] is a sequence of [Values].

### Requirements

A [List] is any specialization of any template class or union,
that only expects types as arguments.

### Examples

\snippet concepts/list.cpp  ex1
\snippet concepts/list.cpp  ex2

### Counterexamples

\snippet concepts/list.cpp nex1
\snippet concepts/list.cpp nex2

### See Also

metal::list, metal::is_list

Pair {#concepts_pair}
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

Map {#concepts_map}
--------------------------------------------------------------------------------

A [Map] is a collection of unique [Values],
each of which is associated with another [Value].

### Requirements

A [Map] is a [List] of [Pairs], whose first elements are all distinct, that is

    [[k0, v0], ..., [kn, vn]]; ki != kj for all i, j in {0, n}

### Examples

\snippet concepts/map.cpp  ex1
\snippet concepts/map.cpp  ex2

### Counterexamples

\snippet concepts/map.cpp nex1
\snippet concepts/map.cpp nex2

### See Also

metal::map, metal::is_map, metal::keys, metal::values

Data-Code Duality {#concepts_duality}
================================================================================

Markedly influenced by various functional programming languages,
such as [Haskell] and [SML], Metal owes much of its design to [Lisp]
in particular.
From it, Metal borrowed [s-expressions] and
the notion that data structures and algorithms are nothing
but [two sides of the same coin][homoiconicity].

Much like Lisp, Metal makes no difference between lists and unevaluated
expressions.
The following, for example, could be seen as an unevaluated expression
that represents the sum of two numbers.

\snippet manual.cpp sum

Just as accurately, it could also be seen as a pair.

\snippet manual.cpp first
\snippet manual.cpp second

Now that may look silly put in a simple example like this one, but [...]

\tip{
To save typing, most [Expressions] in Metal have an associated eager adaptor
suffixed by `_t`, that is,
given an expression `metal::$`,
`metal::$_t<...>` is equivalent to `typename metal::$<...>::type`.
}

[Value]:            \ref concepts_value
[Values]:           \ref concepts_value
[Optional]:         \ref concepts_optional
[Optionals]:        \ref concepts_optional
[Number]:           \ref concepts_number
[Numbers]:          \ref concepts_number
[Expression]:       \ref concepts_expression
[Expressions]:      \ref concepts_expression
[Lambda]:           \ref concepts_lambda
[Lambdas]:          \ref concepts_lambda
[List]:             \ref concepts_list
[Lists]:            \ref concepts_list
[Pair]:             \ref concepts_pair
[Pairs]:            \ref concepts_pair
[Map]:              \ref concepts_map
[Maps]:             \ref concepts_map
[Placeholders]:     \ref placeholders

[C++11]:            http://en.wikipedia.org/wiki/C%2B%2B11
[STL]:              http://en.wikipedia.org/wiki/Standard_Template_Library
[pola]:             http://en.wikipedia.org/wiki/Principle_of_least_astonishment
[simplicity]:       http://en.wikipedia.org/wiki/Simplicity#Quotes_about_simplicity
[expressiveness]:   http://en.wikipedia.org/wiki/Expressive_power_%28computer_science%29
[higher-order]:     http://en.wikipedia.org/wiki/Higher-order_lambda
[first-class]:      http://en.wikipedia.org/wiki/First-class_citizen
[Lambda Calculus]:  http://en.wikipedia.org/wiki/Lambda_calculus
[s-expressions]:    http://en.wikipedia.org/wiki/S-expression
[homoiconicity]:    http://en.wikipedia.org/wiki/Homoiconicity
[ci]:               http://en.wikipedia.org/wiki/Continuous_integration
[bleeding edge]:    http://en.wikipedia.org/wiki/Bleeding_edge_technology
[unix-like]:        http://en.wikipedia.org/wiki/Unix-like

[tmp]:              http://en.wikipedia.org/wiki/Template_metaprogramming
[tmp.turing]:       http://ubietylab.net/ubigraph/content/Papers/pdf/CppTuring.pdf
[tmp.simple]:       http://pdimov.com/cpp2/simple_cxx11_metaprogramming.html
[tmp.modern]:       http://pdimov.com/cpp2/simple_cxx11_metaprogramming_2.html

[preprocessor]:     http://en.wikipedia.org/wiki/C_preprocessor
[variadics]:        http://en.cppreference.com/w/cpp/language/parameter_pack
[alias templates]:  http://en.cppreference.com/w/cpp/language/type_alias
[decltype]:         http://en.cppreference.com/w/cpp/language/decltype
[constexpr]:        http://en.cppreference.com/w/cpp/language/constexpr
[integral]:         http://en.cppreference.com/w/cpp/types/integral_constant

[CMake]:            http://cmake.org/
[CMake.doc]:        http://cmake.org/documentation/

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
