// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_PREPROCESSOR_HPP
#define METAL_TEST_PREPROCESSOR_HPP

#if !defined(INF)
#   define INF 8
#endif

#define CAT_IMPL(X, Y) X##Y
#define CAT(X, Y) CAT_IMPL(X, Y)

#define ID(...) __VA_ARGS__
#define NIL(...)

#define EXPAND(...) __VA_ARGS__
#define DEFER(MACRO) MACRO NIL NIL()()

#define FIRST_IMPL(X, ...) X
#define FIRST(...) EXPAND(FIRST_IMPL(__VA_ARGS__))

#define SECOND_IMPL(_, X, ...) X
#define SECOND(...) EXPAND(SECOND_IMPL(__VA_ARGS__))

#define REST(_, ...) __VA_ARGS__

#define LENGTH_IMPL(_0, _1, _2, _3, _4, _5, _6, _7, N, ...) N
#define LENGTH(...) EXPAND(LENGTH_IMPL(__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#define INC_0 1
#define INC_1 2
#define INC_2 3
#define INC_3 4
#define INC_4 5
#define INC_5 6
#define INC_6 7
#define INC_7 8
#define INC_IMPL(N) INC_##N
#define INC_(N) (INC_IMPL(N))
#define INC(N) INC_IMPL(N)

#define DEC_1 0
#define DEC_2 1
#define DEC_3 2
#define DEC_4 3
#define DEC_5 4
#define DEC_6 5
#define DEC_7 6
#define DEC_8 7
#define DEC_IMPL(N) DEC_##N
#define DEC_(N) (DEC_IMPL(N))
#define DEC(N) DEC_IMPL(N)

#define CMPL_0 INF
#define CMPL_1 DEC(CMPL_0)
#define CMPL_2 DEC(CMPL_1)
#define CMPL_3 DEC(CMPL_2)
#define CMPL_4 DEC(CMPL_3)
#define CMPL_5 DEC(CMPL_4)
#define CMPL_6 DEC(CMPL_5)
#define CMPL_7 DEC(CMPL_6)
#define CMPL_8 DEC(CMPL_7)
#define CMPL_IMPL(N) CMPL_##N
#define CMPL(N) CMPL_IMPL(N)

#define NOT_0  _, 1
#define NOT(N) SECOND(CAT(NOT_, N), 0, _)

#define IF_0(T, F) T
#define IF_1(T, F) F
#define IF(N) CAT(IF_, NOT(N))

#define AND(M, N) IF(M)(N, 0)
#define OR(M, N) IF(M)(1, N)

#define COMMA(N) IF(N)(ID, NIL)(,)

#define FIX_0(...) (0)
#define FIX_1(...) (1)
#define FIX_2(...) (2)
#define FIX_3(...) (3)
#define FIX_4(...) (4)
#define FIX_5(...) (5)
#define FIX_6(...) (6)
#define FIX_7(...) (7)
#define FIX_8(...) (8)
#define FIX_IMPL(N) FIX_##N
#define FIX(N) FIX_IMPL(N)

#define LIFT(MACRO) MACRO##_

#define CALL_0(N, MACRO, ...) DEFER(MACRO)(N, __VA_ARGS__)
#define CALL_1(N, MACRO) DEFER(MACRO)(N)

#define ENUM_ID(...) __VA_ARGS__
#define ENUM_KWD() ENUM_IMPL
#define ENUM_IMPL(N, ...) \
    IF(N)(ENUM_ID, NIL)( \
        DEFER(ENUM_KWD)()(DEC(N), __VA_ARGS__) COMMA(DEC(N)) \
        CAT(CALL_, NOT(DEC(LENGTH(__VA_ARGS__))))(DEC(N), __VA_ARGS__) \
    ) \
/**/

#define ENUM(N, ...) ENUM_IMPL(N, __VA_ARGS__)

#define RENUM_ID(...) __VA_ARGS__
#define RENUM_KWD() RENUM_IMPL
#define RENUM_IMPL(N, ...) \
    IF(N)(RENUM_ID, NIL)( \
        CAT(CALL_, NOT(DEC(LENGTH(__VA_ARGS__))))(DEC(N), __VA_ARGS__) \
        COMMA(DEC(N)) DEFER(RENUM_KWD)()(DEC(N), __VA_ARGS__) \
    ) \
/**/

#define RENUM(N, ...) RENUM_IMPL(N, __VA_ARGS__)

#define FWD_ID(...) __VA_ARGS__
#define FWD_KWD() FWD_IMPL
#define FWD_IMPL(ARG, MACRO, ...) \
    MACRO(ARG) \
    IF(DEC(LENGTH(__VA_ARGS__)))(FWD_ID, NIL)( \
        , DEFER(FWD_KWD)()(ARG, __VA_ARGS__) \
    ) \
/**/

#define FWD(ARG, ...) FWD_ID(DEFER(FWD_IMPL)(ARG, __VA_ARGS__, _))

#define GEN_I0(I, M)
#define GEN_I1(I, M)  M(I, 0)
#define GEN_I2(I, M)  GEN_I1(I, M) M(I, 1)
#define GEN_I3(I, M)  GEN_I2(I, M) M(I, 2)
#define GEN_I4(I, M)  GEN_I3(I, M) M(I, 3)
#define GEN_I5(I, M)  GEN_I4(I, M) M(I, 4)
#define GEN_I6(I, M)  GEN_I5(I, M) M(I, 5)
#define GEN_I7(I, M)  GEN_I6(I, M) M(I, 6)
#define GEN_I8(I, M)  GEN_I7(I, M) M(I, 7)

#define GEN_0J(J, M)
#define GEN_1J(J, M)  CAT_IMPL(GEN_I, J)(0, M)
#define GEN_2J(J, M)  GEN_1J(J, M) CAT_IMPL(GEN_I, J)(1, M)
#define GEN_3J(J, M)  GEN_2J(J, M) CAT_IMPL(GEN_I, J)(2, M)
#define GEN_4J(J, M)  GEN_3J(J, M) CAT_IMPL(GEN_I, J)(3, M)
#define GEN_5J(J, M)  GEN_4J(J, M) CAT_IMPL(GEN_I, J)(4, M)
#define GEN_6J(J, M)  GEN_5J(J, M) CAT_IMPL(GEN_I, J)(5, M)
#define GEN_7J(J, M)  GEN_6J(J, M) CAT_IMPL(GEN_I, J)(6, M)
#define GEN_8J(J, M)  GEN_7J(J, M) CAT_IMPL(GEN_I, J)(7, M)

#define GEN(M) CAT(CAT(GEN_, INF), J)(INF, M)

#if defined(_MSC_VER)
#   define X_4(...) __VA_ARGS__
#   define X_3(...) X_4(__VA_ARGS__)
#   define X_2(...) X_3(__VA_ARGS__)
#   define X_1(...) X_2(__VA_ARGS__)
#   define X(...) X_1(__VA_ARGS__)
#else
#   define X_1(...) __VA_ARGS__
#   define X(...) X_1(__VA_ARGS__)
#endif

#define SCAN(...) X(X(X(X(X(X(X(X(X(X(__VA_ARGS__))))))))))

#define ASSERT_IMPL(X, Y) \
    static_assert(std::is_same<ID X, ID Y>::value, #X " == " #Y) \
/**/

#define ASSERT(X, Y) EXPAND(ASSERT_IMPL SCAN((X, Y)))

#endif
