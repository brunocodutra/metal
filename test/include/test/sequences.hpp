// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_SEQUENCES_HPP
#define METAL_TEST_SEQUENCES_HPP

#include "test/values.hpp"
#include "test/numbers.hpp"
#include "test/preprocessor.hpp"

namespace test
{
    template<typename...> union list;
    template<typename, typename> union pair;
    template<SCAN(ENUM(INF, typename = NA)), typename...> union vect;

    template<typename...> class _map0;

    template<typename... _>
    using map0 =
        typename std::enable_if<length<_...>::value == 0, _map0<_...>>::type;

    template<SCAN(ENUM( 1, typename NIL))> class map1;
    template<SCAN(ENUM( 2, typename NIL))> class map2;
    template<SCAN(ENUM( 3, typename NIL))> class map3;
    template<SCAN(ENUM( 4, typename NIL))> class map4;
    template<SCAN(ENUM( 5, typename NIL))> class map5;
    template<SCAN(ENUM( 6, typename NIL))> class map6;
    template<SCAN(ENUM( 7, typename NIL))> class map7;
    template<SCAN(ENUM( 8, typename NIL))> class map8;
}

#define PAIR(N) test::pair<NUM(N), VAL(N)>
#define PAIRS(N) ENUM(N, PAIR)

#define VECT(N) test::vect<VALS(N)>
#define VECTS(N) ENUM(N, VECT)

#define LIST(N) test::list<VALS(N)>
#define LISTS(N) ENUM(N, LIST)

#define MAP(N) CAT(test::map, N)<PAIRS(N)>
#define MAPS(N) ENUM(N, MAP)

#endif

