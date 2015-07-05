# Overview {#mainpage}

[TOC]

# Introduction {#intro}

--------------------------------------------------------------------------------

Metal is a collection of small, closely related [C++11] template
metaprogramming modules.
Header-only and having the C++ standard library as its only dependency,
Metal is lightweight and easy to deploy.

Designed to make type metaprogramming feel easy, Metal focus on simplicity,
extending existing tools for metaprogramming rather than reinventing the wheel.
To this end, Metal is built upon well established concepts and is developed to
integrate seamlessly with standard [type traits].
As such, modern C++11 features are explored to their full potential, without,
however, allowing its [portability](@ref portability) to be compromised.

Metal owes its design largely to [Boost.MPL] and all due credit is given to the
authors for their groundbreaking work on C++ template metaprogramming.
As a matter of fact, Metal was born *MPL2*,
an independent attempt to *modernize* Boost.MPL, but
soon it became clear that it was slightly more than just a remake,
so thus became **Metal** - <b>Meta</b>programming
<b>Al</b>gorithms.

[C++11]:            http://en.wikipedia.org/wiki/C%2B%2B11
[type traits]:      http://en.cppreference.com/w/cpp/header/type_traits
[Boost.MPL]:        http://www.boost.org/doc/libs/1_58_0/libs/mpl/doc/
