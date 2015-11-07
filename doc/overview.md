# Overview {#overview}

\tableofcontents

It may seem odd, but to understand what Metal is,
one must first learn what it doesn't have to offer:

* no mutable variables;
* no [side effects].

While severely crippling at a first glance,
these features, or rather lack thereof,
classify Metal as [purely functional] and that's
precisely what grants it such great [expressivity]
while attaining [simplicity].

Markedly influenced by various functional programming languages,
such as [Haskell] and [SML], Metal owes much of its design to [Lisp]
in particular.
From it, Metal borrowed [s-expressions] and
the notion that data structures and algorithms are nothing
but [two sides of the same coin][homoiconicity].
These two concepts are crucial for understanding what metal can do Metal,
but before we put the cart before the horse,
let's first go through some basic concepts and conventions.

Template metaprogramming can be seen as a language of its own right,
sharing the same syntax with C++, but having different semantics.
Because constructs assume different meanings during template metaprogramming
from what they usually mean in an actual C++ context, some key concepts must be
defined.

Concepts {#concepts}
================================================================================

Value {#overview_concepts_value}
--------------------------------------------------------------------------------

[Values] are the objects of metaprogramming.

### Requirements

Any type is a [Value].

### Examples

\snippet overview/concepts/value.cpp ex1
\snippet overview/concepts/value.cpp ex2
\snippet overview/concepts/value.cpp ex3

### Counterexamples

~~~{.cpp}
int val;
~~~

~~~{.cpp}
auto val = 3.14;
~~~

~~~{.cpp}
struct
{
    //...
} val;
~~~

Number {#overview_concepts_number}
--------------------------------------------------------------------------------

A [Number] is a compile-time representation of a numerical value.

### Requirements

`num` is a model of [Number] if and only if `num` is an alias to a
specialization of [std::integral_constant][integral].

### Examples

\snippet overview/concepts/number.cpp ex1
\snippet overview/concepts/number.cpp ex2

### Counterexamples

\snippet overview/concepts/number.cpp nex1

### See Also

metal::number, metal::boolean, metal::integer

Optional {#overview_concepts_optional}
--------------------------------------------------------------------------------

[Optionals] are [Values] that
represent either *just* some other [Value] or *nothing*.

In order to *evaluate* an [Optional]
one must explicitly name its nested `::type`.
An [Optional] is said to be empty,
whenever a nested `::type` is undefined or ambiguously defined,
thus attempting to *evaluate* an empty [Optional] leads to a compile-time error.

### Requirements

Any type is an [Optional].

### Examples

\snippet overview/concepts/optional.cpp ex1
\snippet overview/concepts/optional.cpp ex2
\snippet overview/concepts/optional.cpp ex3
\snippet overview/concepts/optional.cpp ex4

### See Also

metal::optional, metal::just, metal::nothing, metal::eval

Expression {#overview_concepts_expression}
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

\note
Because [Expressions] are not themselves [Values],
it is not possible to write [higher-order] expressions.

\tip{
To save typing, most [Expressions] in Metal have an associated eager adaptor
suffixed by `_t`, that is,
given an expression `metal::$`,
`metal::$_t<...>` is equivalent to `typename metal::$<...>::type`.
}

### Requirements

`expr` is a model of [Expression] if and only if `expr` is a
template class, union or alias that only expects types as arguments.

### Examples

\snippet overview/concepts/expression.cpp  ex1
\snippet overview/concepts/expression.cpp  ex2
\snippet overview/concepts/expression.cpp  ex3

### Counterexamples

\snippet overview/concepts/expression.cpp nex1
\snippet overview/concepts/expression.cpp nex2
\snippet overview/concepts/expression.cpp nex3

Lambda {#overview_concepts_lambda}
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

### Examples

\snippet overview/concepts/lambda.cpp ex1
\snippet overview/concepts/lambda.cpp ex2
\snippet overview/concepts/lambda.cpp ex3
\snippet overview/concepts/lambda.cpp ex4
\snippet overview/concepts/lambda.cpp ex5

### See Also

metal::invoke, metal::arg, metal::lambda

List {#overview_concepts_list}
--------------------------------------------------------------------------------

A [List] is a sequence of [Values].

### Requirements

A [List] is any specialization of any template class or union,
that only expects types as arguments.

### Examples

\snippet overview/concepts/list.cpp  ex1
\snippet overview/concepts/list.cpp  ex2
\snippet overview/concepts/list.cpp  ex3

### Counterexamples

\snippet overview/concepts/list.cpp nex1
\snippet overview/concepts/list.cpp nex2
\snippet overview/concepts/list.cpp nex3

### See Also

metal::list, metal::is_list

Pair {#overview_concepts_pair}
--------------------------------------------------------------------------------

A [Pair] is a couple of [Values].

### Requirements

A [Pair] is any [List] whose size is 2.

### Examples

\snippet overview/concepts/pair.cpp  ex1

### Counterexamples

\snippet overview/concepts/pair.cpp nex1

### See Also

metal::pair, metal::is_pair, metal::first, metal::second

Map {#overview_concepts_map}
--------------------------------------------------------------------------------

A [Map] is a collection of unique [Values],
each of which is associated with another [Value].

### Requirements

A [Map] is a [List] of [Pairs], whose first elements are all distinct, that is

    [[k0, v0], ..., [kn, vn]]; ki != kj for all i, j in {0, n}

### Examples

\snippet overview/concepts/map.cpp  ex1
\snippet overview/concepts/map.cpp  ex2

### Counterexamples

\snippet overview/concepts/map.cpp nex1
\snippet overview/concepts/map.cpp nex2

### See Also

metal::map, metal::is_map, metal::keys, metal::values

The Data-Code Duality {#overview_duality}
================================================================================

Much like Lisp, Metal makes no difference between lists and unevaluated
expressions.
The following, for example, could be seen as an unevaluated expression
that represents the sum of two numbers.

\snippet overview/duality.cpp sum

Just as accurately, it could also be seen as a pair.

\snippet overview/duality.cpp first
\snippet overview/duality.cpp second

Now that may look silly put in a simple example like this one, but [...]



[side effects]:         https://en.wikipedia.org/wiki/Side_effect_%28computer_science%29
[purely functional]:    https://en.wikipedia.org/wiki/Purely_functional
[s-expressions]:        https://en.wikipedia.org/wiki/S-expression
[homoiconicity]:        https://en.wikipedia.org/wiki/Homoiconicity
[expressivity]:         https://en.wikipedia.org/wiki/Expressive_power_%28computer_science%29
[simplicity]:           https://en.wikipedia.org/wiki/Simplicity#Quotes_about_simplicity

[Lisp]:                 https://en.wikipedia.org/wiki/Lisp_%28programming_language%29
[SML]:                  https://en.wikipedia.org/wiki/Standard_ML
[Haskell]:              https://en.wikipedia.org/wiki/Haskell_%28programming_language%29

[Value]:                \ref overview_concepts_value
[Values]:               \ref overview_concepts_value
[Optional]:             \ref overview_concepts_optional
[Optionals]:            \ref overview_concepts_optional
[Number]:               \ref overview_concepts_number
[Numbers]:              \ref overview_concepts_number
[Expression]:           \ref overview_concepts_expression
[Expressions]:          \ref overview_concepts_expression
[Lambda]:               \ref overview_concepts_lambda
[Lambdas]:              \ref overview_concepts_lambda
[List]:                 \ref overview_concepts_list
[Lists]:                \ref overview_concepts_list
[Pair]:                 \ref overview_concepts_pair
[Pairs]:                \ref overview_concepts_pair
[Map]:                  \ref overview_concepts_map
[Maps]:                 \ref overview_concepts_map
[Placeholders]:         \ref placeholders

[integral]:             http://en.cppreference.com/w/cpp/types/integral_constant
[higher-order]:         https://en.wikipedia.org/wiki/Higher-order_lambda
[first-class]:          https://en.wikipedia.org/wiki/First-class_citizen
[Lambda Calculus]:      https://en.wikipedia.org/wiki/Lambda_calculus
