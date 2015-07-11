# Concepts {#concepts}

[TOC]

Template metaprogramming can be seen as a language of its own
right, sharing the same syntax with C++, but having different semantics.
Because constructs assume different meanings during template metaprogramming
from what they usually mean in an actual C++ context, some key concepts must be
defined.

# Value {#concept_value}

--------------------------------------------------------------------------------

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

# Nullable Value {#concept_nullable_value}

--------------------------------------------------------------------------------

[Nullable Values] represent either some [Value] or *nil*.
Every [Nullable Value] is also a model of [Value].

In order to evaluate a [Nullable Value]
one must explicitly name its nested `::type`.
A [Nullable Value] is said to be *nil* whenever a nested `::type` is undefined
or ambiguously defined, thus evaluating *nil* leads to a compile-time error.

## Requirements

If `n` is a model of [Nullable Value], then `n` is a model of [Value].

## Associated Traits

metal::is_nil

## Examples

\snippet concepts/nullable.cpp ex1
\snippet concepts/nullable.cpp ex2
\snippet concepts/nullable.cpp ex3
\snippet concepts/nullable.cpp ex4

## Models

metal::nil

# Strict Value {#concept_strict_value}

--------------------------------------------------------------------------------

A [Strict Value] is a [Nullable Value] that represents itself.
[Strict Values] are never nil.

## Requirements

If `sv` is a model of [Strict Value], then
* `sv` is a non-nil [Nullable Value].
* `sv::type` is either some public and unambiguous base of `sv` or `sv` itself.

## Associated Traits

metal::is_strict_value

## Examples

TODO

## Models

TODO

# Numerical Value {#concept_numerical_value}

--------------------------------------------------------------------------------

A [Numerical Value] is a compile type representation of a number,
behaving much like run-time numerical values.
[Numerical Values] derive from a specialization of
[std::integral_constant], thus
every [Numerical Value] is also a [Strict Value].

## Requirements

If `n` is a model of [Numerical Value], then `n` is either:
* an alias to a specialization of
[std::integral_constant].
* publicly and unambiguously derived, directly or indirectly, from a
[Numerical Value].

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

# Expression {#concept_expression}

--------------------------------------------------------------------------------

An [Expression] is a compile type representation of a computation that
maps a set of [Values] to a new [Value].
Since [Expressions] behave much like run-time functions,
they are often called *metafunctions*,
not to be confused with the [Function] concept.

Unlike run-time functions, [Expressions] are lazy,
which means that they do not immediately evaluate when invoked.
Rather, an [Expression] invoked with some set of arguments is
itself a model of [Nullable Value], that is either nil or some [Value].
Therefore, not unlike any other [Nullable Value],
one must explicitly name the nested `::type`
in order to actually evaluate an [Expression].
In general, however, an [Expression] may naturally compute to
nil for some set of arguments, hence
evaluating such an [Expression] leads to a compile time error.

An [Expression] which evaluates to some [Value]
when invoked with some set of arguments
is said to be *evaluable* for that set of arguments.
If it otherwise evaluates to a [Strict Value],
it is said to be *strictly evaluable* for that set of arguments.

## Requirements

If `expr` is a model of [Expression], then `expr` is either a template class
or alias taking only types as arguments.

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

# Function {#concept_function}

--------------------------------------------------------------------------------

A [Function] is a value representation of an [Expression],
that is, unlike the latter, every [Function] is a model of [Strict Value].
As such, [Functions] can serve as argument or return type to other
[Functions] and [Expressions], thus enabling
[higher-order] computations, much like run-time
[function objects].

A [Function] that takes the form of a template is said to be *parametric*
and behaves much like template types in regular C++.
A special group of particular interest are *parametric* [Functions] which also
meet the criteria to model an [Expression].
Those present a dual behavior and may be regarded as either,
depending on what is more convenient at each particular context.

## Requirements

If `f` is a model of [Function], then
* `f` is a model of [Strict Value].
* `f::call` is unambiguously inherited from `f::type` and
is a model of [Expression].

## Examples

\snippet concepts/function.cpp ex1
\snippet concepts/function.cpp ex2

## Counterexamples

\snippet concepts/function.cpp nex1
\snippet concepts/function.cpp nex2

## Models

metal::arg, metal::quote, metal::bind, metal::lambda

[Value]:                    \ref concept_value
[Values]:                   \ref concept_value
[Nullable Value]:           \ref concept_nullable_value
[Nullable Values]:          \ref concept_nullable_value
[Strict Value]:             \ref concept_strict_value
[Strict Values]:            \ref concept_strict_value
[Numerical Value]:          \ref concept_numerical_value
[Numerical Values]:         \ref concept_numerical_value
[Expression]:               \ref concept_expression
[Expressions]:              \ref concept_expression
[Function]:                 \ref concept_function
[Functions]:                \ref concept_function

[std::integral_constant]:   http://en.cppreference.com/w/cpp/types/integral_constant
[higher-order]:             https://en.wikipedia.org/wiki/Higher-order_function
[function objects]:         http://en.cppreference.com/w/cpp/utility/functional
