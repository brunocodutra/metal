// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/core/inherit.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((std::is_base_of<_num(M), metal::inherit<_nums(N)>>::type), (_bool(M < N))); \
    _assert((std::is_base_of<_num(M), metal::inherit<_nums(N) _comma(N) _nums(N)>>::type), (_bool(M < N))); \
/**/

_gen(_boilerplate)
