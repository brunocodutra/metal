# Portability {#portability}

Great effort is undertaken to keep Metal strictly conformant to the C++11
standard, so as to ensure that any piece of code making use of Metal may be
compiled on the widest possible variety of compilers.
Moreover, to minimize the odds that compiler peculiarities get in the way,
three of the most popular freely available C++ compilers are
officially and actively supported through [Continuous Integration (CI)][ci]
premisses. GCC and Clang are tested with help of
[Travis CI][travis.metal], while Microsoft
Visual Studio is tested using
[Appveyor CI][appveyor.metal].
The table bellow presents supported compilers, their minimum
required versions and current compilation
status of the main development branches.

<table>
    <tr>
        <th align="left" rowspan="2">Compiler</th>
        <th align="center" rowspan="2">Minimum Version</th>
        <th align="center" colspan="2">Branch</th>
    </tr>
    <tr>
        <th align="center">Master</th>
        <th align="center">Develop</th>
    </tr>
    <tr>
        <td align="left">GCC</td>
        <td align="center">4.8</td>
        <td align="center" rowspan="2">![travis.master.badge]</td>
        <td align="center" rowspan="2">![travis.develop.badge]</td>
    </tr>
    <tr>
        <td align="left">Clang</td>
        <td align="center">3.5</td>
    </tr>
    <tr>
        <td align="left">MSVC</td>
        <td align="center">14 (2015)</td>
        <td align="center">![appveyor.master.badge]</td>
        <td align="center">![appveyor.develop.badge]</td>
    </tr>
</table>

[ci]:                       https://en.wikipedia.org/wiki/Continuous_integration

[travis.metal]:             https://travis-ci.org/brunocodutra/metal
[travis.master.badge]:      https://travis-ci.org/brunocodutra/metal.svg?branch=master
[travis.develop.badge]:     https://travis-ci.org/brunocodutra/metal.svg?branch=develop

[appveyor.metal]:           https://ci.appveyor.com/project/brunocodutra/metal
[appveyor.master.badge]:    https://ci.appveyor.com/api/projects/status/85pk8n05n4r5x103/branch/master?svg=true
[appveyor.develop.badge]:   https://ci.appveyor.com/api/projects/status/85pk8n05n4r5x103/branch/develop?svg=true
