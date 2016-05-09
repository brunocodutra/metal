// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_PREPROCESSOR_HPP
#define METAL_TEST_PREPROCESSOR_HPP

#ifndef LIMIT
    #define LIMIT 10
#endif

#define NIL(...)
#define ID(...) __VA_ARGS__

#define CAT_(X, Y) X##Y
#define CAT(X, Y) CAT_(X, Y)

#define SIZEOF_(_0, _1, _2, _3, _4, _5, _6, _7, _8, SIZE, ...) SIZE
#define SIZEOF(...) ID(ID(SIZEOF_(__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)))

#define INC_0 1
#define INC_1 2
#define INC_2 3
#define INC_3 4
#define INC_4 5
#define INC_5 6
#define INC_6 7
#define INC_7 8
#define INC_8 9
#define INC_9 10
#define INC_(N) INC_##N
#define INC(N) INC_(N)

#define DEC_1  0
#define DEC_2  1
#define DEC_3  2
#define DEC_4  3
#define DEC_5  4
#define DEC_6  5
#define DEC_7  6
#define DEC_8  7
#define DEC_9  8
#define DEC_10 9
#define DEC_(N) DEC_##N
#define DEC(N) DEC_(N)

#define CMPL_0  LIMIT
#define CMPL_1  DEC(CMPL_0)
#define CMPL_2  DEC(CMPL_1)
#define CMPL_3  DEC(CMPL_2)
#define CMPL_4  DEC(CMPL_3)
#define CMPL_5  DEC(CMPL_4)
#define CMPL_6  DEC(CMPL_5)
#define CMPL_7  DEC(CMPL_6)
#define CMPL_8  DEC(CMPL_7)
#define CMPL_9  DEC(CMPL_8)
#define CMPL_10 DEC(CMPL_9)
#define CMPL_(N) CMPL_##N
#define CMPL(N) CMPL_(N)

#define NOT_0  1
#define NOT_1  0
#define NOT_2  0
#define NOT_3  0
#define NOT_4  0
#define NOT_5  0
#define NOT_6  0
#define NOT_7  0
#define NOT_8  0
#define NOT_9  0
#define NOT_10 0
#define NOT_(N) NOT_##N
#define NOT(N) NOT_(N)

#define IF_0(T, F) F
#define IF_1(T, F) T
#define IF(COND) CAT(IF_, NOT(NOT(COND)))

#define AND(M, N) IF(M)(N, 0)
#define OR(M, N) IF(M)(1, N)

#define COMMA_()  ,
#define COMMA(N) IF(N)(COMMA_, NIL)()

#define REPEAT_ID() REPEAT
#define REPEAT(N, MACRO, ...) \
    IF(N)(ID, NIL)( \
        REPEAT_ID NIL NIL()()()(DEC(N), MACRO, __VA_ARGS__) \
        MACRO NIL NIL()()(DEC(N), __VA_ARGS__) \
    ) \
/**/

#define HEAD(_, ...) _
#define TAIL(_, ...) __VA_ARGS__
#define RECURSE_ID() RECURSE
#define RECURSE(N, MACRO, ...) \
    IF(N)(HEAD, TAIL)( \
        RECURSE_ID NIL NIL()()()( \
            DEC(N), \
            MACRO, \
            MACRO NIL NIL()()(DEC(N), __VA_ARGS__) \
        ), \
        __VA_ARGS__ \
    ) \
/**/

#define BAR_0
#define BAR_1
#define BAR_2
#define BAR_3
#define BAR_4
#define BAR_5
#define BAR_6
#define BAR_7
#define BAR_8
#define BAR_9
#define BAR BAR_

#define ADAPT_0  (0)
#define ADAPT_1  (1)
#define ADAPT_2  (2)
#define ADAPT_3  (3)
#define ADAPT_4  (4)
#define ADAPT_5  (5)
#define ADAPT_6  (6)
#define ADAPT_7  (7)
#define ADAPT_8  (8)
#define ADAPT_9  (9)
#define ADAPT_10 (10)
#define ADAPT(M) M ADAPT_

#define ENUM_1(N, _0) COMMA(N) _0##N
#define ENUM_2(N, _0, _1) COMMA(N) _0##N, _1##N
#define ENUM(N, ...) REPEAT(N, CAT(ENUM_, SIZEOF(__VA_ARGS__)), __VA_ARGS__)

#if defined(_MSC_VER)
    #define X_(...) __VA_ARGS__
    #define X(_, ...) X_(__VA_ARGS__)
#else
    #define X(_, ...) _##__VA_ARGS__
#endif

#define X1(...) X( , __VA_ARGS__)
#define X10(...) X1(X1(X1(X1(X1(X1(X1(X1(X1(X1(X( , __VA_ARGS__)))))))))))

#define EVAL(M, ...) X10(X10(X( , M(__VA_ARGS__))))

#define GEN_I0(I, M)
#define GEN_I1(I, M)  EVAL(M, I, 0)
#define GEN_I2(I, M)  GEN_I1(I, M) EVAL(M, I, 1)
#define GEN_I3(I, M)  GEN_I2(I, M) EVAL(M, I, 2)
#define GEN_I4(I, M)  GEN_I3(I, M) EVAL(M, I, 3)
#define GEN_I5(I, M)  GEN_I4(I, M) EVAL(M, I, 4)
#define GEN_I6(I, M)  GEN_I5(I, M) EVAL(M, I, 5)
#define GEN_I7(I, M)  GEN_I6(I, M) EVAL(M, I, 6)
#define GEN_I8(I, M)  GEN_I7(I, M) EVAL(M, I, 7)
#define GEN_I9(I, M)  GEN_I8(I, M) EVAL(M, I, 8)
#define GEN_I10(I, M) GEN_I9(I, M) EVAL(M, I, 9)

#define GEN_0J(J, M)
#define GEN_1J(J, M)  CAT_(GEN_I, J)(0, M)
#define GEN_2J(J, M)  GEN_1J(J, M) CAT_(GEN_I, J)(1, M)
#define GEN_3J(J, M)  GEN_2J(J, M) CAT_(GEN_I, J)(2, M)
#define GEN_4J(J, M)  GEN_3J(J, M) CAT_(GEN_I, J)(3, M)
#define GEN_5J(J, M)  GEN_4J(J, M) CAT_(GEN_I, J)(4, M)
#define GEN_6J(J, M)  GEN_5J(J, M) CAT_(GEN_I, J)(5, M)
#define GEN_7J(J, M)  GEN_6J(J, M) CAT_(GEN_I, J)(6, M)
#define GEN_8J(J, M)  GEN_7J(J, M) CAT_(GEN_I, J)(7, M)
#define GEN_9J(J, M)  GEN_8J(J, M) CAT_(GEN_I, J)(8, M)
#define GEN_10J(J, M) GEN_9J(J, M) CAT_(GEN_I, J)(9, M)

#define GEN(MATRIX) CAT(CAT(GEN_, LIMIT), J)(LIMIT, MATRIX)

//#define ENTRY(N, MATRIX, M) MATRIX(M, N)
//#define GEN_(M, MATRIX, N) REPEAT(N, ENTRY, MATRIX, M)
//#define GEN(MATRIX) EVAL(REPEAT, LIMIT, GEN_, MATRIX, LIMIT)

#endif
