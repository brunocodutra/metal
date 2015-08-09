# Concepts {#concepts}

\tableofcontents

Template metaprogramming can be seen as a language of its own
right, sharing the same syntax with C++, but having different semantics.
Because constructs assume different meanings during template metaprogramming
from what they usually mean in an actual C++ context, some key concepts must be
defined.

Value {#concept_value}
================================================================================

[Values] are the objects of metaprogramming.
Any type is a [Value].

## Examples

~~~{.cpp}
    struct val
    {
        //...
    };
~~~

~~~{.cpp}
    using val = int;
~~~

~~~{.cpp}
    using val = decltype(3.14);
~~~

## Counterexamples

~~~{.cpp}
    struct
    {
        //...
    } val;
~~~

~~~{.cpp}
    int val;
~~~

~~~{.cpp}
    auto val = 3.14;
~~~

Optional {#concept_optional}
================================================================================

[Optionals] are [Values] that
represent either *just* some other [Value] or *nothing*.

In order to *extract* the underlying [Value] from an [Optional]
one must explicitly name its nested `::type`.
Whenever a nested `::type` is undefined or ambiguously defined,
an [Optional] is said to be empty,
thus attempting to *extract* a [Value] from an empty [Optional]
leads to a compile-time error.

## Examples

\snippet concepts/optional.cpp ex1
\snippet concepts/optional.cpp ex2
\snippet concepts/optional.cpp ex3
\snippet concepts/optional.cpp ex4

## See Also

metal::maybe, metal::just, metal::nothing, metal::extract

Number {#concept_number}
================================================================================

A [Number] is a compile-time representation of a numerical value.

## Requirements

`num` is a model of [Number] if and only if `num` is an alias to a
specialization of [std::integral_constant].

## Examples

\snippet concepts/number.cpp ex1
\snippet concepts/number.cpp ex2

## Counterexamples

\snippet concepts/number.cpp nex1

## See Also

metal::number, metal::boolean

Expression {#concept_expression}
================================================================================

[Expressions] are functions that operate on [Values] and,
because of that, they are also called *metafunctions*.

Unlike run-time functions, [Expressions] are lazy.
An [Expression] evaluated with some set of arguments
is itself a model of [Optional],
that is either *nothing* or *just* some [Value],
therefore one must explicitly name the nested `::type`
in order to *extract* the result of an [Expression].
In general, however, an [Expression] may evaluate to
*nothing* for some set of arguments,
thus attempting to *extract* a result from such an [Expression]
leads to a compile-time error.

## Requirements

`expr` is a model of [Expression] if and only if `expr` is a template class,
union or alias that only expects types as arguments.

## Examples

\snippet concepts/expression.cpp ex1
\snippet concepts/expression.cpp ex2
\snippet concepts/expression.cpp ex3

## Counterexamples

\snippet concepts/expression.cpp nex1
\snippet concepts/expression.cpp nex2
\snippet concepts/expression.cpp nex3

## See Also

metal::eval

Lambda {#concept_lambda}
================================================================================

[Lambdas] are [first-class] functions that operate on [Values].
As [Values] themselves,
[Lambdas] can serve both as argument as well as return type to an *application*,
thus enabling [higher-order] metaprogramming.

[Lambdas] are named after formal system for computability,
the [Lambda Calculus].

## Lambda Application

Let `expr` be an [Expression], `[a1, ..., ai, ..., an]` [Values] and
`[_1, ..., _i, ..., _n]` [Placeholders].

* Applying `ai` to any (possibly empty) set of [Values] yields `ai`
* Applying `expr<a1, ..., an>` to any (possibly empty) set of [Values] yields
`expr<a1, ..., an>::type`
* Applying `_i` to `[a1, ..., ai, ..., an]` yields `ai`
* Applying `expr<_1, ..., _n>` to `[a1, ..., an]` yields
`expr<a1, ..., an>::type`

## Examples

\snippet concepts/lambda.cpp ex1
\snippet concepts/lambda.cpp ex2
\snippet concepts/lambda.cpp ex3
\snippet concepts/lambda.cpp ex4

## See Also

metal::apply, metal::arg

Sequence {#concept_sequence}
================================================================================

A [Sequence] is a collection of [Values].
One distinguishes between two kinds of [Sequences],
*lists* and *maps*, the latter being just a special case of the former.

* A *list* is any specialization of any template class or union,
that only expects types as arguments.

* A *map* is a *list* of *pairs*, that is,
*lists* that contain exactly two [Values].

## Examples

## Counterexamples

## See Also

metal::list, metal::map


[Value]:                    \ref concept_value
[Values]:                   \ref concept_value
[Optional]:                 \ref concept_optional
[Optionals]:                \ref concept_optional
[Number]:                   \ref concept_number
[Numbers]:                  \ref concept_number
[Expression]:               \ref concept_expression
[Expressions]:              \ref concept_expression
[Lambda]:                   \ref concept_lambda
[Lambdas]:                  \ref concept_lambda
[Sequence]:                 \ref concept_sequence
[Sequences]:                \ref concept_sequence

[Placeholders]:             \ref placeholders

[std::integral_constant]:   http://en.cppreference.com/w/cpp/types/integral_constant
[higher-order]:             https://en.wikipedia.org/wiki/Higher-order_lambda
[first-class]:              https://en.wikipedia.org/wiki/First-class_citizen
[Lambda Calculus]:          https://en.wikipedia.org/wiki/Lambda_calculus
