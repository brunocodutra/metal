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
* **SFINAE-Friendly** - [control overload resolution][SFINAE] and make the most
out of function templates.
* **Metaprogramming made easy** - it doesn't have to be hard,
[check it out](#in_a_glimpse)!

In a Glimpse {#in_a_glimpse}
================================================================================

\snippet tutorial.cpp tutorial

Check out [more examples](#examples) below.

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

Make sure to have CMake v3.4 or newer installed on your system, then,
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
    include_directories(${Metal_INCLUDE_DIR})

To use your local copy of Metal instead, just add its `include/` sub-directory
to the include search paths of your project and you are all set.

Supported Compilers {#supported_compilers}
--------------------------------------------------------------------------------

The following compilers are tested in continuous integration using
[Travis CI][travis.metal] and [Appveyor CI][appveyor.metal].

| Compiler          | Version
|-------------------|-----------
| GCC               | &ge; 4.8
| Clang             | &ge; 3.4
| Xcode             | &ge; 6.4
| Visual Studio     | &ge; 14 (2015)
| MinGW             | &ge; 5

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

Migrating from Boost.MPL {#MPL}
================================================================================

Metal was heavily influenced by Boost.MPL, from which it inherited the
convention of naming algorithms after their counterparts in the C++ standard
library. For this reason, metaprograms written using Metal might resemble those
written using Boost.MPL, but there are fundamental differences between these
libraries that you must keep in mind when porting a legacy metaprogram that uses
Boost.MPL to modern C++ using Metal.

Boost.MPL is notable for employing various tricks to emulate features that only
became directly supported by the core language much later on with C++11. Most
notably, Boost.MPL relies on a template arguments to emulate variadic
templates and create an illusion that _Sequences_, such as `mpl::vector` or
`mpl::map`, can hold an arbitrary number of elements. However, because these
templates could not be truly variadic, every possible size of these _Sequences_
had to be enumerated one by one as a distinct numbered version of the template.

\snippet mpl.cpp variadic_emulation

This trick clearly doesn't scale well and implies there must be an upper limit
to the size of _Sequences_. Indeed Boost.MPL limits the sizes of sequences to only
a couple of dozen elements by default. Moreover, because this boilerplate is too
troublesome to maintain, Boost.MPL relies heavily on the C++ preprocessor, which
on one hand reduces code redundancy, but on the other hand dramatically impacts
compilation time figures.

Metal has none of these issues, since it takes advantage of variadic templates
to reduce that boilerplate to a one-liner, while at the same time overcoming
all of the drawbacks mentioned.

\snippet mpl.cpp variadic

Indeed, Metal [Lists] and [Maps] can easily exceed the hundreds and even
thousands of elements with little impact to the compiler performance. For up to
date benchmark figures, visit [metaben.ch].

Another important difference that arises from the lack of language support at
the time Boost.MPL was designed, is the fact that it had no other means of
expressing metafunctions other than by the rather verbose idiom of declaring a
nested type alias within template classes.

\snippet mpl.cpp alias_emulation

Metal on the other hand is able to take advantage of [alias templates] and make
it much less verbose

\snippet mpl.cpp alias

... but that is not all that there's to it. While template aliases produce
SFINAE-friendly errors, substitution errors on nested types prevent the [SFINAE]
rule from kicking in and trigger hard compilation errors instead, which is
another important drawback of Boost.MPL when compared to Metal. For a discussion
about the importance of SFINAE-friendliness, take a look at \ref SFINAE.

For the reasons discussed, Metal cannot interoperate with Boost.MPL out of the
box, but fortunately it is always possible to map Boost.MPL concepts to their
equivalents in Metal, such as _Sequences_ to [Lists], _Metafunction Classes_ to
[Lambdas] and _Integral Constants_ to [Numbers]. To ease the migration, Metal
provides a built in helper `metal::from_mpl` that does just that for you, simply
include `metal/external/mpl.hpp` to make it available.

Examples {#examples}
================================================================================

\tip{
    In the following examples, `IS_SAME(X, Y)` is just a terser shorthand for
    `static_assert(std::is_same<X, Y>::value, "")`.
}

Parsing Raw Literals {#parsing_raw_literals}
--------------------------------------------------------------------------------
________________________________________________________________________________

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
    [Expression] composition in our [next example](#church_booleans).
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
________________________________________________________________________________

[Church Booleans][church] refer to a mathematical framework used to express
logical operation in the context of [lambda notation][lambda_calculus],
where they have an important theoretical significance.
Of less practical importance in C++, even in the context of template
metaprogramming, they will nevertheless help us acquaint with *bind expressions*
in this toy example.

The boolean constants `true_` and `false_` are, by definition, \lambdas that
return respectively the first and second argument with which they are invoked.

\snippet church.cpp bool

Now, using the fact that booleans are themselves \lambdas, it's not too hard to
realize that invoking a boolean with arguments `<false_, true>` always yields
its negation.

\snippet church.cpp not_expr

However, to enable higher-order composition we really need `not_` to be a
\lambda, not an \expression. Granted one could easily define former in terms of
the latter as `metal::lambda<not_>`, but that would defeat the whole
purpose of this exercise, the idea is to use *bind expressions* directly.

\snippet church.cpp not

Admittedly a little more verbose, but that saves us from introducing a new named
alias template.

Using a similar technique, we can also define operators `and_` and `or_`.

\snippet church.cpp and
\snippet church.cpp or

This exercise might me mind-boggling at first, but you'll get used to it soon
enough.

Without further ado we present the logical operator `xor`.

\snippet church.cpp xor

Notice how we *bind* `not_`, which is only possible due to the fact it is a
\lambda.

A Word on SFINAE-Friendliness {#SFINAE}
--------------------------------------------------------------------------------
________________________________________________________________________________

An [Expression] is said to be SFINAE-friendly when it is carefully designed so
as never to prevent the [SFINAE] rule to be triggered. In general, such
[Expressions] may only trigger template substitution errors at the point of
instantiation of the *signature* of a type, which includes the instantiation of
[alias templates] and default template arguments.
SFINAE-friendly [Expressions] are exceedingly powerful, because they may be used
to drive overload resolution, much like [`std::enable_if`][enable_if] does.
For this reason,
__all [Expressions] in Metal are guaranteed to be SFINAE-friendly__.

Conversely, a SFINAE-unfriendly [Expression] produces so called *hard errors*,
which require the compilation to halt immediately. Examples of *hard errors*
are failed `static_assert`'ions or template substitution errors at the point of
instantiation of the nested members of a type.
SFINAE-unfriendly [Expressions] are very inconvenient, because they force
compilation to halt when they are not selected by overload resolution, thereby
hindering the usage of the entire overloaded set.

To illustrate how useful SFINAE-friendliness can be, suppose we need a factory
function `make_array` that takes an arbitrary number of arguments and returns
a `std::array`. Because arrays are homogeneous collections, we need the
_common type_ of all its arguments, that is, the type to which every argument
can be converted to. Fortunately `std::common_type_t` does just that and is also
guaranteed to be SFINAE-friendly as per the C++ Standard.

\snippet sfinae.cpp make_array

There is one caveat to `std::common_type_t` however: it doesn't work with
`std::tuple`s in general, even though the _common tuple_ is really
just a _tuple_ of _common types_.
Hence, we need a new trait that computes the _common tuple_ from a set of
_tuples_ so that we may overload `make_array`.

\snippet sfinae.cpp common_tuple_t
\snippet sfinae.cpp make_array_of_tuples

And it works as expected, for both numerical values

\snippet sfinae.cpp array_of_numbers

as well as `std::tuple`s

\snippet sfinae.cpp array_of_tuples

Now, it might not be obvious to the untrained eye, but the reason why
overloading works as expected in this example, is precisely the fact
`common_tuple_t` is SFINAE-friendly. If it weren't, as soon as one attempted to
call `make_array` for anything that isn't a `std::tuple`, the compilation would
halt immediately, even if the first overload would be a perfect match otherwise.

To demonstrate this issue, we'll implement the same common tuple trait, but this
time using Boost.Hana, which, contrary to Metal, doesn't provide any guarantees
regarding SFINAE-friendliness.

\snippet sfinae.cpp naive_common_tuple_t

Now, if we use `naive_common_tuple_t` to overload `make_array`

\snippet sfinae.cpp naive_make_array_of_tuples

it does work as expected for `std::tuples`

\snippet sfinae.cpp array_of_tuples

however it produces a compilation error as soon as we try to make an array of
anything that is not a Boost.Hana _Sequence_, even if the first overload remains
available and would be a perfect match as we just verified

\strike{
\snippet sfinae.cpp array_of_numbers
}

> error: static_assert failed "hana::zip_with(f, xs, ys...)
> requires 'xs' and 'ys...' to be Sequences"

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
[church]:           https://en.wikipedia.org/wiki/Church_encoding#Church_Booleans
[lambda_calculus]:  https://en.wikipedia.org/wiki/Lambda_calculus

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
