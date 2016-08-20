// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::not_<metal::not_<NUM(N)>>), (BOOL(!!N))); \
    CHECK((metal::not_<metal::and_<NUM(M), NUM(N)>>), (metal::or_<metal::not_<NUM(M)>, metal::not_<NUM(N)>>)); \
    CHECK((metal::not_<metal::or_<NUM(M), NUM(N)>>), (metal::and_<metal::not_<NUM(M)>, metal::not_<NUM(N)>>)); \
    CHECK((metal::neg<metal::neg<NUM(N)>>), (NUM(N))); \
    CHECK((metal::inc<metal::dec<NUM(N)>>), (NUM(N))); \
    CHECK((metal::dec<metal::inc<NUM(N)>>), (NUM(N))); \
    CHECK((metal::same<metal::add<NUM(0) COMMA(N) ENUM(N, NUM FIX(M))>, metal::mul<NUM(M), NUM(N)>>), (TRUE)); \
    CHECK((metal::same<metal::mul<NUM(1) COMMA(N) ENUM(N, NUM FIX(M))>, metal::pow<NUM(M), NUM(N)>>), (TRUE)); \
    CHECK((metal::same<metal::add<NUMS(INC(N))>, metal::div<metal::mul<NUM(N), metal::inc<NUM(N)>>, NUM(2)>>), (TRUE)); \
    CHECK((metal::same<metal::sub<NUM(M), metal::mul<metal::div<NUM(M), NUM(INC(N))>, NUM(INC(N))>>, metal::mod<NUM(M), NUM(INC(N))>>), (TRUE)); \
    CHECK((metal::same<metal::mod<metal::pow<NUM(INC(M)), NUM(INC(N))>, NUM(INC(M))>, NUM(0)>), (TRUE)); \
    CHECK((metal::same<NUM(M), NUM(N)>), (metal::not_<metal::or_<metal::less<NUM(M), NUM(N)>, metal::greater<NUM(M), NUM(N)>>>)); \
    CHECK((metal::less<NUM(M), NUM(N)>), (metal::greater<NUM(N), NUM(M)>)); \
    CHECK((metal::if_<NUM(M), BOOL(!!N), FALSE>), (metal::and_<NUM(M), NUM(N)>)); \
    CHECK((metal::if_<NUM(M), TRUE, BOOL(!!N)>), (metal::or_<NUM(M), NUM(N)>)); \
    CHECK((metal::flatten<metal::transpose<metal::list<LIST(M)>>>), (LIST(M))); \
    CHECK((metal::flatten<metal::fold_left<LIST(M), metal::list<>, metal::lambda<metal::list>>>), (metal::list<VALS(M)>)); \
    CHECK((metal::at<LIST(INF), metal::find<LIST(INF), VAL(M)>>), (VAL(M))); \
    CHECK((metal::fold_left<LIST(M), metal::list<>, metal::lambda<metal::push_front>>), (metal::fold_right<LIST(M), metal::list<>, metal::lambda<metal::push_back>>)); \
    CHECK((metal::insert<LIST(M), NUM(M), VAL(N)>), (metal::push_back<LIST(M), VAL(N)>)); \
    CHECK((metal::insert<LIST(M), NUM(0), VAL(N)>), (metal::push_front<LIST(M), VAL(N)>)); \
    CHECK((metal::erase<LIST(INF), NUM(M), NUM(INF)>), (metal::take<LIST(INF), NUM(M)>)); \
    CHECK((metal::erase<LIST(INF), NUM(0), NUM(M)>), (metal::drop<LIST(INF), NUM(M)>)); \
    CHECK((metal::same<metal::enumerate<NUM(M), NUM(N), NUM(0)>>), (TRUE)); \
    CHECK((metal::slice<LIST(M), NUM(0), metal::size<LIST(M)>>), (LIST(M))); \
    CHECK((metal::range<metal::list<NUMS(M)>, NUM(M), NUM(0)>), (metal::reverse<metal::list<NUMS(M)>>)); \
    CHECK((metal::sort<metal::list<NUMS(M)>, metal::lambda<metal::greater>>), (metal::reverse<metal::list<NUMS(M)>>)); \
    CHECK((metal::transform<metal::bind<metal::lambda<metal::at>, metal::quote<LIST(M)>, metal::_1>, metal::list<NUMS(M)>>), (LIST(M))); \
    CHECK((metal::transpose<metal::transpose<MAP(INC(M))>>), (MAP(INC(M)))); \
    CHECK((metal::transform<metal::bind<metal::lambda<metal::first>, metal::_1>, MAP(M)>), (metal::keys<MAP(M)>)); \
    CHECK((metal::transform<metal::bind<metal::lambda<metal::second>, metal::_1>, MAP(M)>), (metal::values<MAP(M)>)); \
    CHECK((metal::first<metal::transpose<MAP(INC(M))>>), (metal::keys<MAP(INC(M))>)); \
    CHECK((metal::second<metal::transpose<MAP(INC(M))>>), (metal::values<MAP(INC(M))>)); \
    CHECK((metal::at<MAP(INF), metal::order<MAP(INF), NUM(N)>>), (PAIR(N))); \
    CHECK((metal::has_key<metal::erase_key<metal::list<PAIRS(INF)>, NUM(M)>, NUM(M)>), (FALSE)); \
/**/

GEN(MATRIX)
