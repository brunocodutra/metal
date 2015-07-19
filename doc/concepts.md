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

## Requirements

If `v` is a model of [Value], then `v` is a type.

## Examples

~~~{.cpp}
    struct value
    {
        //...
    };
~~~

~~~{.cpp}
    using value = int;
~~~

~~~{.cpp}
    using value = decltype(3.14);
~~~

## Counterexamples

~~~{.cpp}
    struct
    {
        //...
    } value;
~~~

~~~{.cpp}
    int value;
~~~

~~~{.cpp}
    auto value = 3.14;
~~~

Optional {#concept_optional}
================================================================================

[Optionals] are [Values] that
represent either *just* some other [Value] or *nothing*.

In order to evaluate an [Optional]
one must explicitly name its nested `::type`.
Whenever a nested `::type` is undefined or ambiguously defined,
an [Optional] is said to be *nothing*,
thus evaluating *nothing* leads to a compile-time error.

While every [Optional] is also a [Value], the converse is not always true.
However, any [Value] can be lifted to a corresponding [Optional] using
`metal::identity`.

## Requirements

If `opt` is a model of [Optional], then `opt` is a model of [Value].

## Associated Traits

metal::is_nothing

## Examples

\snippet concepts/optional.cpp ex1
\snippet concepts/optional.cpp ex2
\snippet concepts/optional.cpp ex3
\snippet concepts/optional.cpp ex4

## Models

metal::nothing

Number {#concept_number}
================================================================================

A [Number] is a compile-time representation of a numerical value,
behaving much like its run-time counterparts.
[Numbers] derive from a specialization of
[std::integral_constant], thus every [Number] is also an [Optional].

## Requirements

If `n` is a model of [Number], then `n` is either:
* an alias to a specialization of
[std::integral_constant].
* publicly and unambiguously derived, directly or indirectly, from a
[Number].

Names inherited from [std::integral_constant]
must not be hidden and must be unambiguously available.

## Examples

~~~{.cpp}
    using n = std::true_type;
~~~

~~~{.cpp}
    using n = std::integral_constant<int, -1>;
~~~

~~~{.cpp}
    struct n :
        std::integral_constant<char, 'a'>
    {};
~~~

Expression {#concept_expression}
================================================================================

An [Expression] is a compile-time representation of a computation that
maps a set of [Values] to a new [Value].
Since [Expressions] behave much like run-time functions,
they are often called *metafunctions*,
not to be confused with the [Function] concept.

Unlike run-time functions, [Expressions] are lazy,
which means that they do not immediately evaluate when invoked.
Rather, an [Expression] invoked with some set of arguments is
itself a model of [Optional], that is either *nothing* or some [Value].
Not unlike any other [Optional],
one must explicitly name the nested `::type`
in order to actually evaluate an [Expression].
In general, however, an [Expression] may naturally compute to
*nothing* for some set of arguments, hence
evaluating such an [Expression] leads to a compile-time error.

An [Expression] which evaluates to some [Value]
when invoked with some set of arguments
is said to be *evaluable* for that set of arguments.

## Requirements

If `expr` is a model of [Expression], then `expr` is either a template class
or alias taking only types as arguments.

## Associated Traits

metal::is_same_expression, metal::is_evaluable

## Examples

\snippet concepts/expression.cpp ex1
\snippet concepts/expression.cpp ex2
\snippet concepts/expression.cpp ex3

## Counterexamples

\snippet concepts/expression.cpp nex1
\snippet concepts/expression.cpp nex2
\snippet concepts/expression.cpp nex3

## Models

metal::identity, metal::call, metal::bind, metal::lambda

Function {#concept_function}
================================================================================

A [Function] is a value representation of an [Expression],
that is, unlike the latter, every [Function] is a model of [Value].
As such, [Functions] can serve as argument or return type to other
[Functions] and [Expressions], thus enabling
[higher-order] computations, much like run-time
[function objects].

A [Function] that takes the form of a template is said to be *parametric*
and behaves much like template types in regular C++.
A special group of particular interest are *parametric* [Functions] which also
meet the criteria to model an [Expression].

## Requirements

If `f` is a model of [Function], then
* `f` is a model of [Value].
* `f::call` is unambiguously defined and is a model of [Expression].

## Associated Traits

metal::is_function

## Examples

\snippet concepts/function.cpp ex1
\snippet concepts/function.cpp ex2

## Counterexamples

\snippet concepts/function.cpp nex1

## Models

metal::arg, metal::quote, metal::bind, metal::lambda

[Value]:                    \ref concept_value
[Values]:                   \ref concept_value
[Optional]:                 \ref concept_optional
[Optionals]:                \ref concept_optional
[Number]:                   \ref concept_number
[Numbers]:                  \ref concept_number
[Expression]:               \ref concept_expression
[Expressions]:              \ref concept_expression
[Function]:                 \ref concept_function
[Functions]:                \ref concept_function

[std::integral_constant]:   http://en.cppreference.com/w/cpp/types/integral_constant
[higher-order]:             https://en.wikipedia.org/wiki/Higher-order_function
[function objects]:         http://en.cppreference.com/w/cpp/utility/functional
