# Metal {#mainpage}

\tableofcontents

Metal is a single header C++11 library designed to make template metaprogramming
convenient. It provides a powerful high-level abstraction for compile-time
algorithms that mimic the Standard Algorithms Library, hence
**Metal** - <b>Meta</b>programming <b>Al</b>gorithms.

There is a myriad of C++ metaprogramming libraries out there so why Metal?

* **Portable** - compatible with the
[most popular compilers][Metal.portable].
* **Blazing fast** - browse up to date benchmarks at [metaben.ch].
* **Trivial Integration** - everything you need in a single self-contained
header file [`metal.hpp`][Metal.standalone].
* **SFINAE-Friendly** - [control overload resolution](#SFINAE) and make the most
out of function templates.

In a Glimpse {#in_a_glimpse}
================================================================================

\snippet tutorial.cpp tutorial

**[Try it online][godbolt.metal]!**

Be sure to also have a look at the [examples](#examples) below.

Definitions {#definitions}
================================================================================

Template metaprogramming may be seen as a language of its own right,
it shares the usual syntax of C++ templates, but has its own unique semantics.
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

\tip{
    `metal::number<n>` is guaranteed to be an alias template to
    `std::integral_constant<metal::int_, n>`.
}

### Examples

\snippet number.cpp num1
\snippet number.cpp num2
\snippet number.cpp num3

### Counterexamples

\snippet number.cpp not_a_num1
\snippet number.cpp not_a_num2

### FAQ

\ref FAQ_numbers

### See Also

metal::number, metal::is_number, metal::as_number

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

metal::lambda, metal::is_lambda, metal::as_lambda

List {#list}
--------------------------------------------------------------------------------

A [List] is a sequence of [Values].

### Requirements

`list` is a model of [List] if and only if `list` is a specialization of
`metal::list`.

### Examples

\snippet list.cpp  list1
\snippet list.cpp  list2

### Counterexamples

\snippet list.cpp not_a_list1

### See Also

metal::list, metal::is_list, metal::as_list

Pair {#pair}
--------------------------------------------------------------------------------

A [Pair] is a couple of [Values].

### Requirements

A [Pair] is any [List] whose size is 2.

### Examples

\snippet pair.cpp  pair1

### Counterexamples

\snippet pair.cpp not_a_pair1

### See Also

metal::pair, metal::is_pair, metal::as_pair

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

metal::map, metal::is_map, metal::as_map

Examples {#examples}
================================================================================

\note{
    In the following examples, `IS_SAME(X, Y)` is just a terser shorthand for
    `static_assert(std::is_same<X, Y>{}, "")`.
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

only to realize the hard way that this is simply not valid C++.

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

A custom [literal operator] that constructs \numbers out of integer literals
could help reducing the verbosity

\snippet literal.cpp teaser_4

but how is `operator ""_c` implemented?

It might be tempting to try something like this

\strike{
\snippet literal.cpp naive_2
}

but let us not forget the reason why we got this far down the road to begin
with, recall we can't instantiate a template using a non-`constexpr` variable as
argument!

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
default constructed object of whatever type it evaluates to, which is guaranteed
to be a [Number] in this case.

\snippet literal.cpp _c

### Resolving the Radix

In its turn `parse_number` strips the prefix, if any, thus resolving the radix,
then forwards the remaining characters to `parse_digits`, which is in charge of
translating the raw characters to the numerical values they represent.
The radix and digits are then forwarded to `assemble_number`, which adds up the
individual digits according to the radix.

\snippet literal.cpp parse_number

Notice how we are able to use template pattern matching and partial template
specializations to extract all relevant information from the tokens.

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

which can also be written recursively

    ((...((0*radix + D0)*radix + D1)*...)*radix + D{n-2})*radix + D{n-1}

This is the equivalent of [left folding][fold] a [List], or, in Metal parlance,
`metal::accumulate`, after its run-time counterpart in the standard library.

\snippet literal.cpp accumulate_1

Here we introduced a new [Expression] `expr` from which we created a [Lambda],
but we could also have chosen to use *bind expressions* instead.

\snippet literal.cpp accumulate_2

\tip{
    If *bind expressions* look scary to you, don't panic, we will exercise
    [Expression] composition in our [next example](#church_booleans).
    Here it suffices to keep in mind that *bind expressions* return anonymous
    [Lambdas], just like [`std::bind`][bind] returns anonymous functions, and
    that `metal::_1` and `metal::_2` are the equivalents of
    [`std::placeholders`][placeholders].
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
logical operation in the context of [lambda notation],
where they have an important theoretical significance.
Of less practical importance in C++, even in the context of template
metaprogramming, they will nevertheless help us acquaint with *bind expressions*
in this toy example.

The boolean constants `true_` and `false_` are, by definition, \lambdas that
return respectively the first and second argument with which they are
[invoked](\ref metal::invoke).

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

Automatic Test Cases Generation {#automatic_test_cases_generation}
--------------------------------------------------------------------------------
________________________________________________________________________________

Suppose you have a component you want to test, say an algorithm on sequences.
Because it's a generic algorithm, it's able to work with any kind of containers
and, as such, is specialized for different categories of iterators so that it
always delivers optimal performance. Moreover, to provide exception safety
guarantees without compromising on execution time or memory consumption, it must
also specialize on `noexcept` properties of the elements, particularly of their
move constructors. Finally, it's conceivable that such a generic algorithm could
also take advantage of other properties, such as whether elements can be ordered
or not.

As such a complex implementation, it ought to be thoroughly tested for all
relevant combinations of iterator categories and interesting properties
implemented by the contained elements. Furthermore, it's crucial that all corner
cases are covered, such as empty sequences to name the most obvious, so, before
we even start to get fancy with our test cases, we already have three dimensions
that vary independently, namely

1. Iterator category;
2. Element properties;
3. Size of the sequence.

How can we possibly implement this testing suite?

First of all, it's a good idea to subdivide each _test case_ into three steps:
the set-up phase constructs the particular sequence to be tested, the execution
phase runs our algorithm and the tear-down phase releases the resources. This
way we can leverage on [RAII] and reduce the boilerplate to a minimum.

\snippet testing.cpp test_case

That's a good start, but in order to run all test cases we still have to
manually instantiate each and every combination of iterator categories, element
type and sequence size. That is, if we want to test for `M` different categories
of iterators, `N` sets of interesting properties that could be provided by
elements and `O` different sizes of containers, we end up with `M*N*O` distinct
instantiations to maintain! That's too troublesome and prone to error, there
ought to be a way to generate all test cases automatically.

Fortunately Metal can do just that for us. With the help of `metal::cartesian`,
we can generate every test case automatically, which we can then run by
instantiating a single driver class. It's actually very simple.

\snippet testing.cpp automatic

And that was it.

To verify that we are in fact generating all possible combinations of test cases
under the hood, let's inspect the return type of `generate_test_cases`

\snippet testing.cpp inspect

A Word on SFINAE-Friendliness {#SFINAE}
--------------------------------------------------------------------------------
________________________________________________________________________________

An [Expression] is said to be SFINAE-friendly when it is carefully designed so
as never to prevent the [SFINAE] rule to be triggered. In general, such
[Expressions] may only trigger template substitution errors at the point of
declaration of a type, which includes the instantiation of [alias templates],
default template arguments and the _signature_ of function templates.
SFINAE-friendly [Expressions] are exceedingly powerful, because they may be used
to drive overload resolution, think [`std::enable_if`][enable_if] on steroids.
For this reason,
__all [Expressions] in Metal are guaranteed to be strictly SFINAE-friendly__.

Conversely, a SFINAE-unfriendly [Expression] produces so called *hard errors*,
which require the compilation to halt immediately. Examples of *hard errors*
are failed `static_assert`'ions or template substitution errors at the point of
definition of a class or function template. SFINAE-unfriendly [Expressions] are
very inconvenient, because they force compilation to halt when they are not
selected by overload resolution, thereby hindering the usage of the entire
overloaded set.

### make_array

To illustrate how useful SFINAE-friendliness can be, suppose we need a factory
function `make_array` that takes an arbitrary number of arguments and returns
a `std::array`. Because arrays are homogeneous collections, we need the
_common type_ of all its arguments, that is, the type to which every argument
can be converted to.

The base case is straightforward.

\snippet sfinae.cpp make_array

\snippet sfinae.cpp array_of_numbers

Now suppose we need an array of tuples

\snippet sfinae.cpp tuples

\strike{
\snippet sfinae.cpp naive_array_of_tuples
}

> error: no matching function for call to 'make_array'

Even though the _common tuple_ is really just a _tuple_ of _common types_,
`std::common_type_t` is unable to find it in general. That means we need to
overload `make_array` and handle the _array of tuples_ case.

### make_array of tuples

The idea is to define a metafunction that computes the _common tuple_ from a
set of _tuples_ and then use it to overload our factory function.

This sounds like a use-case for Boost.Hana, let's try it.

\snippet sfinae.cpp hana_common_tuple_t
\snippet sfinae.cpp hana_make_array_of_tuples

It works as expected for `std::tuples`

\snippet sfinae.cpp hana_array_of_tuples

but we get a compilation error as soon as we try to make an array of anything
that is not a Boost.Hana _Sequence_, even though the first overload remains
available and would be a perfect match otherwise.

\strike{
\snippet sfinae.cpp hana_array_of_numbers
}

> error: static_assert failed "hana::zip_with(f, xs, ys...)
> requires 'xs' and 'ys...' to be Sequences"

### make_array of tuples _done right_

The reason why Boost.Hana can't help us overload `make_array` is the fact that
it doesn't provide any SFINAE-friendliness guarantees, which essentially means
that it cannot be used effectively to control overload resolution. Metal, on the
other hand, was carefully designed to never trigger hard errors but rather
_substitution failures_, which makes it able to select candidates from an
overloaded set by means of the [SFINAE] rule.

Let's try the same approach using Metal.

\snippet sfinae.cpp common_tuple_t
\snippet sfinae.cpp make_array_of_tuples

This time it works not only for `std::tuple`'s

\snippet sfinae.cpp array_of_tuples

but also for numerical values

\snippet sfinae.cpp array_of_numbers

Again, this only works as expected because of the strict SFINAE-friendliness
guarantees provided by Metal.

Getting Started {#getting_started}
================================================================================

Metal is distributed as a drop-in standalone header file and integrating it in
your project is as easy as it gets:

1. Download the [latest release][Metal.releases]
2. `# include </path/to/metal.hpp>`

Migrating from Boost.MPL {#MPL}
================================================================================

A quick glance Metal and Boost.MPL might look very similar, but because Metal
leverages modern language features that were not available at the time Boost.MPL
was developed, they are in fact fundamentally distinct.

### Metafunctions

The representation of *metafunctions* has been completely redesigned in Metal.
Instead of expressing them as class templates that define a nested typename
`type`, Metal assumes *metafunctions* to be templates, usually but not
necessarily alias, that evaluate directly to the result type.

That is, instead of something like this

\snippet mpl.cpp lazy_expression

you should simply write this

\snippet mpl.cpp eager_expression

Notice that traditional *lazy metafunctions* are still valid [Expressions] in
Metal, but keep in mind that their nested typename `type` is never implicitly
evaluated.

\snippet mpl.cpp lazy_evaluation

Don't worry, you can still use *lazy metafunctions* with Metal just fine, you
just need to use the adaptor `metal::lazy` instead of `metal::lambda`.

\snippet mpl.cpp lazy_adaptor

Additionally, you can also explicitly evaluate *lazy values* using
`metal::eval`.

\snippet mpl.cpp eval

### Type Traits

Traditionally, *type traits* are represented as class templates that define a
nested integral constant `value`. Metal on the other hand defines a *type trait*
as any [Expression] that returns a [Number], but that's not to say you can't use
good old *type traits* with Metal just fine, on the contrary, in a similar
fashion to *lazy metafunctions*, all you have to do is use the trait adaptor
`metal::trait` instead of `metal::lambda`.

\snippet mpl.cpp trait_adaptor

Alternatively, you can also explicitly convert *traits* to [Numbers] using
`metal::as_number`.

\snippet mpl.cpp as_number

### Metafunction Classes

The concept of _Metafunction Class_ became obsolete with Metal. Instead of
defining [first-class][first-class] metafunctions like you would with Boost.MPL

\snippet mpl.cpp lazy_lambda

you just have to wrap regular metafunctions using `metal::lambda` instead

\snippet mpl.cpp eager_lambda

It's that simple.

Frequently Asked Questions {#FAQ}
================================================================================

What are some advantages of Metal with respect to Boost.MPL? {#FAQ_MPL}
--------------------------------------------------------------------------------
________________________________________________________________________________

The most apparent advantage of Metal with respect to Boost.MPL is the fact Metal
[Lists] and [Maps] can easily exceed the hundreds and even thousands of elements
with little impact to the compiler performance, whereas Boost.MPL _Sequences_,
such as `mpl::vector` and `mpl::map`, are hard-limited to at most a couple dozen
elements and even then at much longer compilation times and higher memory
consumption than Metal. Another obvious improvement in Metal is the much terser
syntax made possible by alias templates, which were not available at the time
Boost.MPL was developed.

Visit [metaben.ch] for up to date benchmarks that compare Metal against
Boost.MPL and other notable metaprogramming libraries. For a brief discussion
about fundamental design differences between Boost.MPL and Metal, refer to
\ref MPL.

What are some advantages of Metal with respect to Boost.Hana? {#FAQ_Hana}
--------------------------------------------------------------------------------
________________________________________________________________________________

As a tool specifically designed for type level programming, Metal is able to
provide stronger guarantees and much faster compilation times than Boost.Hana
when used for similar purposes. In fact, Metal guarantees SFINAE-friendliness,
whereas Boost.Hana does not. Check out \ref SFINAE for a real world example of
the limitations of Boost.Hana with this respect.

Moreover, since Metal [concepts](#definitions) are defined by their type
signatures, it is always safe to use template pattern matching on them to
partially specialize class templates or overload function templates. In
contrast, the types of most Boost.Hana objects are left unspecified.

Why isn't std::integral_constant a Number in general? {#FAQ_numbers}
--------------------------------------------------------------------------------
________________________________________________________________________________

[Numbers] are defined as a specific specialization of `std::integral_constant`s,
whose binary representation is fixed to `metal::int_`, an implementation-defined
integral type. This design choice stems from the fact two [Values] compare equal
if and only if they have the same type signature. As [Values] themselves,
[Numbers] are also subject to this requirement, thus had [Numbers] been defined
as a numerical value _plus_ its binary representation, would two [Numbers] only
compare equal if they had both the same numerical value _and_ the same binary
representation. This is unreasonable in the context of metaprogramming, where
the binary representation of numerical values is entirely irrelevant.

[Value]:            #value
[Values]:           #value
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

[higher-order]:     http://en.wikipedia.org/wiki/Higher-order_function
[first-class]:      http://en.wikipedia.org/wiki/First-class_citizen
[fold]:             http://en.wikipedia.org/wiki/Fold_(higher-order_function)
[church]:           http://en.wikipedia.org/wiki/Church_encoding#Church_Booleans
[lambda notation]:  http://en.wikipedia.org/wiki/Lambda_calculus

[alias templates]:  http://en.cppreference.com/w/cpp/language/type_alias
[constexpr]:        http://en.cppreference.com/w/cpp/language/constexpr
[tuple]:            http://en.cppreference.com/w/cpp/utility/tuple
[get]:              http://en.cppreference.com/w/cpp/utility/tuple/get
[enable_if]:        http://en.cppreference.com/w/cpp/types/enable_if
[bind]:             http://en.cppreference.com/w/cpp/utility/functional/bind
[placeholders]:     http://en.cppreference.com/w/cpp/utility/functional/placeholders
[literal operator]: http://en.cppreference.com/w/cpp/language/user_literal
[SFINAE]:           http://en.cppreference.com/w/cpp/language/sfinae
[RAII]:             http://en.cppreference.com/w/cpp/language/raii

[godbolt.metal]:    https://godbolt.org/g/JN13FQ

[travis.metal]:     http://travis-ci.org/brunocodutra/metal
[appveyor.metal]:   http://ci.appveyor.com/project/brunocodutra/metal

[Metal.portable]:   http://github.com/brunocodutra/metal#portable
[Metal.releases]:   http://github.com/brunocodutra/metal/releases
[Metal.headers]:    http://github.com/brunocodutra/metal/tree/master/include
[Metal.standalone]: http://github.com/brunocodutra/metal/blob/standalone/metal.hpp

[metaben.ch]:       http://metaben.ch/
