\mainpage Introduction

\tableofcontents

Overview {#intro_overview}
================================================================================

Metal is a collection of small, closely related [C++11] template
metaprogramming modules.
Header-only and depending solely on C++ standard libraries,
Metal is lightweight and easy to deploy.

Designed to make type metaprogramming feel easy, Metal focus on simplicity,
extending existing tools for metaprogramming rather than reinventing the wheel.
To this end, Metal is built upon well established concepts and is developed to
integrate seamlessly with standard [type traits].
As such, modern C++11 features are explored to their full potential, without,
however, allowing [portability](\ref portability) to be compromised.

Metal owes its design largely to [Boost.MPL] and all due credit is given to the
authors for their groundbreaking work on C++ template metaprogramming.
As a matter of fact, Metal was born *MPL2*,
an independent attempt to *modernize* Boost.MPL, but
soon it became clear that it was slightly more than just a remake,
so thus became **Metal** - <b>Meta</b>programming
<b>Al</b>gorithms.

Motivation {#intro_motivation}
================================================================================

Metaprogramming is the art of writing code that is executed to generate new
code, which in turn is translated into machine code that is finally assembled
into an executable program.

Metaprograms are far from a novelty in the C family, in fact they have been part
of everyday programming since the early days in the form of
*the C preprocessor*.
In C++, metaprogramming was taken to a whole new level with the development of
[template metaprogramming][tmp], a technique that employs templates to
perform computations during compilation time.
Contrary to the C preprocessor, it has long been noticed that
[C++ templates are indeed Turing complete][tmp.turing], thus making templates
the standard tool for metaprogramming in C++.

[Continues...]


Organization of This Document {#intro_organization}
================================================================================

[C++11]:            http://en.wikipedia.org/wiki/C%2B%2B11
[type traits]:      http://en.cppreference.com/w/cpp/header/type_traits
[Boost.MPL]:        http://www.boost.org/doc/libs/1_58_0/libs/mpl/doc/
[tmp]:              https://en.wikipedia.org/wiki/Template_metaprogramming
[tmp.turing]:       http://ubietylab.net/ubigraph/content/Papers/pdf/CppTuring.pdf
