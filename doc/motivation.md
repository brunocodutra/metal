# Motivation {#motivation}

Metaprogramming is far from a novelty in the C family,
in fact it has been part of everyday C programming since the early days
through the [preprocessor].
In C++, it was taken to a whole new level with the development of
[template metaprogramming][tmp], a technique that exploits the
template system to perform computations during compilation time.
Contrary to the C preprocessor, it has long been noticed that
[C++ templates are indeed Turing complete][tmp.turing],
thus consolidating template metaprogramming as the standard idiom for
compile time computations in C++.

In March of 2003 the [Boost Metaprogramming Library][Boost.MPL],
by Aleksey Gurtovoy and David Abrahams,
is officially shipped with Boost version 1.30.0.
A masterpiece of template metaprogramming,
it went to great lengths to support the
widest variety of poorly conforming if not utterly defective compilers,
abstracting away the nastiest compiler hackery to present a uniform
framework that finally could be relied upon.
It played a crucial role in the dissemination of metaprogramming in C++ and
remained undisputed for almost a decade,
but, eventually, it started showing its age when [C++11] introduced
[variadic templates][variadics], [alias templates], [type inference][decltype]
and [constant expressions][constexpr] to the core language.
The powerful C++11 machinery enabled the development of whole new
metaprogramming [styles][tmp.simple] and [techniques][tmp.modern] with
potential to outperform Boost.MPL by orders of magnitude in many instances.
Moreover, the need for endless automatically generated boilerplate code could
finally be overcome using variadic templates,
whereas syntax clutter could finally be mitigated using alias templates,
vastly improving readability.

Eventually, [motivation][mpl.lite] to modernize Boost.MPL emerged from the
community, even though opinions diverged widely on the matter.
As diverse has been the development of new metaprogramming libraries
with varying degrees of success,
most notably [meta] by Eric Niebler, [turbo] by Manu Sánchez and [Boost.Hana] by
Louis Dionne, the latter formally accepted into the Boost distribution in July
2015.

Metal is yet another approach to modern C++11 metaprogramming.
Its ultimate goal is to be regarded as the best alternative to Boost.MPL in
every use case where support for C++11 is desired,
delivering greater performance and expressiveness without
cluttering the codebase.
Although not a perfect drop in replacement for Boost.MPL,
Metal follows very similar [design principles](\ref overview),
except that they have been fine tuned to take advantage of C++11,
so migration is meant to be the smoothest possible.

[Boost.MPL]:        http://www.boost.org/doc/libs/1_58_0/libs/mpl/doc/
[Boost.Hana]:       http://boostorg.github.io/hana/index.html
[meta]:             https://github.com/ericniebler/meta
[turbo]:            https://github.com/Manu343726/Turbo

[tmp]:              https://en.wikipedia.org/wiki/Template_metaprogramming
[tmp.turing]:       http://ubietylab.net/ubigraph/content/Papers/pdf/CppTuring.pdf
[tmp.simple]:       http://www.pdimov.com/cpp2/simple_cxx11_metaprogramming.html
[tmp.modern]:       http://www.pdimov.com/cpp2/simple_cxx11_metaprogramming_2.html

[preprocessor]:     https://en.wikipedia.org/wiki/C_preprocessor
[variadics]:        http://en.cppreference.com/w/cpp/language/parameter_pack
[alias templates]:  http://en.cppreference.com/w/cpp/language/type_alias
[decltype]:         http://en.cppreference.com/w/cpp/language/decltype
[constexpr]:        http://en.cppreference.com/w/cpp/language/constexpr

[C++11]:            http://en.wikipedia.org/wiki/C%2B%2B11
[mpl.lite]:         http://rrsd.com/blincubator.com/bi_suggestion/mpl-lite-or-mpl2/
