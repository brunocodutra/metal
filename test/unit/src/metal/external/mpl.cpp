// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>
#include <metal/external/mpl.hpp>

#include "test.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/vector.hpp>

#define MPL_NUMBER(N) boost::mpl::int_<N>
#define MPL_PAIR(N) boost::mpl::pair<MPL_NUMBER(N), VALUE(N)>
#define MPL_LIST(N) boost::mpl::list<VALUES(N)>
#define MPL_VECTOR(N) boost::mpl::vector<VALUES(N)>
#define MPL_SET(N) boost::mpl::set<RENUM(N, VALUE)>
#define MPL_MAP(N) boost::mpl::map<ENUM(N, MPL_PAIR)>

struct mfc0 { struct apply { using type = MPL_NUMBER(0); }; };
struct mfc1 { template<SCAN(ENUM(1, typename NIL))> struct apply { using type = MPL_NUMBER(1); }; };
struct mfc2 { template<SCAN(ENUM(2, typename NIL))> struct apply { using type = MPL_NUMBER(2); }; };
struct mfc3 { template<SCAN(ENUM(3, typename NIL))> struct apply { using type = MPL_NUMBER(3); }; };
struct mfc4 { template<SCAN(ENUM(4, typename NIL))> struct apply { using type = MPL_NUMBER(4); }; };
struct mfc5 { template<SCAN(ENUM(5, typename NIL))> struct apply { using type = MPL_NUMBER(5); }; };
struct mfc6 { template<SCAN(ENUM(6, typename NIL))> struct apply { using type = MPL_NUMBER(6); }; };
struct mfc7 { template<SCAN(ENUM(7, typename NIL))> struct apply { using type = MPL_NUMBER(7); }; };
struct mfc8 { template<SCAN(ENUM(8, typename NIL))> struct apply { using type = MPL_NUMBER(8); }; };
struct mfc9 { template<SCAN(ENUM(9, typename NIL))> struct apply { using type = MPL_NUMBER(9); }; };

#define MPL_LAMBDA(N) CAT(mfc, N)

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, VALUE(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, LAMBDA(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, LAMBDA(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, MPL_NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, MPL_LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, MPL_VECTOR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, MPL_SET(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, MPL_MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::from_mpl>, MPL_LAMBDA(M)>), (TRUE)); \
    CHECK((metal::from_mpl<MPL_NUMBER(M)>), (NUMBER(M))); \
    CHECK((metal::from_mpl<MPL_LIST(M)>), (LIST(M))); \
    CHECK((metal::from_mpl<MPL_VECTOR(M)>), (LIST(M))); \
    CHECK((metal::from_mpl<MPL_SET(M)>), (LIST(M))); \
    CHECK((metal::from_mpl<MPL_MAP(M)>), (MAP(M))); \
    CHECK((metal::invoke<metal::from_mpl<MPL_LAMBDA(M)> COMMA(M) VALUES(M)>), (NUMBER(M))); \
/**/

GEN(MATRIX)
