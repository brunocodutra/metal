// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::flatten<metal::transpose<metal::list<LIST(M)>>>), (LIST(M))); \
    ASSERT((metal::flatten<metal::fold<LIST(M), metal::list<>, metal::lambda<metal::list>>>), (metal::list<VALS(M)>)); \
    ASSERT((metal::flatten<metal::reduce<VECT(M), metal::lambda<metal::list>>>), (metal::list<VALS(M) COMMA(AND(M, CMPL(M))) NAS(CMPL(M))>)); \
    ASSERT((metal::at<LIST(INF), metal::find<LIST(INF), VAL(M)>>), (VAL(M))); \
    ASSERT((metal::fold<LIST(M), metal::list<>, metal::lambda<metal::push_front>, NUM(M), NUM(0)>), (metal::fold<LIST(M), metal::list<>, metal::lambda<metal::push_back>, NUM(0), NUM(M)>)); \
    ASSERT((metal::insert<LIST(M), NUM(M), VAL(N)>), (metal::push_back<LIST(M), VAL(N)>)); \
    ASSERT((metal::insert<LIST(M), NUM(0), VAL(N)>), (metal::push_front<LIST(M), VAL(N)>)); \
    ASSERT((metal::erase<VECT(INC(M)), NUM(M)>), (metal::pop_back<VECT(INC(M)), NUM(CMPL(M))>)); \
    ASSERT((metal::erase<VECT(INC(M)), NUM(0)>), (metal::pop_front<VECT(INC(M))>)); \
    ASSERT((metal::same<metal::enumerate<NUM(M), NUM(N), NUM(0)>>), (TRUE)); \
    ASSERT((metal::slice<LIST(M), NUM(0), metal::size<LIST(M)>>), (LIST(M))); \
    ASSERT((metal::sort<test::list<NUMS(M)>, metal::lambda<metal::greater>>), (metal::reverse<test::list<NUMS(M)>>)); \
    ASSERT((metal::transform<metal::bind<metal::lambda<metal::at>, metal::quote<LIST(M)>, metal::_1>, test::list<NUMS(M)>>), (LIST(M))); \
    ASSERT((metal::transpose<metal::transpose<MAP(INC(M))>>), (MAP(INC(M)))); \
    ASSERT((metal::transform<metal::bind<metal::lambda<metal::first>, metal::_1>, MAP(M)>), (metal::keys<MAP(M)>)); \
    ASSERT((metal::transform<metal::bind<metal::lambda<metal::second>, metal::_1>, MAP(M)>), (metal::values<MAP(M)>)); \
    ASSERT((metal::first<metal::transpose<MAP(INC(M))>>), (metal::keys<MAP(INC(M))>)); \
    ASSERT((metal::second<metal::transpose<MAP(INC(M))>>), (metal::values<MAP(INC(M))>)); \
    ASSERT((metal::at<MAP(INF), metal::order<MAP(INF), NUM(N)>>), (PAIR(N))); \
    ASSERT((metal::has_key<metal::erase_key<metal::list<PAIRS(INF)>, NUM(M)>, NUM(M)>), (FALSE)); \
/**/

GEN(MATRIX)
