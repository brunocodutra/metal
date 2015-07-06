# Concepts {#concepts}

[TOC]

Template metaprogramming can be seen as a language of its own
right, distinct from C++ yet sharing the same syntax.
Because constructs assume different meanings during template metaprogramming
from what they usually mean in an actual C++ context, some key concepts must be
defined.

# Value {#concept_value}

--------------------------------------------------------------------------------

## Requirements

## Examples

## Models

# Lazy Value {#concept_lazy_value}

--------------------------------------------------------------------------------

## Requirements

## Examples

## Models

# Strict Lazy Value {#concept_strict_lazy_value}

--------------------------------------------------------------------------------

## Requirements

## Examples

## Models


# Numerical Value {#concept_numerical_value}

--------------------------------------------------------------------------------

A \ref concept_numerical_value is a compile type representation of a number.
Every \ref concept_numerical_value is also a \ref concept_strict_lazy_value.

## Requirements

If `n` is a model of \ref concept_numerical_value, then `n` is either:
* an alias to a specialization of
[std::integral_constant][std_integral_constant].
* publicly and unambiguously derived, directly or indirectly, from a
\ref concept_numerical_value.

Names inherited from std::integral_constant must not be hidden and must be
unambiguously available.

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

Unlike runtime functions, *expressions* are lazy, which means that they do
not immediately evaluate when invoked. Rather, an
\ref concept_expression instantiated with some set of arguments is a model of
\ref concept_lazy_value.
Therefore one must explicitly name its nested `::type`
in order to actually evaluate an \ref concept_expression and thus obtain a
\ref concept_value.

In general, an \ref concept_expression is not required to yield
a valid computation for any given set of arguments.
Those that do yield valid computations for some set of
arguments are said to model an \ref concept_evaluable_expression for that set of
arguments. Evaluating an \ref concept_expression with some set of arguments
for which they do not model an \ref concept_evaluable_expression
results in a compile time error.

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
    template<typename integral>
    using expr = std::integral_constant<integral, integral{}>;
~~~

## Counterexamples

~~~{.cpp}
    template<typename x, x value> //takes a non-type as argument
    struct expr
    {
        struct type;
    };
~~~

~~~{.cpp}
    template<template<typename...> class>  //takes a non-type as argument
    using expr = void;
~~~

~~~{.cpp}
    using expr = std::true_type; //not a template nor an alias template
~~~

## Models

\ref functional_traits, verbatim, call, bind, lambda

# Evaluable Expression {#concept_evaluable_expression}

--------------------------------------------------------------------------------

An \ref concept_evaluable_expression for a given set of arguments is an
\ref concept_expression that yields a valid computation when *evaluated* with
that set of arguments.

## Requirements

If `expr` is a model of \ref concept_expression and is also a model of
\ref concept_evaluable_expression for a given set of generally variadic
arguments `args`, then expr<args...>::type is defined and is a model of
\ref concept_value.

## Examples

~~~{.cpp}
    template<typename>
    struct expr
    {
        struct type;
    };
~~~

~~~{.cpp}
    template<typename integral>
    using expr = std::integral_constant<integral, integral{}>;
~~~

## Counterexamples

~~~{.cpp}
    template<typename...>
    struct expr
    {};
~~~

~~~{.cpp}
    template<typename...>
    using expr = void;
~~~

## Models

\ref functional_traits, verbatim

# Function {#concept_function}

--------------------------------------------------------------------------------

A \ref concept_function is a value representation of an \ref concept_expression,
that is, unlike the latter, it is a model of \ref concept_value.
As such, a \ref concept_function can serve as argument or return type to other
*functions* and *expressions*, thus enabling
[higher-order computations][higher_order], much like runtime
[function objetcs][function_object].

A \ref concept_function can take the form of a template,
in which case it is said to be *parametric*.
*Parametric functions* are only really functions once they are *instantiated*,
much like template types in regular C++.

A special case of particular interest are *parametric functions* which also
meet the criteria to model an \ref concept_expression

## Requirements

If `f` us a model of \ref concept_function, then
* `f` is also a model of \ref concept_value and
* `f::call` is defined and models an \ref concept_expression

## Examples

~~~{.cpp}
    struct f
    {
        template<typename...>
        struct call;
    };
~~~

## Models

arg, quote, bind, lambda

[std_integral_constant]:    http://en.cppreference.com/w/cpp/types/integral_constant
[higher_order]:             https://en.wikipedia.org/wiki/Higher-order_function
[function_object]:          http://en.cppreference.com/w/cpp/utility/functional
