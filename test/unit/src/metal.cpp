// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::not_<metal::not_<NUMBER(N)>>), (BOOL(!!N))); \
    CHECK((metal::not_<metal::and_<NUMBER(M), NUMBER(N)>>), (metal::or_<metal::not_<NUMBER(M)>, metal::not_<NUMBER(N)>>)); \
    CHECK((metal::not_<metal::or_<NUMBER(M), NUMBER(N)>>), (metal::and_<metal::not_<NUMBER(M)>, metal::not_<NUMBER(N)>>)); \
    CHECK((metal::neg<metal::neg<NUMBER(N)>>), (NUMBER(N))); \
    CHECK((metal::inc<metal::dec<NUMBER(N)>>), (NUMBER(N))); \
    CHECK((metal::dec<metal::inc<NUMBER(N)>>), (NUMBER(N))); \
    CHECK((metal::same<metal::add<NUMBER(0) COMMA(N) ENUM(N, NUMBER FIX(M))>, metal::mul<NUMBER(M), NUMBER(N)>>), (TRUE)); \
    CHECK((metal::same<metal::mul<NUMBER(1) COMMA(N) ENUM(N, NUMBER FIX(M))>, metal::pow<NUMBER(M), NUMBER(N)>>), (TRUE)); \
    CHECK((metal::same<metal::add<NUMBERS(INC(N))>, metal::div<metal::mul<NUMBER(N), metal::inc<NUMBER(N)>>, NUMBER(2)>>), (TRUE)); \
    CHECK((metal::same<metal::sub<NUMBER(M), metal::mul<metal::div<NUMBER(M), NUMBER(INC(N))>, NUMBER(INC(N))>>, metal::mod<NUMBER(M), NUMBER(INC(N))>>), (TRUE)); \
    CHECK((metal::same<metal::mod<metal::pow<NUMBER(INC(M)), NUMBER(INC(N))>, NUMBER(INC(M))>, NUMBER(0)>), (TRUE)); \
    CHECK((metal::same<NUMBER(M), NUMBER(N)>), (metal::not_<metal::or_<metal::less<NUMBER(M), NUMBER(N)>, metal::greater<NUMBER(M), NUMBER(N)>>>)); \
    CHECK((metal::less<NUMBER(M), NUMBER(N)>), (metal::greater<NUMBER(N), NUMBER(M)>)); \
    CHECK((metal::if_<NUMBER(M), BOOL(!!N), FALSE>), (metal::and_<NUMBER(M), NUMBER(N)>)); \
    CHECK((metal::if_<NUMBER(M), TRUE, BOOL(!!N)>), (metal::or_<NUMBER(M), NUMBER(N)>)); \
    CHECK((metal::at<LIST(INF), metal::find<LIST(INF), VALUE(M)>>), (VALUE(M))); \
    CHECK((metal::insert<LIST(M), NUMBER(M), VALUE(N)>), (metal::append<LIST(M), VALUE(N)>)); \
    CHECK((metal::insert<LIST(M), NUMBER(0), VALUE(N)>), (metal::prepend<LIST(M), VALUE(N)>)); \
    CHECK((metal::erase<LIST(INF), NUMBER(M), NUMBER(INF)>), (metal::take<LIST(INF), NUMBER(M)>)); \
    CHECK((metal::erase<LIST(INF), NUMBER(0), NUMBER(M)>), (metal::drop<LIST(INF), NUMBER(M)>)); \
    CHECK((metal::slice<LIST(M), NUMBER(0), metal::size<LIST(M)>>), (LIST(M))); \
    CHECK((metal::take<LIST(INF), NUMBER(M)>), (metal::reverse<metal::drop<metal::reverse<LIST(INF)>, NUMBER(CMPL(M))>>)); \
    CHECK((metal::rotate<LIST(INF), NUMBER(M)>), (metal::join<metal::drop<LIST(INF), NUMBER(M)>, metal::take<LIST(INF), NUMBER(M)>>)); \
    CHECK((metal::sort<metal::list<NUMBERS(M)>, metal::lambda<metal::greater>>), (metal::reverse<metal::list<NUMBERS(M)>>)); \
    CHECK((metal::same<metal::iota<NUMBER(M), NUMBER(N), NUMBER(0)>>), (TRUE)); \
    CHECK((metal::flatten<metal::transpose<metal::list<LIST(M)>>>), (LIST(M))); \
    CHECK((metal::accumulate<LIST(M), metal::list<>, metal::lambda<metal::prepend>>), (metal::accumulate<metal::reverse<LIST(M)>, metal::list<>, metal::lambda<metal::append>>)); \
    CHECK((metal::range<LIST(M), metal::size<LIST(M)>, NUMBER(0)>), (metal::reverse<LIST(M)>)); \
    CHECK((metal::transform<metal::bind<metal::lambda<metal::at>, metal::quote<LIST(M)>, metal::_1>, metal::indices<LIST(M)>>), (LIST(M))); \
    CHECK((metal::transpose<metal::transpose<MAP(INC(M))>>), (MAP(INC(M)))); \
    CHECK((metal::transform<metal::bind<metal::lambda<metal::first>, metal::_1>, MAP(M)>), (metal::keys<MAP(M)>)); \
    CHECK((metal::transform<metal::bind<metal::lambda<metal::second>, metal::_1>, MAP(M)>), (metal::values<MAP(M)>)); \
    CHECK((metal::first<metal::transpose<MAP(INC(M))>>), (metal::keys<MAP(INC(M))>)); \
    CHECK((metal::second<metal::transpose<MAP(INC(M))>>), (metal::values<MAP(INC(M))>)); \
    CHECK((metal::at<MAP(INF), metal::order<MAP(INF), NUMBER(N)>>), (PAIR(N))); \
    CHECK((metal::has_key<metal::erase_key<MAP(INF), NUMBER(M)>, NUMBER(N)>), (BOOL(M != N))); \
    CHECK((metal::insert_key<MAP(M), NUMBER(M), VALUE(N)>), (metal::append<MAP(M), metal::pair<NUMBER(M), VALUE(N)>>)); \
/**/

GEN(MATRIX)
