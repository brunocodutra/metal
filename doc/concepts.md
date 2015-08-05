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

`val` is a model of [Value] if and only if `val` is a type.

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

In order to evaluate an [Optional]
one must explicitly name its nested `::type`.
Whenever a nested `::type` is undefined or ambiguously defined,
an [Optional] is said to be *nothing*,
thus evaluating *nothing* leads to a compile-time error.

## Requirements

`opt` is a model of [Optional] if and only if `opt` is a model of [Value].

## Associated Traits

metal::is_just, metal::is_nothing

## Examples

\snippet concepts/optional.cpp ex1
\snippet concepts/optional.cpp ex2
\snippet concepts/optional.cpp ex3
\snippet concepts/optional.cpp ex4

## Models

metal::maybe, metal::just, metal::nothing

Number {#concept_number}
================================================================================

A [Number] is a compile-time representation of a numerical value,
behaving much like its run-time counterparts.
[Numbers] derive from a specialization of
[std::integral_constant], thus every [Number] is also an [Optional].

## Requirements

`n` is a model of [Number] if and only if `n` is either:
* an alias to a specialization of [std::integral_constant].
* publicly and unambiguously derived, directly or indirectly, from a [Number].

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
they are often called *metafunctions*.

Unlike run-time functions, [Expressions] are lazy,
which means that they do not immediately evaluate when invoked.
Rather, an [Expression] invoked with some set of arguments is
itself a model of [Optional], that is either *nothing* or *just* some [Value].
Not unlike any other [Optional], one must explicitly name the nested `::type`
in order to actually evaluate an [Expression].
In general, however, an [Expression] may naturally compute to
*nothing* for some set of arguments, hence
evaluating such an [Expression] leads to a compile-time error.

An [Expression] which evaluates to some [Value]
when invoked with some set of arguments
is said to be *evaluable* with that set of arguments.

## Requirements

`expr` is a model of [Expression] if and only if `expr` is a template class,
union or alias taking only types as arguments.

## Examples

\snippet concepts/expression.cpp ex1
\snippet concepts/expression.cpp ex2
\snippet concepts/expression.cpp ex3

## Counterexamples

\snippet concepts/expression.cpp nex1
\snippet concepts/expression.cpp nex2
\snippet concepts/expression.cpp nex3

## Models

metal::apply, metal::bind, metal::protect, metal::quote

Lambda {#concept_lambda}
================================================================================

A [Lambda] is a value representation of an [Expression],
that is, unlike the latter, every [Lambda] is a model of [Value].
As such, [Lambdas] can serve as argument or return type to other
[Lambdas] and [Expressions], thus enabling
[higher-order] programming, much like run-time [function objects].

[Lambdas] are named after their homonym mathematical model for computation,
the [Lambda Calculus].

## Requirements

If `expr` is a model of [Expression] and `[a1, ..., an]` are models of [Value],
then `lbd` is a model of [Lambda] if and only if `lbd` is either
* an alias to `expr<a1, ..., an>`
* a [placeholder](\ref placeholders)

## Associated Traits

metal::is_lambda

## Examples

\snippet concepts/lambda.cpp ex1
\snippet concepts/lambda.cpp ex2
\snippet concepts/lambda.cpp ex3

## Counterexamples

\snippet concepts/lambda.cpp nex1
\snippet concepts/lambda.cpp nex2

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
[Lambda]:                   \ref concept_lambda
[Lambdas]:                  \ref concept_lambda

[std::integral_constant]:   http://en.cppreference.com/w/cpp/types/integral_constant
[higher-order]:             https://en.wikipedia.org/wiki/Higher-order_lambda
[function objects]:         http://en.cppreference.com/w/cpp/utility/functional
[Lambda Calculus]:          https://en.wikipedia.org/wiki/Lambda_calculus#The_lambda_calculus
