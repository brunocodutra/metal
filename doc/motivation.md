# Motivation {#motivation}

Metaprogramming is the art of writing code that is executed to generate new
code, which in turn is translated into machine code that is finally assembled
into an executable program.

Metaprograms are far from a novelty in the C family, in fact they have been part
of everyday programming since the early days in the form of
the [C preprocessor][preprocessor].
In C++, metaprogramming was taken to a whole new level with the development of
[template metaprogramming][tmp], a technique that employs templates to
perform computations during compilation time.
Contrary to the C preprocessor, it has long been noticed that
[C++ templates are indeed Turing complete][tmp.turing], thus making templates
the standard tool for metaprogramming in C++ since the very beginning.

In March of 2003 [Boost.MPL] is officially shipped with Boost version 1.30.0.
A masterpiece in its field, Boost.MPL went to great lengths to support the
widest variety of poorly conforming if not utterly defective compilers,
abstracting away the nastiest compiler hackery to present a uniform
working interface that others could rely on.
After almost a decade being the best known tool for metaprogramming in C++,
Boost.MPL started to show its age when [C++11] introduced
[variadic templates][variadics], [constant expressions][constexpr] and
[type inference][decltype] to the core language.
This new machinery have opened path to the development of
[several new techniques][tmp.modern] with potential to outperform Boost.MPL
by orders of magnitude in many instances.
This motivated several attempts to propose a modern tool for metaprogramming,
most notably [meta] by Eric Niebler and [Boost.Hana] by Louis Dionne,
with varying degrees of success.

Metal is yet another attempt to modernize the way of doing metaprogramming in
C++ with focus on simplicity, portability and performance.
Its ultimate goal is to succeed Boost.MPL in every use case where support for
C++11 is desired, delivering greater performance and expressiveness.

[C++11]:            http://en.wikipedia.org/wiki/C%2B%2B11
[preprocessor]:     https://en.wikipedia.org/wiki/C_preprocessor
[Boost.MPL]:        http://www.boost.org/doc/libs/1_58_0/libs/mpl/doc/
[tmp]:              https://en.wikipedia.org/wiki/Template_metaprogramming
[tmp.turing]:       http://ubietylab.net/ubigraph/content/Papers/pdf/CppTuring.pdf
[tmp.modern]:       http://www.pdimov.com/cpp2/simple_cxx11_metaprogramming_2.html
[variadics]:        http://en.cppreference.com/w/cpp/language/parameter_pack
[constexpr]:        http://en.cppreference.com/w/cpp/language/constexpr
[decltype]:         http://en.cppreference.com/w/cpp/language/decltype
[meta]:             https://github.com/ericniebler/meta
[Boost.Hana]:       http://boostorg.github.io/hana/index.html
