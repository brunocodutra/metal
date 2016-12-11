# Metal {#mainpage}

\tableofcontents

Metal is a header-only C++14 library designed to make metaprogramming easy.
It provides a powerful high-level abstraction for compile-time algorithms that
mimic the Standard Algorithms Library, hence
**Metal** - <b>Meta</b>programming <b>Al</b>gorithms.

There is a myriad of C++ metaprogramming libraries out there so why Metal?

* **Portable** - compatible with the
[most popular compilers](#supported_compilers).
* **Blazing fast** - browse up to date benchmarks at [metaben.ch].
* **Trivial integration** - `#include <metal.hpp>` and start enjoying
metaprogramming right away.
* **Metaprogramming made easy** - it doesn't have to be hard, check out
[the examples](#examples).
* **SFINAE-Friendly** - [control overload resolution](#SFINAE) and unleash the
power of function templates.

In a Glimpse {#in_a_glimpse}
================================================================================

We start with an empty [List]

\snippet tutorial.cpp empty

then we insert some [Values]

\snippet tutorial.cpp insert

We can check the sizes of lists,

\snippet tutorial.cpp size

access their elements

\snippet tutorial.cpp access

or erase them

\snippet tutorial.cpp erase

We can reverse the order of elements

\snippet tutorial.cpp reverse

count their occurrences

\snippet tutorial.cpp count

and even transform them

\snippet tutorial.cpp transform

That and much, much more!

Getting Started {#getting_started}
================================================================================

Download {#download}
--------------------------------------------------------------------------------

There are a few ways to get Metal, the easiest might be to simply
[download the latest release][Metal.releases] as a compressed package.

If you have git installed and would rather have the latest stable Metal,
you may consider cloning branch `master` from GitHub.

    git clone https://github.com/brunocodutra/metal

Likewise, the bleeding edge development version can be obtained by cloning
branch `develop` instead.

    git clone https://github.com/brunocodutra/metal --branch=develop

Install (optional) {#install}
--------------------------------------------------------------------------------

Metal may optionally be installed system-wide to ease integration with external
projects. If you'd rather use Metal locally, you can skip to the
[next section](#integration).

Make sure to have CMake v3.0 or newer installed on your system, then,
from within an empty directory, issue the following commands.

    cmake /path/to/Metal
    cmake --build . --target install

At this point Metal's include tree will be installed in
`/usr/local/include` on Posix systems and `C:\Program Files\Metal\include`
on Windows.

Integration {#integration}
--------------------------------------------------------------------------------

If you chose to [install Metal system-wide](#install), you just have to make
sure the installation prefix is looked up by your compiler.

Using CMake it suffices to add the following to your `CMakeLists.txt`.

    find_package(Metal REQUIRED)
    include_directories(${METAL_INCLUDE_DIRS})

To use your local copy of Metal instead, just add its `include/` sub-directory
to the include search paths of your project and you are all set.

Supported Compilers {#supported_compilers}
--------------------------------------------------------------------------------

The following compilers are tested in continuous integration using
[Travis CI][travis.metal] and [Appveyor CI][appveyor.metal].

| Compiler          | Version
|-------------------|-----------
| GCC               | &ge; 5
| Clang             | &ge; 3.4
| Xcode             | &ge; 6.4
| Visual Studio     | &ge; 14 (2015)

Project Organization {#project_organization}
--------------------------------------------------------------------------------

Header files are divided in modules named after each [concept](#concepts).
Modules are organized in directories and contain algorithms that operate on
models of that concept. The complete hierarchy of modules and headers is
available on [Metal's repository][Metal.headers] on GitHub.

\tip{
    You may choose to `#include <metal.hpp>` to get access to all that Metal has
    to offer without concerning yourself with which specific headers to include.
}

Concepts {#concepts}
================================================================================

Template metaprogramming may be seen as a language of its own right.
It shares the usual syntax of C++ templates, but has unique semantics.
Because constructs assume different meanings in its context it is useful to
define a few key concepts.

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

### See Also

metal::value, metal::is_value

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

Examples {#examples}
================================================================================

Parsing Raw Literals {#parsing_raw_literals}
--------------------------------------------------------------------------------

If you ever considered augmenting [`std::tuple`][tuple],
so that instead of the rather clunky [`std::get<N>()`][get]

\snippet literal.cpp teaser_1

one could use the more expressive subscript operator `[N]`

\strike{
\snippet literal.cpp teaser_2
}

you might have come up with something like this

\strike{
\snippet literal.cpp naive_1
}

only to realize the hard way that this is simply not valid C++14.

> error: non-type template argument is not a constant expression

While the keyword [`constexpr`][constexpr] tells the compiler the value
returned by `operator []` *might* be a compile time constant, it imposes no
such constraint on its arguments, which may as well be unknown at compile-time.
It might seem we are out of luck at this point, but let us not forget that long
before C++ had `constexpr` variables, integral constants strictly known at
compile time could be expressed with the help of non-type template parameters.

So how about refactoring `operator []` to take an instance of `metal::number`
and relying on template pattern matching to extract its non-type template
argument?

\snippet literal.cpp augmented_tuple

\snippet literal.cpp teaser_3

That looks promising, but then again `metal::number<1>{}` is even clunkier than
`std::get<1>()`, we want something more expressive.

A custom [literal operator][literal.operator] that constructs \numbers out of
integer literals could help reducing the verbosity

\snippet literal.cpp teaser_4

but how is `operator ""_c` implemented?

It might be tempting to try something like this

\strike{
\snippet literal.cpp naive_2
}

but let us not forget the reason why we got this far down the road to begin
with, recall we can't instantiate a template using a non-`constexpr` variable as
argument!

At this point, a watchful reader might argue that in theory there is no real
reason for this to be rejected, since the literal value must always be known at
compile-time and that makes a lot of sense indeed, but unfortunately that's just
not how C++14 works.

All is not lost however, because we can still parse raw literals, in other
words, we are in for some fun!

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

Before translating characters to their corresponding numerical values, we need
to get rid of all digit separators that may be in the way. To do that we'll use
`metal::remove`, which takes a [List] `l` and a [Value] `val` and returns
another [List] that contains every element in `l` and in the same order,
except for those that are the same as `val`.

\snippet literal.cpp remove

The remaining characters can then be individually parsed with the help of
`metal::transform`, which takes a [Lambda] `lbd` and a [List] `l` and returns
another [List] that contains the \values produced by the invocation of `lbd`
for each element in `l`.

    [lbd(l[0]), lbd(l[1]), ..., lbd(l[n-2]), lbd(l[n-1])]

\snippet literal.cpp parse_digit

\snippet literal.cpp transform

Notice how characters are translated to their actual numerical representation.

Thus we have

\snippet literal.cpp parse_digits

### Assembling Numbers

We now turn to `assemble_number`. It takes a [List] of digits and adds them up
according to the radix, in other words

    D0*radix^(n-1) + D1*radix^(n-2) + ... + D{n-2}*radix + D{n-1}

or, recursively,

    ((...((0*radix + D0)*radix + D1)*...)*radix + D{n-2})*radix + D{n-1}

This is the equivalent of [left folding][fold], or, in the Metal parlance,
`metal::accumulate`, after its run-time counterpart in the standard library.

\snippet literal.cpp accumulate_1

Here we introduced a new [Expression] `expr` from which we created a [Lambda],
but we could also have chosen to use *bind expressions* instead.

\snippet literal.cpp accumulate_2

\note{
    If *bind expressions* look scary to you, don't panic, we will exercise
    [Expression] composition in our [next practical example](#church_booleans).
    Here it suffices to keep in mind that *bind expressions* return anonymous
    [Lambdas], just like [`std::bind`][bind] returns anonymous functions, and
    that `metal::_1` and `metal::_2` are the equivalents of
    [`std::placeholders::_1` and `std::placeholder::_2`][placeholders].
}

Finally

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

A Word on SFINAE-Friendliness {#SFINAE}
================================================================================

An [Expression] is said to be SFINAE-friendly when it is carefully designed so
as never to prevent the [SFINAE] rule to be triggered. In general, such
[Expressions] may only trigger template substitution errors at the point of
instantiation of the *signature* of a type, which includes the instantiation of
[alias templates] and default template arguments.

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

[C++14]:            http://en.wikipedia.org/wiki/C%2B%2B14
[JavaScript]:       http://en.wikipedia.org/wiki/JavaScript
[higher-order]:     http://en.wikipedia.org/wiki/Higher-order_function
[first-class]:      http://en.wikipedia.org/wiki/First-class_citizen
[fold]:             http://en.wikipedia.org/wiki/Fold_(higher-order_function)

[algorithm]:        http://en.cppreference.com/w/cpp/algorithm
[alias templates]:  http://en.cppreference.com/w/cpp/language/type_alias
[constexpr]:        http://en.cppreference.com/w/cpp/language/constexpr
[tuple]:            http://en.cppreference.com/w/cpp/utility/tuple
[get]:              http://en.cppreference.com/w/cpp/utility/tuple/get
[enable_if]:        http://en.cppreference.com/w/cpp/types/enable_if
[bind]:             http://en.cppreference.com/w/cpp/utility/functional/bind
[placeholders]:     http://en.cppreference.com/w/cpp/utility/functional/placeholders
[literal.operator]: http://en.cppreference.com/w/cpp/language/user_literal
[SFINAE]:           http://en.cppreference.com/w/cpp/language/sfinae

[travis.metal]:     http://travis-ci.org/brunocodutra/metal
[appveyor.metal]:   http://ci.appveyor.com/project/brunocodutra/metal

[Metal.releases]:   http://github.com/brunocodutra/metal/releases
[Metal.headers]:    http://github.com/brunocodutra/metal/tree/master/include

[metaben.ch]:       http://metaben.ch/
