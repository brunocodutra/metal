# Concepts {#concepts}

[TOC]

Template metaprogramming can be seen as a language of its own
right, sharing the same syntax with C++, but having different semantics.
Because constructs assume different meanings during template metaprogramming
from what they usually mean in an actual C++ context, some key concepts must be
defined.

# Optional Value {#concept_optional_value}

--------------------------------------------------------------------------------

## Requirements

TODO

## Examples

TODO

## Models

TODO

# Numerical Value {#concept_numerical_value}

--------------------------------------------------------------------------------

A \ref concept_numerical_value is a compile type representation of a number,
maping directly to runtime numerical values.
They derive from a specialization of
[std::integral_constant][std_integral_constant], thus
every \ref concept_numerical_value is also a
**Strict** \ref concept_optional_value.

## Requirements

If `n` is a model of \ref concept_numerical_value, then `n` is either:
* an alias to a specialization of
[std::integral_constant][std_integral_constant].
* publicly and unambiguously derived, directly or indirectly, from a
\ref concept_numerical_value.

Names inherited from [std::integral_constant][std_integral_constant]
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

An \ref concept_expression is a compile type representation of a computation.
They map directly to runtime functions and are thus often denoted
*metafunctions*, not to be confused with the \ref concept_function concept.

An \ref concept_expression operates on arguments that model an
\ref concept_optional_value, but
unlike runtime functions, *expressions* are lazy, which means that they do
not immediately evaluate when invoked.
Rather, an \ref concept_expression invoked with some set of *optional values* is
itself a model of \ref concept_optional_value,
thus either *nothing* or *just* something.
Not unlike any other \ref concept_optional_value,
one must explicitly name the nested `::type`
in order to actually evaluate an \ref concept_expression.
In general, however, an \ref concept_expression may also compute to *nothing*,
i.e. an empty \ref concept_optional_value, for some set of arguments, hence,
just like any other empty \ref concept_optional_value,
evaluating such an \ref concept_expression results in a compile time error.

An \ref concept_expression which computes to *just* something, i.e. a non-empty
\ref concept_optional_value, when invoked with some set of arguments
is said to be *evaluable* for that set of arguments.

## Requirements

If `expr` is a model of \ref concept_expression, then `expr` is a template,
either type or alias, taking only types as arguments.

## Examples

~~~{.cpp}
    template<typename>
    struct expr //evaluable for every argument
    {
        struct type;
    };
~~~

~~~{.cpp}
    template<typename...>
    using expr = void; //not evaluable for any set of arguments
~~~

~~~{.cpp}
    template<typename integral> //evaluable for integral types
    using expr = std::integral_constant<integral, integral{}>;
~~~

## Counterexamples

~~~{.cpp}
    template<typename x, x value>
    struct expr //takes a non-type as argument
    {
        struct type;
    };
~~~

~~~{.cpp}
    template<template<typename...> class>
    using expr = void; //takes a non-type as argument
~~~

~~~{.cpp}
    using expr = std::true_type; //not a template nor an alias template
~~~

## Models

\ref functional_traits, verbatim, call, bind, lambda

# Function {#concept_function}

--------------------------------------------------------------------------------

A \ref concept_function is a value representation of an \ref concept_expression,
that is, unlike the latter, it is a model of \ref concept_optional_value.
As such, a \ref concept_function can serve as argument or return type to other
*functions* and *expressions*, thus enabling
[higher-order computations][higher_order], much like runtime
[function objetcs][function_object].

A \ref concept_function can take the form of a template,
in which case it is said to be *parametric*.
*Parametric functions* are only really functions once they are *instantiated*,
much like template types in regular C++.
A special case of particular interest are *parametric functions* which also
meet the criteria to model an \ref concept_expression.

As an \ref concept_optional_value,
a \ref concept_function may certainly evaluate to
*nothing*, i.e. model an empty \ref concept_optional_value,
but it is often very useful that a \ref concept_function
evaluate to *just* itself,
being thus a model of **Strict** \ref concept_optional_value.
Such a function is said to be a *strict function*.

A *strict function*
that is parametric and also meets the criteria to model an
\ref concept_expression is called a *dual function*,
after the fact such a \ref concept_function
may be regarded eiter as a \ref concept_function
or as an \ref concept_expression,
depending on what is more convenient at each particular context.
*Dual functions* play an important role in Metal
and, in fact, two of its most powerful functional
constructs are part of this special group: \ref bind and \ref lambda.


## Requirements

If `f` us a model of \ref concept_function, then
* `f` is also a model of \ref concept_optional_value and
* `f::call` is defined and is a model of \ref concept_expression

## Examples

~~~{.cpp}
    struct f //an empty Optional Value
    {
        template<typename...>
        struct call;
    };
~~~

TODO

## Models

arg, quote, bind, lambda

[std_integral_constant]:    http://en.cppreference.com/w/cpp/types/integral_constant
[higher_order]:             https://en.wikipedia.org/wiki/Higher-order_function
[function_object]:          http://en.cppreference.com/w/cpp/utility/functional
