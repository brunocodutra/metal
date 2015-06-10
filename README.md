# Metal

# {#Disclaimers}
________________________________________________________________________________

This is **not** an official Boost library.

# {#Introduction}
________________________________________________________________________________

Metal is a fine selection of small, closely related template metaprogramming 
C++ libraries. Header-only, Metal is lightweight and easy to deploy.

Designed to make type metaprogramming feel easy, Metal focus on simplicity, 
extending existing tools for metaprogramming rather than reinventing the wheel. 
To this end, Metal is built upon well established concepts and is developed to 
integrate seamlessly with standard [type traits]. 

Metal is meant to be modern, user friendly, easy to maintain. As 
such, dependencies are kept to a minimum, modern [C++11] features are explored 
to their full potential, without, however, allowing its 
[portability](#Portability) to be compromised. The three most popular freely 
available compilers, Clang, GCC and Microsoft Visual Studio, are actively 
supported through continuous integration.

Metal owes its design largely to [Boost.MPL] and all due credit is given to the 
authors for their groundbreaking work on C++ template metaprogramming. In fact, 
Metal was born *MPL2*, an independent attempt to *modernize* Boost.MPL, but 
soon it became clear that Metal was slightly more than just a remake, moreover, 
it was not right to use Boost.MPL's respected name without explicit consent 
given by its authors, so thus became **Metal** - <b>Meta</b>programming 
<b>Al</b>gorithms.

# {#Motivation}
________________________________________________________________________________

...


# {#Portability}
________________________________________________________________________________

...

| Branch  | Travis                  | Appveyor                  |
| ------- |:-----------------------:|:-------------------------:|
| Master  | ![travis.master.badge]  | ![appveyor.master.badge]  |
| Develop | ![travis.develop.badge] | ![appveyor.develop.badge] |


# {#License}
________________________________________________________________________________

Metal is distributed under the [Boost Software License, Version 
1.0][boost.license].

[TOC]

[C++11]:                    http://en.wikipedia.org/wiki/C%2B%2B11
[type traits]:              http://en.cppreference.com/w/cpp/header/type_traits


[Travis]:                   https://travis-ci.org/brunocodutra/metal
[travis.master.badge]:      https://travis-ci.org/brunocodutra/metal.svg?branch=master
[travis.develop.badge]:     https://travis-ci.org/brunocodutra/metal.svg?branch=develop

[Appveyor]:                 https://ci.appveyor.com/project/brunocodutra/metal
[appveyor.master.badge]:    https://ci.appveyor.com/api/projects/status/vvu3y6afl74tlbyi/branch/master?svg=true
[appveyor.develop.badge]:   https://ci.appveyor.com/api/projects/status/vvu3y6afl74tlbyi/branch/develop?svg=true

[boost.license]:            http://boost.org/LICENSE_1_0.txt
[boost.mpl]:                http://www.boost.org/doc/libs/1_58_0/libs/mpl/doc/