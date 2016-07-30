// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::not_<metal::not_<NUM(N)>>), (BOOL(N))); \
    ASSERT((metal::not_<metal::and_<NUM(M), NUM(N)>>), (metal::or_<metal::not_<NUM(M)>, metal::not_<NUM(N)>>)); \
    ASSERT((metal::not_<metal::or_<NUM(M), NUM(N)>>), (metal::and_<metal::not_<NUM(M)>, metal::not_<NUM(N)>>)); \
    ASSERT((metal::neg<metal::neg<NUM(N)>>), (NUM(N))); \
    ASSERT((metal::inc<metal::dec<NUM(N)>>), (NUM(N))); \
    ASSERT((metal::dec<metal::inc<NUM(N)>>), (NUM(N))); \
    ASSERT((metal::equal<metal::add<NUM(0) COMMA(N) ENUM(N, NUM FIX(M))>, metal::mul<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::equal<metal::mul<NUM(1) COMMA(N) ENUM(N, NUM FIX(M))>, metal::pow<NUM(M), NUM(N)>>), (TRUE)); \
    ASSERT((metal::equal<metal::add<NUMS(INC(N))>, metal::div<metal::mul<NUM(N), metal::inc<NUM(N)>>, NUM(2)>>), (TRUE)); \
    ASSERT((metal::equal<metal::sub<NUM(M), metal::mul<metal::div<NUM(M), NUM(INC(N))>, NUM(INC(N))>>, metal::mod<NUM(M), NUM(INC(N))>>), (TRUE)); \
    ASSERT((metal::equal<metal::mod<metal::pow<NUM(INC(M)), NUM(INC(N))>, NUM(INC(M))>, NUM(0)>), (TRUE)); \
    ASSERT((metal::equal<NUM(M), NUM(N)>), (metal::not_<metal::or_<metal::less<NUM(M), NUM(N)>, metal::greater<NUM(M), NUM(N)>>>)); \
    ASSERT((metal::less<NUM(M), NUM(N)>), (metal::greater<NUM(N), NUM(M)>)); \
    ASSERT((metal::if_<NUM(M), BOOL(N), FALSE>), (metal::and_<NUM(M), NUM(N)>)); \
    ASSERT((metal::if_<NUM(M), TRUE, BOOL(N)>), (metal::or_<NUM(M), NUM(N)>)); \
    ASSERT((metal::flatten<metal::transpose<metal::list<LIST(M)>>>), (LIST(M))); \
    ASSERT((metal::flatten<metal::fold<LIST(M), metal::list<>, metal::lambda<metal::list>>>), (metal::list<VALS(M)>)); \
    ASSERT((metal::at<LIST(INF), metal::find<LIST(INF), VAL(M)>>), (VAL(M))); \
    ASSERT((metal::fold<LIST(M), metal::list<>, metal::lambda<metal::push_front>, NUM(M), NUM(0)>), (metal::fold<LIST(M), metal::list<>, metal::lambda<metal::push_back>, NUM(0), NUM(M)>)); \
    ASSERT((metal::insert<LIST(M), NUM(M), VAL(N)>), (metal::push_back<LIST(M), VAL(N)>)); \
    ASSERT((metal::insert<LIST(M), NUM(0), VAL(N)>), (metal::push_front<LIST(M), VAL(N)>)); \
    ASSERT((metal::erase<LIST(INC(M)), NUM(M)>), (metal::pop_back<LIST(INC(M))>)); \
    ASSERT((metal::erase<LIST(INC(M)), NUM(0)>), (metal::pop_front<LIST(INC(M))>)); \
    ASSERT((metal::same<metal::enumerate<NUM(M), NUM(N), NUM(0)>>), (TRUE)); \
    ASSERT((metal::slice<LIST(M), NUM(0), metal::size<LIST(M)>>), (LIST(M))); \
    ASSERT((metal::sort<metal::list<NUMS(M)>, metal::lambda<metal::greater>>), (metal::reverse<metal::list<NUMS(M)>>)); \
    ASSERT((metal::transform<metal::bind<metal::lambda<metal::at>, metal::quote<LIST(M)>, metal::_1>, metal::list<NUMS(M)>>), (LIST(M))); \
    ASSERT((metal::transpose<metal::transpose<MAP(INC(M))>>), (MAP(INC(M)))); \
    ASSERT((metal::transform<metal::bind<metal::lambda<metal::first>, metal::_1>, MAP(M)>), (metal::keys<MAP(M)>)); \
    ASSERT((metal::transform<metal::bind<metal::lambda<metal::second>, metal::_1>, MAP(M)>), (metal::values<MAP(M)>)); \
    ASSERT((metal::first<metal::transpose<MAP(INC(M))>>), (metal::keys<MAP(INC(M))>)); \
    ASSERT((metal::second<metal::transpose<MAP(INC(M))>>), (metal::values<MAP(INC(M))>)); \
    ASSERT((metal::at<MAP(INF), metal::order<MAP(INF), NUM(N)>>), (PAIR(N))); \
    ASSERT((metal::has_key<metal::erase_key<metal::list<PAIRS(INF)>, NUM(M)>, NUM(M)>), (FALSE)); \
/**/

GEN(MATRIX)
